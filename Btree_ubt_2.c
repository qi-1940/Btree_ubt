/*
二叉树节点的deletion
*/
#include <stdio.h>
#include<stdlib.h>
#include"Btree_ubt_0.h"
Ptr delete(Ptr root,int val);
int main(){
    int input;
    Ptr root=NULL;
    while (1)
    {
        printf("Please input an integer to establish a binary search tree.\n");
        scanf("%d",&input);
        if(input==0){
            break;
        }
        else{
            root=creat_Btree(root,input);
        }
    }
    printf("\nBinary search tree established successfully!\n");
    printf("Input one integer which you want to delete:\n");
    int input2;
    scanf("%d",&input2);
    show(delete(root,input2));
    printf("Over!\n");
    return 0;
}

Ptr delete(Ptr root,int val){
    Ptr temp=search(root,val);
    Ptr father_of_temp=search_by_relation(root,temp);
    if(temp->left==NULL&&temp->right==NULL){
        father_of_temp->left=NULL;
        father_of_temp->right=NULL;
        free(temp);
        temp=NULL;
        return root;
    }
    else if (temp->left==NULL||temp->right==NULL)
    {
        if(temp->left==NULL){
            if(father_of_temp->left==temp){
                father_of_temp->left=temp->right;
            }
            else{
                father_of_temp->right=temp->right;
            }
            
        }
        else{
                if(father_of_temp->left==temp){
                father_of_temp->left=temp->left;
                }
                else{
                father_of_temp->right=temp->left;
                }
        }
        free(temp);
        temp=NULL;
        return root;
    }
    else 
    {
        Ptr temp2=temp->left;
        while(temp2!=NULL){
            Ptr father_of_temp2=search_by_relation(root,temp2);
            if(temp2->right==NULL){
                temp->data=temp2->data;
                father_of_temp2->right=NULL;
                free(temp2);
                temp2=NULL;
                return root;
            }
            temp2=temp2->right;
        }
    }
}
    
