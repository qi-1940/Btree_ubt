#ifndef STACK_BY_ARRAY_H
#define STACK_BY_ARRAY_H

#include "stdbool.h"

typedef struct {
    int * base;
    int * top;
    int stacksize;
}SqStack;

SqStack creat_stack();

SqStack push(SqStack S,int input);

int pop(SqStack S);

_Bool isEmpty(SqStack S);

_Bool isFull(SqStack S);

#endif