#include <stdio.h>
#include "stack_by_array.h"
#include <stdbool.h>
//#include "status.h"
#include <stdlib.h>

#define STACK_SIZE 100
#define STACKINCREMENT 10

SqStack creat_stack(){
    SqStack S;
    S.base=(int *)malloc(STACK_SIZE * sizeof(int));
    S.top=S.base;
    S.stacksize=STACK_SIZE;
    return S;
}

SqStack push(SqStack S,int input){
    if(S.top-S.base>=S.stacksize){
        S.base=(int *)realloc(S.base,
        (S.stacksize+STACKINCREMENT)*sizeof(int));
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    * S.top ++ = input;
    return S;
}

int pop(SqStack S){
    if(S.base==S.top){
        printf("Failed to pop brcause there is no data int the\ 
        stack./n");
        return -999;
    }
    else{
        int i = *(S.top);
        S.top--;
        S.stacksize--;
        return i;
    }
}

_Bool isEmpty(SqStack S){
    return S.base==S.top?true:false;
}

_Bool isFull(SqStack S){
    return (S.top-S.base)==S.stacksize?true:false;
}