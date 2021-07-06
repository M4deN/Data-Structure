#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 50

typedef struct {
   int top;
   char vet[N];
} stack;

typedef struct {
   int head;
   int tail;
   char vet[N];
} queue;

void newQueue(queue *q);
void enqueue(queue *q, char value);
char dequeue(queue *q);
int isEmpty(queue *q);
int isFull(queue *q);
void showQueue(queue *q);
void inverte(queue *q);

void newStack(stack *s);
int isStackEmpty(stack *s);
int isStackFull(stack *s);
void push(stack *s, char value);
char pop(stack *s);
char top(stack *s);

int main(){
   int i;
   queue q;
   stack s;
   char texto[N], aux;

   newStack(&s);
   newQueue(&q);

   printf("Informe a sequencia: ");
   scanf("%s", texto);

   for (i=0; i < strlen(texto); i++) {
     aux = texto[i];
     if (aux >= '0' && aux <= '9') {
       push(&s, aux);
       aux = '9';
     }

     enqueue(&q, aux);
   }

   printf("\n\n%s -> ", texto);
   while (!isEmpty(&q)) {
     aux = dequeue(&q);
     if (aux == '9') {
       printf("%c", pop(&s));
     } else {
       printf("%c", aux);
     }
   }
   printf("\n");

}


void newStack(stack *s) {
   s->top = 0;
}

int isStackEmpty(stack *s) {
   return s->top == 0;
}

int isStackFull(stack *s) {
   return s->top == N;
}

void push(stack *s, char value) {
   if (isStackFull(s)) {
     printf("Stack overflow!\n");
     exit(1);
   }

   s->vet[s->top++] = value;
}

char pop(stack *s) {
  if (isStackEmpty(s)) {
    printf("Stack underflow!\n");
    exit(1);
  }
  s->top--;
  return s->vet[s->top];
}

char top(stack *s) {
  if (isStackEmpty(s)) {
    printf("Stack underflow!\n");
    exit(1);
  }
  return s->vet[s->top - 1];
}

void newQueue(queue *q) {
  q->head = 0;
  q->tail = 0;
}

int isEmpty(queue *q) {
  return q->head == q->tail;
}

int isFull(queue *q) {
  return q->tail - q->head == N;
}

void enqueue(queue *q, char value) {
  if (isFull(q)) {
    printf("Queue overflow!\n");
    exit(1);
  }
  q->vet[q->tail++ % N] = value;
}

char dequeue(queue *q) {
  if (isEmpty(q)) {
    printf("Queue underflow!\n");
    exit(1);
  }
  return q->vet[q->head++ % N];
}

void showQueue(queue *q) {
  int i;
  printf("Queue: ");
  for (i=q->head; i<q->tail; i++) {
    printf("%d ", q->vet[i%N]);
  }
  printf("\n");
}