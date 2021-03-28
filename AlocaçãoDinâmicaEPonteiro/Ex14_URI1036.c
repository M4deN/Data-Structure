#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct bhaskara{
	
	double val1,val2,val3,val4,val5,val6,val7;

}Bhaskara;

int main(){
	
	Bhaskara bhaskara, *bhask;
	bhask = &bhaskara;
	bhask = (Bhaskara*) malloc(sizeof(Bhaskara));
	
   
    scanf ("%lf%lf%lf", &bhask->val1,&bhask->val2,&bhask->val3);
    bhask->val4=bhask->val2*bhask->val2-4*bhask->val1*bhask->val3;
    bhask->val5=pow(bhask->val4,.5);
    if(bhask->val4<0||bhask->val1==0)
        printf ("Impossivel calcular\n");
    else
    {
        bhask->val6=(-bhask->val2+bhask->val5)/(2*bhask->val1);
        bhask->val7=(-bhask->val2-bhask->val5)/(2*bhask->val1);
        printf ("R1 = %.5lf\n",bhask->val6);
        printf ("R2 = %.5lf\n",bhask->val7);
    }
    return 0;
}