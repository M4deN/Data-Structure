#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100

typedef struct {
   int head;
   int tail;
   int vet[N];
} queue;

void newQueue(queue *q);
void enqueue(queue *q, char num);
char dequeue(queue *q);
int isEmpty(queue *q);
int isFull(queue *q);
int size(queue *q);
void fillQueue(queue *q, char *seq);
void mergeQueues(queue *target, queue *q1, queue *q2);
void showQueue(queue *q);
void clone(queue *q1, queue *q2);

int main() {


  int num, i;
  char seq[N];
  queue q1, q2, q3;

  newQueue(&q1);
  newQueue(&q2);
  newQueue(&q3);

  printf("Informe a primeira sequencia: ");
  scanf("%s", seq);
  fillQueue(&q1, seq);

  printf("Informe a segunda sequencia: ");
  scanf("%s", seq);
  fillQueue(&q2, seq);

  mergeQueues(&q3, &q1, &q2);

  showQueue(&q1);
  showQueue(&q2);
  showQueue(&q3);
}

void clone(queue *q1, queue *q2) {
  int i;

  q2->head = q1->head;
  q2->tail = q1->tail;
  for (i=q1->head; i<q1->tail; i++) {
    q2->vet[i%N] = q1->vet[i%N];
  }
}

void showQueue(queue *q) {
  char c;
  
  int i, x = 0, y = 0;
  printf("Instrucoes: ");
  for (i=q->head; i<q->tail; i++) {
    c = q->vet[i%N];
    switch (c) {
      case 'a':
        x--;
        break;
      case 'd':
        x++;
        break;
      case 's':
        y--;
        break;
      case 'w':
        y++;
        break;
    }
    printf("%c", c);
  }
  printf(": X: %d, Y: %d\n", x, y);
}

void mergeQueues(queue *target, queue *q1, queue *q2) {
  char c;
  queue maior, menor;


  if (size(q1) > size(q2)) {
    clone(q1, &maior);
    clone(q2, &menor);
  } else {
    clone(q1, &menor);
    clone(q2, &maior);
  }

  while(!isEmpty(&maior)) {
    enqueue(target, dequeue(&maior));

    c = dequeue(&menor);
    enqueue(target, c);
    enqueue(&menor, c);
  }
}

void fillQueue(queue *q, char *seq) {
  while(*seq != '\0') {
    if (*seq == 'a' || *seq == 's' || *seq == 'd' || *seq == 'w') {
      enqueue(q, *seq);
    }
    seq++;
  }
}

void newQueue(queue *q) {
  q->head = 0;
  q->tail = 0;
}

int size(queue *q) {
  return q->tail - q->head;
}

int isEmpty(queue *q) {
  return q->head == q->tail;
}

int isFull(queue *q) {
  return q->tail == N;
}

void enqueue(queue *q, char num) {
  if (isFull(q)) {
    printf("Queue overflow!\n");
    exit(1);
  }
  q->vet[q->tail] = num;
  q->tail++;
}

char dequeue(queue *q) {
  if (isEmpty(q)) {
    printf("Queue underflow!\n");
    exit(1);
  }
  return q->vet[q->head++];
}