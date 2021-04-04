#include <stdio.h>
#include <stdlib.h>

int main(){

    double *n;
    int i;

    n = (double*) malloc(100*sizeof(double));
    
    for(i=0; i<=99; i++);

        scanf("%lf", &n[i]);

    for(i=0; i<=99; i++){

        if(n[i]<=10.0)

            printf("A[%d] = %.1lf\n",i, n[i]);
    }

    return 0;
}