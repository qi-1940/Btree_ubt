#ifndef STACK_BY_ARRAY_H
#define STACK_BY_ARRAY_H

#include "stdbool.h"

typedef struct {
    double * array;
    int top;
    int stacksize;
}SqStack;

typedef SqStack * Stack;



Stack creat_stack();

void push(Stack S,double input);

double pop(Stack S);

_Bool isEmpty(Stack S);

_Bool isFull(Stack S);

#endif