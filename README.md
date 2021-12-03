# UAb_littleDominoPuzzle

[![Replit Ready to Run](https://img.shields.io/badge/Replit-Ready_to_Run-informational?logo=replit&labelColor=white)](https://replit.com/@DiogoAntao/UAblittleDominoPuzzle)

[EN] This project was made under the Curricular Unit of **Introduction to Programming** in the Computer Science and Engineering Bachelor Program of Universidade Aberta, academic year of 2018-19.

[PT] Este projeto foi realizado no âmbito da Unidade Curricular de **Introdução à Programação** da Licenciatura em Engenharia Informática da Universidade Aberta no ano letivo de 2018-19.

## Introdução

A base do projeto é o puzzle Dominó numa versão adaptada em que as peças têm 4 números em vez de 2, e são quadrados.

Exemplo de uma peça:

    -- --
    |3|0|
    -- --
    |2|2|
    -- --

Esta peça pode rodar, podendo neste caso ficar nas seguintes três posições alternativas:

(a) Rotação de 1 no sentido anti-horário da peça exemplificada:

    -- --
    |0|2|
    -- --
    |3|2|
    -- --


(b) Rotação de 2 no sentido anti-horário da peça exemplificada:

    -- --
    |2|2|
    -- --
    |0|3|
    -- --

(c) Rotação de 3 no sentido anti-horário da peça exemplificada:

    -- --
    |2|3|
    -- --
    |2|0|
    -- --

Tal como as peças de dominó clássicas, estas peças têm costas todas iguais de modo a poderem ser baralhadas, pelo que não se podem virar, apenas rodar. Como exemplo, a peça exemplificada nunca pode estar na seguinte posição:


    -- --
    |2|0|
    -- --
    |2|3|
    -- --


Os números possíveis podem ser valores entre 0 e 9. As diversas alíneas do projeto irão revelar a cada momento o puzzle proposto com este conjunto de peças.


## Alínea A

O objetivo é receber 4 valores inteiros A B C D (de 0 a 9) e mostrar a peça respeitando a seguinte ordem:

    -- --
    |A|B|
    -- --
    |D|C|
    -- --

Exemplo de entrada:

    3 0 2 2

Exemplo de saída:

    ++++
    +30+
    +22+
    ++++


## Alínea B

O objetivo é listar todas as peças com números de 0 a K, sendo K um valor inteiro entre 0 e 9 inclusive, e em todas as posições. Dado que o número de peças e posições pode ser muito elevado, deve-se parar após um valor de número de peças W, fornecido pelo utilizador. No caso de se utilizarem vetores em que seja necessário um valor máximo, deve-se utilizar o valor 4000.
Considerando as posições A B C D em baixo, pretende-se listar primeiro todas as possibilidades de D antes de C e assim sucessivamente até A.

Exemplo de entrada:

    2 6


Exemplo de saída:

    ++++
    +00+
    +00+
    ++++
    ++++
    +00+
    +10+
    ++++
    ++++
    +00+
    +20+
    ++++
    ++++
    +00+
    +01+
    ++++
    ++++
    +00+
    +11+
    ++++
    ++++
    +00+
    +21+
    ++++

Neste exemplo tem-se que K=2 e W=6, sendo portanto mostradas as 6 primeiras peças, com números de 0 a 2. Note-se que a segunda peça mostrada é a mesma que a quarta peça. Não se pretende a remoção de peças repetidas considerando rotações.


## Alínea C

As peças do Dominó clássico são únicas, ou seja, não existem duas peças 2|3, apenas uma peça, podendo a mesma tomar a forma 2|3 ou 3|2 através da rotação. Pretende-se a implementação da unicidade das peças na alínea C, nesta versão de peças com 4 números. De todas as peças/posições identificadas na alínea B, pretendem-se apenas as peças únicas, e numa posição normalizada, que é a primeira versão da peça que ocorre de acordo com a ordem utilizada na alínea B. Pretendem-se ainda as peças por uma ordem fixa, que corresponde também à ordem utilizada na alínea B. Pretende-se a remoção da borda das peças, de modo a reduzir o volume de dados de saída, sendo os dados de entrada os mesmos dois
parâmetros da alínea B (um valor K para o número mais alto, e um valor W para o número máximo de peças a visualizar). No final, pretende-se a indicação do número de peças únicas geradas, independentemente do número de peças visualizadas.

Exemplo de entrada 1:

    1 100


Exemplo de saída 1:

    00
    00

    00
    10
    
    00
    11
    
    01
    10
    
    01
    11
    
    11
    11
    
    6 pecas geradas.

Notar que a segunda peça tem apenas um valor 1 e o resto 0. É gerada apenas esta versão da peça, não sendo gerada das restantes versões. A ordem das peças segue a indicada na alínea B, mas após subtrair as versões que são iguais considerando operações de rotação.

Exemplo de entrada 2:

    2 6


Exemplo de saída 2:

    00
    00
    
    00
    10
    
    00
    20
    
    00
    11
    
    00
    21
    
    00
    12

    24 pecas geradas.

Notar que para o caso de K=1 existem 6 peças distintas, enquanto que com K=2 existem 24 peças distintas. Na alínea anterior, em que se mostrava
todas as peças/posições distintas, existem K^4 peças/posições distintas, enquanto que ao considerar apenas peças únicas, este valor é naturalmente
inferior.


## Alínea D

Pretende-se nesta alínea que selecione W peças, de entre as peças geradas na alínea anterior, que são as peças que tem para jogar. As peças devem
ser baralhadas utilizando a função `randaux`.

Exemplo de Entrada:

    1 3


Exemplo de Saída:

    6 pecas geradas.
    
    0:
     01
     10
    1:
     01
     11
    2:
     11
     11

Nesta execução de exemplo (ainda incompleta), foi introduzido K=1 e W=3, significando que usamos peças de 0 a 1, e pretendemos extrair 3 peças
aleatoriamente, de entre todas as peças únicas possíveis, as quais foram geradas na alínea C. A ordem a apresentar as peças selecionadas, respeita a ordem de geração das peças da alínea B, mesmo
que tenham sido selecionadas pela função baralhar por outra ordem. Pretende-se selecionar peças para colocar na mesa. A primeira peça pode ser colocada após rotação. As restantes peças podem ser colocadas após
rotação mas apenas por baixo da peça mais abaixo da cadeia, à esquerda ou à direita desta, desde que o número de ligação seja igual em ambas as
peças.

Exemplo:

    -- --
    |0|1|
    -- --
    |1|0|
    -- --
       -- --
       |0|1|
       -- --
       |1|1|
       -- --

Estas duas peças, que correspondem ao ID 0 e 1, podem ser colocadas de forma ligada, em que a segunda fica à direita. Esta segunda peça poderia ter sido colocada também à esquerda:

       -- --
       |0|1|
       -- --
       |1|0|
       -- --
    -- --
    |0|1|
    -- --
    |1|1|
    -- --

***
O objetivo do puzzle é fazer uma sequência de jogadas válidas, de modo a gastar todas as peças, e assim terminar o puzzle com sucesso. Se fizer um lance ilegal, o puzzle termina com insucesso. Uma jogada é efetuada após serem inseridos três números inteiros: ID da peça (no caso do exemplo é um valor de 0 a 2), número de rotações (um valor de 0 a 3), e posição da peça (0 na esquerda, 1 na direita). Uma rotação corresponde a rodar a peça 90º no sentido anti-horário.
***

    6 pecas geradas.
    
    0:
     01
     10
    1:
     01
     11
    2:
     11
     11
    Mesa:
    Jogada:0 0 0
    
    0:
     01
     11
    1:
     11
     11
    Mesa:
    01
    10
    Jogada:0 0 0
    
    0:
     11
     11
    Mesa:
     01
     10
    01
    11
    Jogada:0 0 1
    
    Mesa:
     01
     10
    01
    11
     11
     11
    Puzzle terminado.

Notar que foi selecionada sempre a primeira peça em cada momento, portanto o primeiro dos três números foi sempre o número 0. O segundo
número corresponde ao número de rotações a dar à peça, antes de a colocar na mesa, e foi sempre zero, portanto a posição foi a mesma. Apenas no último lance houve a escolha pela direita, e portanto o último número foi 1, mas neste caso teria sido válida a jogada de colocar a peça na esquerda.

## Compilação
    gcc -Wall -o alineaX src/alineaX.c

## Execução
#### Linux ou Windows `PowerShell`
    ./alineaX
#### Windows `cmd.exe`
    alineaX


## Execução com ficheiro de entrada
#### Linux
    ./alineaX < input.txt
#### Windows `PowerShell`
    Get-Content input.txt | ./alineaX
#### Windows `cmd.exe`
    alineaX < input.txt


## Execução no Replit
Run it on Replit [here](https://replit.com/@DiogoAntao/UAblittleDominoPuzzle).
