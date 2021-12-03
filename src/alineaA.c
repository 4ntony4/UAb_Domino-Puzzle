#include <stdio.h>

void imprimePeca (int domino[4])
{
    printf("++++\n+%d%d+\n+%d%d+\n++++\n",domino[0],domino[1],domino[3],domino[2]);
}

int main()
{
    int domino[4], i;
    
    for(i=0;i<4;i++)
        scanf("%d",&domino[i]);
    
    imprimePeca(domino);
}