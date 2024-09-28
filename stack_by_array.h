#ifndef STACK_BY_ARRAY_H
#define STACK_BY_ARRAY_H

#include "stdbool.h"

typedef struct {
    int * array;
    int top;
    int stacksize;
}SqStack;

typedef SqStack * Stack;



Stack creat_stack();

void push(Stack S,int input);

int pop(Stack S);

_Bool isEmpty(Stack S);

_Bool isFull(Stack S);

#endif