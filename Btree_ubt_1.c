/*
二叉树节点的插入
*/
#include <stdio.h>
#include<stdlib.h>
#include"Btree_ubt_0.h"

void search(Ptr root,int val){
    Ptr temp,back,new_node;
    temp=root;
    if(temp==NULL){
        creat_Btree(root,val);
        return;
    }
    while(temp){
        back=temp;
        if(val==temp->data){
            printf("The node already exists!\n");
            return;
        }
        else if (val>temp->data)
        {
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    creat_Btree(root,val);
    printf("This node has been added!\n");
}

int main(){
    int input;
    Ptr root=NULL;
    while (1)
    {
        printf("Please input an interger to establish a binary search tree.\n");
        scanf("%d",&input);
        if(input==0){
            break;
            return 0;
        }
        else{
            root=creat_Btree(root,input);
        }
    }
    printf("\nBinary search tree established successfully!\n");
    while(1){
        printf("Input a valve:");
        scanf("%d",&input);
        search(root,input);
    }
    return 0;
}