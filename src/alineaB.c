#include <stdio.h>
 
void imprimePeca (int domino[4])
{
    printf("++++\n+%d%d+\n+%d%d+\n++++\n",domino[0],domino[1],domino[3],domino[2]);
}
 
int main() 
{
    int domino[4]={0,0,0,0}, i[4], k, w, total=0;
     
    scanf("%d%d",&k,&w);

    for(i[0]=0;i[0]<=k&&total<w;i[0]++){
      domino[0]=i[0];

      for(i[1]=0;i[1]<=k&&total<w;i[1]++){
        domino[1]=i[1];

        for(i[2]=0;i[2]<=k&&total<w;i[2]++){
          domino[2]=i[2];
     
          for(i[3]=0;i[3]<=k&&total<w;i[3]++,total++){
            domino[3]=i[3];
            imprimePeca(domino);
          }
        }
      }
    }
}