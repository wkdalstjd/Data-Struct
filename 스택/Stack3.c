#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    //printf("pushed: %d\n", value);
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


int prec(char op){
    switch (op)
    {
    case '(': case ')':
        return 0;
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    }
    return -1;
}

//중위->후위
/*void infix_to_postfix(char exp[]){
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    init(&s);

    for(int i=0; i<len; i++){
        ch=exp[i];
        switch (ch)
        {
        case '+': case '-': case '*': case '/':
            while(!is_empty(&s)&&(prec(ch)<=prec(peek(&s))))//스택이 비어있지 않으면서 스택의 최상단이 ch 보다 크거나 같은경우
                printf("%c", pop(&s));
            push(&s, ch);    
            break;
        case '(': 
            push(&s, ch);
            break;
        case ')':
            top_op = pop(&s);
            while(top_op != '('){
                printf("%c",top_op);
                top_op = pop(&s);
            }
            break;
        default:
           printf("%c", ch);
           break;
        }
    }
    while(!is_empty(&s))
        printf("%c", pop(&s));
}*/

// 후위표기식 계산하는 함수
int eval(char exp[]){
    int op1, op2, value;
    char ch;
    int len = strlen(exp);

    StackType s;
    init(&s);
    for(int i=0; i<len; i++){
        ch=exp[i];
        if(ch!='+' && ch!='-' && ch!='*'&&ch!='/'){
            value=ch-'0'; //문자 -> 숫자
            push(&s, value);
        }else{
            op2=pop(&s);
            op1=pop(&s);
            switch (ch)
            {
            case '+':
                push(&s, op1+op2);
                break;
            case '-':
                push(&s, op1-op2);
                break;
            case '*':
                push(&s, op1*op2);
                break;
            case '/':
                push(&s, op1/op2);
                break;
            }
        }
    }
    return pop(&s);
}

int main(int argc, char const *argv[])
{
    int result;
    result = eval("82/3-32*+");
    printf("--> %d", result);

    return 0;
}
