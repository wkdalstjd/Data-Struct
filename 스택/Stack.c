#include <stdio.h>
#include <stdlib.h>
#define SIZE 100


typedef struct StackType{
    int arr [SIZE];
    int top;
}StackType;


void init(StackType *s){
    s->top=-1; 
}


// empty= return 1
// !empty= return 0
// 스택이 비어있는지 확인
int is_empty(StackType *s){
    if(s->top==-1)
        return 1;
    return 0;
}

// full = return 1
// !full = return 0
// 스택이 꽉 차있는지 확인인
int is_full(StackType *s){
    if(s->top == SIZE-1)
        return 1;
    return 0;
}

// 데이터를 스택에 넣는 작업업
void push(StackType *s, int value){
    if(is_full(s)){
        printf("Stack is full");
        exit(1);
    }
    printf("pushed: %d\n", value);
    s->arr[++(s->top)] = value;
}

// 데이터를 스택에서 배는 작업업
int pop(StackType *s){
    if(is_empty(s)){
        printf("Stack is empty");
        exit(1);
    }
    return s->arr[(s->top)--];
}

//최상위 데이터 출력
int peek(StackType *s){ 
    if(is_empty(s)){
        printf("Stack is empty");
        exit(1);
    }
    return s->arr[(s->top)];
}

int main(int argc, char const *argv[])
{
    StackType s;
    init(&s); //Stack 초기화

    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    printf("\npeed: %d\n", peek(&s));
    printf("\npop: %d\n", pop(&s));
    printf("\npop: %d\n", pop(&s));
    printf("\npop: %d\n", pop(&s));

    printf("\npop: %d\n", pop(&s));
    return 0;
}
