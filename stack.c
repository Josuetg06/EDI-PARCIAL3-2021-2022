#include <stdio.h>
#define MAX 10
typedef struct  {
    int data[MAX];
    int top;
} Stack;
void setupStack(Stack *s);
int isEmpty(Stack stack);
int isFull(Stack stack);
int push(Stack *s, int value);
int pop (Stack *s, int *v);


int main(){

Stack stack;
int value,r;

    setupStack(&stack);


    r = push(&stack, 5);
    r = push(&stack, 15);
    r = push(&stack, 25);
    r = push(&stack, 35);
    r = push(&stack, 45);
    r = push(&stack, 65);


    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);

    setupStack(&stack);


return 0;
}

void setupStack(Stack *s){
    s->top=-1;
}
int isEmpty(Stack stack){
    if (stack.top==-1)
        return 1;
    return 0;


}
int isFull(Stack stack){
    if (stack.top== MAX-1)
        return 1;
    return 0;
}
int push(Stack *s, int value){

    int r=0;
    if (isFull(*s)==0){
        s->top++;
        s->data[s->top]=value;
        r=1;
    }
    return r;
}
int pop (Stack *s, int *v){


    if (!isEmpty(*s)){
        *v= s->data[s->top];
        s->top--;
        return 1;
    }
    return 0;
}


