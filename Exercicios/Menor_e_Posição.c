#include <stdio.h>

int main(){

    int a,b,c,d,e,N,k,mun;

    scanf("%d",&N);

    int X[N];

    for(a=0;a<N;a++)

            scanf("%d",&X[a]);

    mun=X[0];

        for(a=1;a<N; a++){

            if(mun>X[a]){

                 mun=X[a];

                 k=a;
            }
        }

    printf("Menor valor: %d\nPosicao: %d\n", mun, k);

    return 0;
    
    }