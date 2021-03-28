#include <stdio.h>
#include <stdlib.h>

typedef struct calculo{
	
	double val1,val2,val3,val4,val5,val6,val7,val8;
    
}Calculo;


int main(){
	
	Calculo calculo, *calc;
	calc = &calculo;
	calc = (Calculo*) malloc(sizeof(Calculo));
	
    
    scanf ("%lf %lf %lf", &calc->val1, &calc->val2, &calc->val3);
    
 	calc->val4=.5*calc->val1*calc->val3;
    calc->val5=3.14159*calc->val3*calc->val3;
    calc->val6=.5*(calc->val1+calc->val2)*calc->val3;
    calc->val7=calc->val2*calc->val2;
    calc->val8=calc->val1*calc->val2;
    
    printf ("TRIANGULO: %.3lf\n", calc->val4);
    printf ("CIRCULO: %.3lf\n", calc->val5);
    printf ("TRAPEZIO: %.3lf\n", calc->val6);
    printf ("QUADRADO: %.3lf\n", calc->val7);
    printf ("RETANGULO: %.3lf\n", calc->val8);
    return 0;
}