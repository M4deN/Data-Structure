#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
	int codigo;
	int horas_t;
	double valor_h;
}Funcionario;

int main(){
	
	Funcionario funcionario, *func;
	func = &funcionario;

    func = (Funcionario*) malloc(sizeof(Funcionario));
    
    scanf ("%d %d %lf", &func->codigo,&func->horas_t,&func->valor_h);

    printf ("NUMBER = %d\nSALARY = U$ %.2lf\n",func->codigo,(func->horas_t*func->valor_h));
    return 0;
}