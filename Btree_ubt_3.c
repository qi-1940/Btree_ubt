/*
The algorithm in
this file 
is demonstrated very 
difficult to
 accomplish.So I 
have abandoned it.
*/



/*
Binary Expression Tree:

Firstly,requirements are listed below.
Evaluates two given expressions' valve.They are inorder.
Meanwhile,obtain expressions with preorder traversal 
and postorder traversal.

Sceondly,methods uesd are introduced below,too.
To process data,i.e.,a string,we need to put parentheses 
around it.
Then build Binary Expression Tree from the innermost 
parentheses to the outermost.
*/
#include <stdio.h>
#include<stdlib.h>
//include"Btree_ubt_0.h"

//Define a new type node and its associated variables.
struct Node_BET{
    struct Node_BET* left;
    struct Node_BET* right;
    char data;
};
typedef struct Node_BET Node_BET;
typedef Node_BET* Ptr;

//Define the priority of the four operators.
struct operator{
    char oper;
    int priority;
};
typedef struct operator operator;
operator op1={'+',1};
operator op2={'-',1};
operator op3={'*',2};
operator op4={'/',2}; 

//Return a char's,i.e.,operator's,priority.
int return_priority(char op){
    if(op=='+'||op=='-'){
        return 1;
    }
    else if (op=='*'||op=='/')
    {
        return 2;
    }
    else{
        return 0;
    }
    
}

char* add_parentheses(char* input){
    char* re[100]={'\0'};
    for(int i=0;input[i]!='\0';i++){





        //When the char is a operator.
        if((!isdigit(input[i]))&&input[i]!='('&&input[i]!=')')
        {


            if(
            
            ((i-2>=0&&return_priority(input[i-2])<=return_priority(input[i]))||(i==1))
            
            &&
            
            ((i+2<=(sizeof(input)-1)&&return_priority(input[i+2])<=return_priority(input[i]))||(i+1==sizeof(input)))
            
            
            )
            
            
            
            {
                re[i-2+1]='(';
                re[i+2+1]=')';
                for(int j=0;i<=sizeof(input)-1+2;j++){
                    
                    if(j<=i-2){
                        re[j]=input[j];
                    }
                    else if (j>=i&&j<=i+2)
                    {
                        re[j]=input[j-1];
                    }
                    else if(j>=i+4){
                        re[j]=input[j-2];
                    }
                    
                    
                        
                    
                    
                    
                }
            }
        }









    }

    
}

Ptr build_BET(char* input_w_a){

}

double calculate_by_BET(Ptr root){
    double outcome;

    return outcome;
}

int main(){
    printf("Please input a arithmetic expression:\n");
    char* input[100]={'\0'};
    scanf("%s",input);
    char* input_with_parentheses[100]={'\0'};
    strcat(input_with_parentheses,add_parentheses(input));
    //You have obtain the expression with parentheses.
    printf("The outcome is %d.\n",calculate_by_BET
    (build(input_with_parentheses)));
    return 0;
}