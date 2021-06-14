#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 500

// Implementacao utilizando 1 fila
typedef struct {
  int v;
  int c;
} num;

typedef struct {
   int head;
   int tail;
   num vet[N];
} queue;

void newQueue(queue *q);
void enqueue(queue *q, int value, int qtd);
num *dequeue(queue *q);
int size(queue *q);
int isEmpty(queue *q);
int isFull(queue *q);

int comp(int n, int op);

int main() {
  int n, m, i;
  num *aux;
  queue q;

  printf("Informe os numeros N e M: ");
  scanf("%d%d", &n, &m);

  newQueue(&q);
  enqueue(&q, n, 0);

  while(n != m) {
    aux = dequeue(&q);
    for (i=0; i<6 && n != m; i++) {
      n = comp(aux->v, i);
      enqueue(&q, n, aux->c + 1);
    }
  }

  printf("Foram necessarios: %d operacoes\n", aux->c + 1);
}

int comp(int n, int op){
  switch (op) {
    case 0: return n * 2; break;
    case 1: return n * 3; break;
    case 2: return n / 2; break;
    case 3: return n / 3; break;
    case 4: return n + 7; break;
    case 5: return n - 7; break;
  }
  return n;
}

void newQueue(queue *q){
  q->head = 0;
  q->tail = 0;
}

int isEmpty(queue *q){
  return q->head == q->tail;
}

int isFull(queue *q){
  return size(q) == N;
}

int size(queue *q){
  return q->tail - q->head;
}

void enqueue(queue *q, int value, int qtd) {
  if (isFull(q)) {
    printf("Queue overflow!\n");
    exit(1);
  }
  q->vet[q->tail % N].v = value;
  q->vet[q->tail % N].c = qtd;
  q->tail++;
}

num *dequeue(queue *q) {
  if (isEmpty(q)) {
    printf("Queue underflow!\n");
    exit(1);
  }
  return &q->vet[q->head++ % N];
}