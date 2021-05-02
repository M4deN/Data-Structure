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
void enqueue(queue *q, int num);
int dequeue(queue *q);
int isEmpty(queue *q);
int isFull(queue *q);

int main() {

        int num, i;
        queue q;

        printf("Informe um numero: ");
        scanf("%d", &num);

        newQueue(&q);

        for(i = 1; i <= num; i++) {

            enqueue(&q, i);
        }

        printf("Cartas descartadas: ");
        
        for(i=1; i < num; i++) {
            printf("%d, ", dequeue(&q));
            enqueue(&q, dequeue(&q));
        }

        printf("\nCarta restante: %d\n", dequeue(&q));
        }

        void newQueue(queue *q) {
        q->head = 0;
        q->tail = 0;
        }

        int isEmpty(queue *q) {
        return q->head == q->tail;
        }

        int isFull(queue *q) {
        return q->tail == N;
        }

        void enqueue(queue *q, int num) {
        if (isFull(q)) {
            printf("Queue overflow!\n");
            exit(1);
        }
        q->vet[q->tail] = num;
        q->tail++;
        }

        int dequeue(queue *q) {

        if (isEmpty(q)) {
            printf("Queue underflow!\n");
            exit(1);
        }
        return q->vet[q->head++];
}