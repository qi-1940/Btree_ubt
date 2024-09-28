#include <stdio.h>
#include "stack_by_array.h"
#include <stdbool.h>
//#include "status.h"
#include <stdlib.h>

#define STACK_SIZE 100
#define STACKINCREMENT 10

Stack creat_stack(){
    Stack S;
    S=malloc(sizeof(SqStack));
    S->array=(int *)malloc(STACK_SIZE * sizeof(int));
    S->top=-1;
    S->stacksize=STACK_SIZE;
    return S;
}

void push(Stack S,int input){
    if(S->top>=S->stacksize-1){
        S->array=(int *)realloc(S->array,
        (S->stacksize+STACKINCREMENT)*sizeof(int));
        S->stacksize+=STACKINCREMENT;
    }
    S->array[++S->top] = input;
    return S;
}

int pop(Stack S){
    if(S->top==-1){
        printf("Failed to pop brcause there is no data int the stack.\n");
        exit(-1);
    }
    else{
        return S->array[S->top--];
    }
}

_Bool isEmpty(Stack S){
    return S->top==-1?true:false;
}

_Bool isFull(Stack S){
    return S->top==S->stacksize-1?true:false;
}