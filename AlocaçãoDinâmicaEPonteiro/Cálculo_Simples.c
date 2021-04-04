#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vendas{

	int cod1,num1,cod2,num2;
	double val1,val2,total;
}Vendas;

int main(){
   
    Vendas vendas, *vend;
	vend = &vendas;
	vend = (Vendas*) malloc(sizeof(Vendas));
	
    scanf ("%d %d %lf", &vend->cod1,&vend->num1,&vend->val1);
    
    scanf ("%d %d %lf", &vend->cod2,&vend->num2,&vend->val2);
    
    vend->total=(vend->num1*vend->val1)+(vend->num2*vend->val2);
    
    printf ("VALOR A PAGAR: R$ %.2lf\n",vend->total);
    
    return 0;
}