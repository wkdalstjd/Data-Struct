/*DEQUE: queue의 front와 rear에서 모두 삽입과 삭제가 가능한 queue를 의미함
         중간에 삽입, 삭제 불가능함
         원형큐를 기반으로 구현함 
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_DEQUE_SIZE 3

typedef int element;
typedef struct DequeType{
    element data[MAX_DEQUE_SIZE];
    int front, rear;
}DequeType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_deque(DequeType *d){
    d->front = d->rear=0;
}

int is_empty(DequeType *d){
    return (d->front==d->rear);
}

int is_full(DequeType *d){
    return ((d->rear)+1 % MAX_DEQUE_SIZE==d->front);
}

void add_rear(DequeType *d, element item){
    if(is_full(d))
        error("Deque is full");
    //데이터가 deque에 추가될때 항상 뒤의 값을 체크해야한다
    d->rear = (d->rear+1) % MAX_DEQUE_SIZE;
    d->data[d->rear]=item;
}

element delete_front(DequeType*d){
    if(is_empty(d))
        error("Deque is empty");
    //데이터가 deque에서 삭제될때 우리는 앞의 값을 체크해야함
    d->front=(d->front+1)%MAX_DEQUE_SIZE;
    return d->data[d->front];
}

void add_front(DequeType *d, element item){
    if(is_full(d))
        error("Deque is full");
    d->data[d->front]=item;
    d->front=(d->front-1+MAX_DEQUE_SIZE)% MAX_DEQUE_SIZE;
}

element delete_rear(DequeType *d){
    int prev = d->rear;
    if(is_empty(d))
        error("Deque is empty");
    d->rear = (d->rear-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    return d->data[prev];
}

element get_rear(DequeType *d){
    if(is_empty(d))
        error("Deque is empty");
    return d->data[d->rear];
}

element get_front(DequeType *d){
    if(is_empty(d))
        error("Deque is empty");
        return d->data[(d->front+1)%MAX_DEQUE_SIZE];
}

int main(){
    DequeType deque;
    init_deque(&deque);

    for(int i=0; i<3; i++)
        add_front(&deque, i);
    
    printf("\n%d", get_front(&deque));
    printf("\n%d", get_rear(&deque));

    for(int i=0; i<3; i++){
        printf("\n%d", delete_rear(&deque));
    }
    
    return 0;
}