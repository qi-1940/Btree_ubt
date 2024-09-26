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

char* to_postfix(char* in){
    char* po_in;
    
    return po_in;
}

double evaluate_by_pfix(char* po_in){
    double outcome;

    return outcome;
}

int main (void){

    //Get input.
    printf("Please input a arithmetic expression:\n");
    char* input[100]={'\0'};
    scanf("%s",input);

    //Transform input into postfix.
    char postfix_input[100]={'\0'};
    strncpy(postfix_input,to_postfix(input),sizeof(postfix_input)-1);
    postfix_input[sizeof(postfix_input)-1]='\0';

    //Evaluate through postfix expression and show the outcome.
    printf("The outcome is %5.3g .\n",evaluate_by_pfix(postfix_input));


    return 0;
}