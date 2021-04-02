#include <stdio.h>
#include <stdlib.h> 

int main(){
	
    int x, y,i;
    int *n;
    
    n = (int*) malloc(1000*sizeof(int));
    
    scanf ("%d", &x);
    
    for(y=0,i=0; y<1000; y++){
    	
        printf("N[%d] = %d\n",y,i);
        i++;
        if(i==x)
            i=0;
    }
    
    return 0;
}