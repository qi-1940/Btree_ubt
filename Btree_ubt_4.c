/*
Binary Expression Tree:

Firstly,requirements are listed below.
Evaluates two given expressions' valve.They are inorder.
Meanwhile,obtain expressions with preorder traversal 
and postorder traversal.

The program needs stack to run.Stack in this program
is accomplish by array.
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include"stack_by_array.h"

SqStack  string_to_stack(char * s){
    SqStack input;
    input=creat_stack();
    int i=0;
    while(s[i]!='\0'||s[i]!='\n'){
        push(input,s[i]);
        i++;
    }
    return input;
}

char * to_postfix(char * s){
    char * o=(char *)malloc(100*sizeof(char));
    for(int i=0;i<100;i++){
        o[i]='\0';
    }
    SqStack op;
    op=creat_stack();
    int i=0,j=0;
    while(s[i]!='\0'||s[i]!='\n'){
        if(isdigit( s[i])){
            o[j++]=s[i];
        }
        else{
             if(op.top==op.base){
                push(op,s[i]);
             }
             else if (s[i]==')')
             {
                while(*op.top!='('){
                    o[j++]=pop(op);
                }
                pop(op);
             }
             
             else if ((*op.top)=='+'||(*(op.top))=='-')
             {
                push(op,s[i]);
             }
             else if (*op.top=='*'||*op.top=='/')
             {
                if(s[i]=='+'||s[i]=='-'){
                    while(!(*op.top=='*'||*op.top=='/')){
                        o[j++]=pop(op);
                    }
                    push(op,s[i]);
                }
                else if (s[i]=='*'||s[i]=='/')
                {
                    
                    push(op,s[i]);
                }
                
             }  
        }
        i++;
    }
    while(!isEmpty(op)){
        o[j++]=pop(op);
    }
    free(op.base);
    return o;
}

double evaluate_by_pfix(char * s){
    double outcome;
    SqStack op = creat_stack(op);
    int i=0;
    while(s[i]!='\0'||s[i]!='\n'){
        if(isdigit(s[i])){
            push(op,s[i]);
        }
        else{
            if(s[i]=='+'){
                int a,b;
                a=pop(op);
                b=pop(op);
                push(op,a+b);
            }
            else if (s[i]=='-')
            {
                int a,b;
                a=pop(op);
                b=pop(op);
                push(op,a-b);
            }
            else if (s[i]=='*')
            {
                int a,b;
                a=pop(op);
                b=pop(op);
                push(op,a*b);
            }
            else if (s[i]=='/')
            {
                int a,b;
                a=pop(op);
                b=pop(op);
                push(op,(double)a/b);
            }
            
            
        }

        i++;
    }
    outcome=pop(op);
    free(op.base);
    return outcome;
}

int main (void){
    
    //Get input.
    printf("Please input a arithmetic expression:\n");
    char input_0[100]={'\0'};
    scanf("%s",input_0);

    //Transform input into postfix.
    char i_p[100]={'\0'};
    char * p=to_postfix(input_0);
    strncpy(i_p,p,sizeof(i_p)-1);
    free(p);
    i_p[sizeof(i_p)-1]='\0';
    
    //Evaluate through postfix expression and show the outcome.
    printf("The outcome is %5.3g .\n",evaluate_by_pfix(i_p));

    return 0;
}