unsigned int randaux()
{
	static long seed = 1;
	return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}

#include <stdio.h>

void imprime(int w, int deckDomino[][4]) {
  printf(" %d%d\n %d%d\n", deckDomino[w][0], deckDomino[w][1], deckDomino[w][3],
         deckDomino[w][2]);
}

void imprimeTodos(int w, int deckDomino[][4]) {
  int m;
  for (m = 0; m < w; m++) {
    printf("%d:\n", m);
    imprime(m, deckDomino);
  }
}

void rotacao(int w, int deckDomino[][4]) {
  int aux = deckDomino[w][0];
  deckDomino[w][0] = deckDomino[w][1];
  deckDomino[w][1] = deckDomino[w][2];
  deckDomino[w][2] = deckDomino[w][3];
  deckDomino[w][3] = aux;
}

void geraDeck(int k, int w, int deckDomino[][4]) {
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
int checkIguais(int m, int z, int deckDomino[][4]) {
  return deckDomino[m][0] == deckDomino[z][0] &&
         deckDomino[m][1] == deckDomino[z][1] &&
         deckDomino[m][2] == deckDomino[z][2] &&
         deckDomino[m][3] == deckDomino[z][3];
}

void alteraDeck(int m, int w, int deckDomino[][4]) {
  int i;
  while (m < w - 1) {
    for (i = 0; i < 4; i++)
      deckDomino[m][i] = deckDomino[m + 1][i];
    m++;
  }
}

int corrigeDeckSemRotacoes(int w, int deckDomino[][4]) {
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

int verificaEcorrige1linha(int m, int w, int deckDomino[][4]) {
  int z;

  for (z = m - 1; z >= 0; z--) {
    if (checkIguais(m, z, deckDomino)) {
      alteraDeck(m, w, deckDomino);
      return 1;
    }
  }
  return 0;
}

int verificarRotacoes(int w, int deckDomino[][4]) {
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

void troca2linhas(int r, int i, int deckDomino[][4]) {
  int j, vetorAuxiliar[4];
  for (j = 0; j < 4; j++) {
    vetorAuxiliar[j] = deckDomino[r][j];
    deckDomino[r][j] = deckDomino[i][j];
    deckDomino[i][j] = vetorAuxiliar[j];
  }
}

void baralhar(int w, int w_pretendido, int deckDomino[][4]) {
  int i = 0, r;
  for (i = 0; i < w_pretendido; i++, w--) {
    r = i + randaux() % w;
    troca2linhas(r, i, deckDomino);
  }
}

void transfParaNum(int w_pretendido, int deckDomino[][4], int deckNum[]) {
  int m;

  for (m = 0; m < w_pretendido; m++) {
    deckNum[m] = deckDomino[m][0] * 1000 + deckDomino[m][1] * 100 +
                 deckDomino[m][2] * 10 + deckDomino[m][3];
  }
}

int verificaEalteraNum(int m, int w_pretendido, int deckNum[]) {
  int t = m - 1, aux;

  while (t >= 0) {
    if (deckNum[m] < deckNum[t]) {
      aux = deckNum[m];
      deckNum[m] = deckNum[t];
      deckNum[t] = aux;
      return 1;
    }
    t--;
  }

  return 0;
}

void ordena(int w_pretendido, int deckNum[]) {
  int m = w_pretendido - 1;

  while (m > 0) {
    do
      verificaEalteraNum(m, w_pretendido, deckNum);
    while (verificaEalteraNum(m, w_pretendido, deckNum));
    m--;
  }
}

void transfParaVetor(int w_pretendido, int deckDomino[][4], int deckNum[]) {
  int i;

  for (i = 0; i < w_pretendido; i++) {
    deckDomino[i][3] = deckNum[i] % 10;
    deckDomino[i][2] = (int)(deckNum[i] / 10) % 10;
    deckDomino[i][1] = (int)(((int)(deckNum[i] / 10) / 10)) % 10;
    deckDomino[i][0] = (int)(deckNum[i] / 1000);
  }
}

void imprimeMesaToda(int nJogadas, int w_pretendido, int mesa[][6]) {
  int i = 0, c;

  printf("Mesa:\n");

  for (i = 0; i < nJogadas; i++) {
    for (c = 0; c < mesa[i][5]; c++)
      printf(" ");
    printf("%d%d\n", mesa[i][0], mesa[i][1]);
    for (c = 0; c < mesa[i][5]; c++)
      printf(" ");
    printf("%d%d\n", mesa[i][3], mesa[i][2]);
  }
}

int jogar(int w_pretendido, int deckDomino[][4]) {
  int mesa[w_pretendido][6], nJogadas, ID, rot, i, maxJogadas = w_pretendido;

  /*inicializar a coluna 5 do vetor mesa a 0*/
  for (i = 0; i < w_pretendido; i++)
    mesa[i][5] = 0;

  for (nJogadas = 0; nJogadas < maxJogadas; nJogadas++) {
    imprimeTodos(w_pretendido, deckDomino);
    imprimeMesaToda(nJogadas, w_pretendido, mesa);
    printf("Jogada:\n");
    scanf("%d%d%d", &ID, &rot, &mesa[nJogadas][4]);

    if (mesa[nJogadas][4] < 0 || mesa[nJogadas][4] > 1 ||
        ID > w_pretendido - 1 || ID < 0 || rot < 0)
      return 0;

    mesa[nJogadas][5] = mesa[nJogadas][4];

    if (rot > 0) {
      for (i = 0; i < rot; i++)
        rotacao(ID, deckDomino);
    }

    for (i = 0; i < 4; i++) {
      mesa[nJogadas][i] = deckDomino[ID][i];
    }
    if (nJogadas > 0 && mesa[nJogadas][4] == 1)
      mesa[nJogadas][5] = mesa[nJogadas - 1][5] + 1;
    else if (nJogadas > 0 && mesa[nJogadas][4] == 0) {
      if (mesa[nJogadas - 1][4] == 1) {
        mesa[nJogadas][5] = mesa[nJogadas - 1][5] - 1;
      } else if (mesa[nJogadas - 1][4] == 0) {
        for (i = 0; i < nJogadas; i++)
          mesa[i][5]++;
        mesa[nJogadas][5] = mesa[nJogadas - 1][5] - 1;
      }
      while (mesa[nJogadas][5] > 0) /*para ficar sempre o mais à esquerda possível*/
        for (i = 0; i <= nJogadas; i++)
          mesa[i][5]--;
    }
    alteraDeck(ID, w_pretendido, deckDomino);
    w_pretendido--;

    if (nJogadas > 0) {
      if (mesa[nJogadas][4] == 0 && mesa[nJogadas][1] != mesa[nJogadas - 1][3])
        return 0;
      if (mesa[nJogadas][4] == 1 && mesa[nJogadas][0] != mesa[nJogadas - 1][2])
        return 0;
    }
  }

  if (w_pretendido == 0) {
    imprimeMesaToda(nJogadas, w_pretendido, mesa);
    return 1;
  }
  return 0;
}

int main() {
  int k, w_pretendido;
  scanf("%d%d",&k,&w_pretendido);
  int w = (k + 1) * (k + 1) * (k + 1) * (k + 1);
  int deckDomino[w][4];

  geraDeck(k, w, deckDomino);
  w = corrigeDeckSemRotacoes(w, deckDomino);
  w = verificarRotacoes(w, deckDomino);

  printf("\n%d pecas geradas.\n\n", w);

  if (w_pretendido < w)
    baralhar(w, w_pretendido, deckDomino);
  else {
    w_pretendido = w;
    baralhar(w, w_pretendido, deckDomino);
  }

  int deckNum[w_pretendido];

  transfParaNum(w_pretendido, deckDomino, deckNum);
  ordena(w_pretendido, deckNum);
  transfParaVetor(w_pretendido, deckDomino, deckNum);

  /*printf("\ndeck ordenado:");*/

  if (jogar(w_pretendido, deckDomino))
    printf("Puzzle terminado.\n");
  else
    printf("Erro: jogada deve ser constituida por tres numeros: <ID> "
           "<rotacoes> <posicao>.\n");

  return 0;
}