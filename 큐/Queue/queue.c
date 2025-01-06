#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct Queue{
    int front; //앞 쪽 index
    int rear; //뒤 쪽 index
    int data[MAX];
}Queue;

void init(Queue *q){
    q->front=q->rear =0;
}

int is_full(Queue *q){
    /*if(q->rear == MAX-1)
        return 1;
    return 0;*/

    return ((q->rear+1) % MAX == q->front);
}

int is_empty(Queue *q){
    /*if(q->front==q->rear)
        return 1;
    return 0;*/
    return q->front == q->rear;
}

void enqueue(Queue *q, int item){
    if(is_full(q)){
        printf("Error Queue is full");
        exit(1);
    }
    //q->data[++(q->rear)]=item;
    q->rear=(q->rear+1)%MAX;
    q->data[q->rear]=item;
}

int dequeue(Queue *q){
    if(is_empty(q)){
        printf("Error Queue is empty");
        exit(1);
    }
    q->front=(q->front+1)%MAX;
    return q->data[q->front];
}


int main(int argc, char const *argv[])
{
    Queue q;
    init(&q);
    
    enqueue(&q,3);
    enqueue(&q,2);
    //enqueue(&q,1);


    printf("%d", dequeue(&q));
    printf("%d", dequeue(&q));
    //printf("%d", dequeue(&q));

    enqueue(&q, 3);
    printf("%d", dequeue(&q));
    return 0;
}
