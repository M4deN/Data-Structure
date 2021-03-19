#include <stdio.h>
#include <stdlib.h> 

int main(){
	
    int x;
    double y;
    double *n;

    n = (double*) malloc(100*sizeof(double));
    
    
    scanf("%lf", &y);
    
    n[x]=y;
    
    for(x=0; x<100;x++){
    	
        printf("N[%d] = %.4lf\n", x, n[x]);
        y/=2;
        n[x+1]=y;
    }
    return 0;
}