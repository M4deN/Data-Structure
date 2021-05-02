#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define N 30

typedef struct {
   int top;
   int vet[N];
} stack;

void newStack(stack *s){

   s->top = 0;
}

int isEmpty(stack *s){

   return s->top == 0;
}

int isFull(stack *s){

   return s->top == N;
}

void push(stack *s, int value){

   if (isFull(s)){

     printf("Stack overflow!\n");

     exit(1);
   }

   s->vet[s->top++] = value;
}

int pop(stack *s){

  if (isEmpty(s)){

    printf("Stack underflow!\n");

    exit(1);
  }
  s->top--;

  return s->vet[s->top];
}

int top(stack *s){

  if (isEmpty(s)){

    printf("Stack underflow!\n");

    exit(1);
  }

  return s->vet[s->top - 1];

}

void clone(stack *s1, stack *s2){

  int i;

  s2->top = s1->top;

  for (i = 0; i < s1->top; i++){

    s2->vet[i] = s1->vet[i];

  }
}

void converte(stack *p, int n, int base);

void showNumber(stack *s, int base);

int main(){

  int n, i;
  stack p2, p8, p16;

  printf("Informe o numero: ");
  scanf("%d",&n);

  newStack(&p2);
  newStack(&p8);
  newStack(&p16);

  converte(&p2, n, 2);
  converte(&p8, n, 8);
  converte(&p16, n, 16);

  showNumber(&p2, 2);
  showNumber(&p8, 8);
  showNumber(&p16, 16);
  
}

void showNumber(stack *s, int base) {
  int aux;
  stack *p = (stack *)malloc(sizeof(stack));
  clone(s, p);
  printf("Base %2d: ", base);
  while(!isEmpty(p)) {
    aux = pop(p);
    if (aux > 9) {
      printf("%c", 'a' + aux % 10);
    } else {
      printf("%d", aux);
    }
  }
  printf("\n");
}

void converte(stack *p, int n, int base) {
  while(n != 0) {
    push(p, n % base);
    n = n / base;
  }
}