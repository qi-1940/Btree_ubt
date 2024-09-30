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

int * to_postfix(int * s){
    int * o=(int *)calloc(100,sizeof(int));
    Stack op=creat_stack();
    int i=0,j=0;
    while(s[i]!='\0'&&s[i]!='\n'){

        //printf("s[i]=%c.\n",(char)s[i]);

        if(s[i]>='0'&&s[i]<='9'){
            o[j++]=s[i];
        }
        else{

            char temp=(char)op->array[op->top];
            //printf("temp=%c\n",temp);

             if(isEmpty(op)){
                push(op,s[i]);
             }
             else if (s[i]==')')
             {
                while((char)op->array[op->top]!='('){
                    o[j++]=(char)pop(op);
                    //printf("%c was poped and outputed!\n",o[j-1]);
                }
                //printf("%c was poped !\n",op->array[op->top]);
                pop(op);
                
             }
             else if ((temp=='+'||temp=='-')&&(s[i]=='+'||s[i]=='-'))
             {
                o[j++]=(char)pop(op);
                push(op,s[i]);
             }
             else if ((temp=='*'||temp=='/')&&(s[i]=='+'||s[i]=='-'))
             {
                while((char)op->array[op->top]=='*'||(char)op->array[op->top]=='/'||
                (char)op->array[op->top]=='+'||(char)op->array[op->top]=='-'
                ){
                    o[j++]=(char)pop(op);
                }
                push(op,s[i]);
             }
             /*
             else if ((temp=='*'||temp=='/')&&(s[i]=='*'||s[i]=='/'))
             {
                o[j++]=(char)pop(op);
                push(op,s[i]);
             }
             */
             else if (s[i]=='(')
             {
                push(op,s[i]);
             }
             else
             {
                push(op,s[i]);
             }
             
             

             
        }
        //printf("%d was changed to %d.\n",i,i+1);
        i++;
    }


    while(!isEmpty(op)){
        o[j++]=(char)pop(op);
    }
    free(op);
    return o;
}

double evaluate_by_pfix(char * s){
    show(s);
    double outcome;
    Stack op = creat_stack();
    




    int i=0;
    while(s[i]!='\0'&&s[i]!='\n'){
        printf("s[i]=%c.\n",(char)s[i]);
        if(s[i]>='1'&&s[i]<='9'){
            printf("%5.3f was pushed in!\n",(double)s[i]-'0');
            push(op,(double)s[i]-'0');
        }
        else{
            if(s[i]=='+'){
                double a,b;
                a=pop(op);
                b=pop(op);
                push(op,b+a);
                printf("%5.3f+%5.3f=%5.3f\n",b,a,b+a);
            }
            else if (s[i]=='-')
            {
                double a,b;
                a=pop(op);
                b=pop(op);
                push(op,b-a);
                printf("%5.3f-%5.3f=%5.3f\n",b,a,b-a);
            }
            else if (s[i]=='*')
            {
                double a,b;
                a=pop(op);
                b=pop(op);
                push(op,b*a);
                printf("%5.3f*%5.3f=%5.3f\n",b,a,b*a);
            }
            else if (s[i]=='/')
            {
                double a,b;
                a=pop(op);
                b=pop(op);
                push(op,b/a);
                printf("%5.3f/%5.3f=%5.3f\n",b,a,b/a);
            }
        }
        i++;
    }
    outcome=pop(op);
    free(op);
    return outcome;
}

void show(char* in){
    int i=0;
    while(in[i]!='\n'&&in[i]!='\0'){
        printf("%c",in[i]);
        i++;
    }
    printf("\n");
}

int transform(char * in){

}

int main (void){
    
    //Get input.
    printf("Please input a arithmetic expression:\n");
    //char in[100]={'\0'};
    //scanf("%s",in);
    int in[100]={'\0'};
    char temp[10]={'\0'};
    int i=0;
    int j=0;
    char ch,ch_;
    while(ch=getchar()!='\0'&&ch!='\n'){
        if(j>=9){
            printf("Single number is too long!\n");
            exit(-999);
        }
        //ch=getchar();
        ch_=getchar();
        if((ch>='1'&&ch<='9')&&(ch_>='1'&&ch_<='9')){
            temp[j++]=ch;
        }
        else if ((ch>='1'&&ch<='9')&&!(ch_>='1'&&ch_<='9'))
        {
            temp[j++]=ch;
            j=0;
            in[i++]=transform(temp);
        }
        else{

            in[i++]=ch-50;
        }
        
    }
    

    //Transform input into postfix.
    int i_p[100]={'\0'};
    int * p=to_postfix(in);
    strncpy(i_p,p,sizeof(i_p)-1);
    
    free(p);
    i_p[sizeof(i_p)-1]='\0';
    //show(i_p);
    
    //Evaluate through postfix expression and show the outcome.
    printf("The outcome is %5.3g .\n",evaluate_by_pfix(i_p));

    return 0;
}