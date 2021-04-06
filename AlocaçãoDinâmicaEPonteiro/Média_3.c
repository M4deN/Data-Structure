#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{

	double nota1,nota2,nota3,nota4,nota5,v1,v2;
    
}Aluno;

int main(){
  
 	Aluno aluno, *alunos;
	alunos = &aluno;
	alunos = (Aluno*) malloc(sizeof(Aluno));
	
    scanf ("%lf%lf%lf%lf", &alunos->nota1,&alunos->nota2,&alunos->nota3,&alunos->nota4);

    alunos->v1=((alunos->nota1*2)+(alunos->nota2*3)+(alunos->nota3*4)+alunos->nota4)/10;

    printf ("Media: %.1lf\n",alunos->v1);

    if(alunos->v1>=7)

        printf ("Aluno aprovado.\n");

    else if(alunos->v1<5)

        printf("Aluno reprovado.\n");

    else if(alunos->v1>=5&&alunos->v1<=6.9){

        printf ("Aluno em exame.\n");

        scanf("%lf", &alunos->nota5);

        printf ("Nota do exame: %.1lf\n",alunos->nota5);

        alunos->v2=(alunos->nota5+alunos->v1)/2;

        if(alunos->v2>=5)

            printf ("Aluno aprovado.\n");

        else if(alunos->v2<=4.9)
            printf ("Aluno reprovado.\n");

        printf ("Media final: %.1lf\n",alunos->v2);
    }

    return 0;
}