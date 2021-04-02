#include <stdio.h>
#include <stdlib.h> 

int main(){
	
   int a,n,p,menor;
   int *X;
   scanf("%d", &n);
    X = (int*) malloc(n*sizeof(int));
 
    for(a=0; a<n; a++)
        scanf("%d", &X[a]);
    menor=X[0];
    for(a=1; a<n; a++){
        
        if(menor>X[a]){
            
            menor=X[a];
            p=a;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor, p);
    
    return 0;
}