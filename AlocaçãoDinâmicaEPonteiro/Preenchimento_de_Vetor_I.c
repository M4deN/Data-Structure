#include <stdio.h>
#include <stdlib.h>

int main(){

    int x,y;
    int *n;

    n = (int*) malloc(10*sizeof(int));

    scanf("%d", &y);

    for(x=0; x<=9; x++){
    	
        n[x]=y;

        printf("N[%d] = %d\n",x,y);
        
        y*=2;
    }

    return 0;
}