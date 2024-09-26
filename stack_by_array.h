#ifndef STACK_BY_ARRAY_H
#define STACK_BY_ARRAY_H

#include<stdbool.h>

int* creat_stack();
int* push(int input);
int pop();
_Bool isEmpty(int* stack);
_Bool isFull(int* stack);

#endif