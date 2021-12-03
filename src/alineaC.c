#include <stdio.h>

void imprime(int w, int deckDomino[][4])
{
  printf("\n%d%d\n%d%d\n", deckDomino[w][0], deckDomino[w][1], deckDomino[w][3],
         deckDomino[w][2]);
}

void imprimeTodos(int w, int deckDomino[][4])
{
  int m;
  for (m = 0; m < w; m++) {
    imprime(m, deckDomino);
  }
}

void rotacao(int w, int deckDomino[][4])
{
  int aux = deckDomino[w][0];
  deckDomino[w][0] = deckDomino[w][1];
  deckDomino[w][1] = deckDomino[w][2];
  deckDomino[w][2] = deckDomino[w][3];
  deckDomino[w][3] = aux;
}

void geraDeck(int k, int w, int deckDomino[][4])
{
  int m = 0, a, b, c, d, total = 0;
  while (m < w) {
    for (a = 0; a <= k && total < w; a++) {
      for (b = 0; b <= k && total < w; b++) {
        for (c = 0; c <= k && total < w; c++) {
          for (d = 0; d <= k && total < w; d++, total++) {
            deckDomino[m][3] = d;
            deckDomino[m][2] = c;
            deckDomino[m][1] = b;
            deckDomino[m][0] = a;
            m++;
          }
        }
      }
    }
  }
}

/*funcao para verificar se dois dominos sao iguais*/
int checkIguais(int m, int z, int deckDomino[][4])
{
  return deckDomino[m][0] == deckDomino[z][0] &&
         deckDomino[m][1] == deckDomino[z][1] &&
         deckDomino[m][2] == deckDomino[z][2] &&
         deckDomino[m][3] == deckDomino[z][3];
}

void alteraDeck(int m, int w, int deckDomino[][4])
{
  int i;
  while (m < w - 1) {
    for (i = 0; i < 4; i++)
      deckDomino[m][i] = deckDomino[m + 1][i];
    m++;
  }
}

int corrigeDeckSemRotacoes(int w, int deckDomino[][4])
{
  int m, z, nIguais = 0;

  for (m = 1; m < w; m++) {
    for (z = m - 1; z >= 0; z--) {
      if (checkIguais(m, z, deckDomino)) {
        alteraDeck(m, w, deckDomino);
        nIguais++;
        z = -1;
      }
    }
  }
  return w - nIguais;
}

int verificaEcorrige1linha(int m, int w, int deckDomino[][4])
{
  int z;

  for (z = m - 1; z >= 0; z--) {
    if (checkIguais(m, z, deckDomino)) {
      alteraDeck(m, w, deckDomino);
      return 1;
    }
  }
  return 0;
}

int verificarRotacoes(int w, int deckDomino[][4])
{
  int m = 2, nRotacoes = 0;
  for (m = 1; m < w; m++) {
    while (nRotacoes < 4) {
      rotacao(m, deckDomino);
      nRotacoes++;
      if (verificaEcorrige1linha(m, w, deckDomino)) {
        w--;
        nRotacoes = 0;
      }
      if (nRotacoes == 1) {
        rotacao(m, deckDomino);
        nRotacoes++;
        if (verificaEcorrige1linha(m, w, deckDomino)) {
          w--;
          nRotacoes = 0;
        }
      }
      if (nRotacoes == 2) {
        rotacao(m, deckDomino);
        nRotacoes++;
        if (verificaEcorrige1linha(m, w, deckDomino)) {
          w--;
          nRotacoes = 0;
        }
      }
      if (nRotacoes == 3) {
        rotacao(m, deckDomino);
        nRotacoes = 0;
        break;
      }
    }
  }
  return w;
}

int main()
{
  int k, w_pretendido;
  scanf("%d%d", &k, &w_pretendido);
  int w = (k + 1) * (k + 1) * (k + 1) * (k + 1);
  int deckDomino[w][4];

  geraDeck(k, w, deckDomino);
  w = corrigeDeckSemRotacoes(w, deckDomino);
  w = verificarRotacoes(w, deckDomino);

  if (w_pretendido > w)
    imprimeTodos(w, deckDomino);
  else
    imprimeTodos(w_pretendido, deckDomino);

  printf("\n%d pecas geradas.\n", w);

  return 0;
}