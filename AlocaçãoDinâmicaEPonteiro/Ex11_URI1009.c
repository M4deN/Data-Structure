#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vendedor{
	char nome[100];
	double vendas,comissao,total;
}Vendedor;

int main(){
	
	Vendedor vendedor, *vend;
	vend = &vendedor;
	vend = (Vendedor*) malloc(sizeof(Vendedor));
  
    scanf ("%s",&vend->nome);
  
    scanf("%lf %lf",&vend->vendas,&vend->comissao);
    vend->total = vend->vendas+((vend->comissao*15)/100);
    printf ("TOTAL = R$ %.2lf\n",vend->total);
    
    return 0;
}