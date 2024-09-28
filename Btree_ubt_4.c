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

char * to_postfix(char * s){
    char * o=(char *)calloc(100,sizeof(char));
    Stack op=creat_stack();
    int i=0,j=0;
    while(s[i]!='\0'&&s[i]!='\n'){
        if(s[i]>='0'&&s[i]<='9'){
            o[j++]=s[i];
        }
        else{
            char temp=(char)op->array[op->top];
             if(isEmpty(op)){
                push(op,s[i]);
             }
             else if (s[i]==')')
             {
                while((char)op->array[op->top]!='('){
                    o[j++]=(char)pop(op);
                }
                pop(op);
             }
             else if ((temp)=='+'||((temp)=='-'))
             {
                push(op,s[i]);
             }
             else if ((temp=='*'||temp=='/')&&(s[i]=='+'||s[i]=='-'))
             {
                while((char)op->array[op->top]=='*'||(char)op->array[op->top]=='/'){
                    o[j++]=(char)pop(op);
                }
                push(op,s[i]);
             }
        }
        i++;
    }
    while(!isEmpty(op)){
        //printf("%d\n",op->top);
        o[j++]=(char)pop(op);
        //
    }
    free(op);
    return o;
}

double evaluate_by_pfix(char * s){
    double outcome;
    Stack op = creat_stack();
    int i=0;
    while(s[i]!='\0'&&s[i]!='\n'){
        if(s[i]>='1'&&s[i]<=9){
            push(op,(int)(s[i]-'0'));
            printf("%d\n",(int)(s[i]-'0'));
            //printf("%d\n",(int)(s[i]-'0'));
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
                push(op,((double)a)/b);
            }
        }
        i++;
    }
    outcome=pop(op);
    free(op);
    return outcome;
}

int main (void){
    
    //Get input.
    printf("Please input a arithmetic expression:\n");
    char in[100]={'\0'};
    scanf("%s",in);

    //Transform input into postfix.
    char i_p[100]={'\0'};
    char * p=to_postfix(in);
    strncpy(i_p,p,sizeof(i_p)-1);
    free(p);
    i_p[sizeof(i_p)-1]='\0';
    
    //Evaluate through postfix expression and show the outcome.
    printf("The outcome is %5.3g .\n",evaluate_by_pfix(i_p));

    return 0;
}