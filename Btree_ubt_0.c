/*
该文件包含了Btree_ubt项目中大部分源文件所需的函数.

The function list:
void show(Ptr);
Ptr search(Ptr,int);
Ptr search_by_relation(Ptr,int);
Ptr creat_Btree(Ptr,int);

*/
#include <stdio.h>
#include<stdlib.h>
#include "Btree_ubt_0.h"
//show
void show(Ptr root){
    Ptr temp=root;
    if(temp!=NULL){
        if(temp->left!=NULL&&temp->right!=NULL){
            printf("%d:%d,%d\n",temp->data,temp->left->data,temp->right->data);
            show(temp->left);
            show(temp->right);
        }
        else if(temp->left!=NULL&&temp->right==NULL){
            printf("%d(l):%d\n",temp->data,temp->left->data);
            show(temp->left);
            show(temp->right);
        }
        else if(temp->left==NULL&&temp->right!=NULL){
            printf("%d(r):%d\n",temp->data,temp->right->data);
            show(temp->left);
            show(temp->right);
        }
    }
}

//search() function returns the  pointer of the to-be-searched node through preorder traversal.
Ptr search(Ptr root,int val){
    Ptr temp=root;
    //int i=0;
    while(1){
        //printf("%d",i);
        //printf("\n");
        if(val==temp->data){
            return temp;
        }
        else if (val>temp->data)
        {
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
        
    }
    //printf("search() is over.\n");
    //return temp;
}
//Return the father node of the node named of son.
Ptr search_by_relation(Ptr root,Ptr son){
    Ptr temp=root;
    Ptr re=NULL;
    if(temp!=NULL){
        if(temp->left==son||temp->right==son){
            re=temp;
        }
        else{
            if(search_by_relation(temp->left,son)!=NULL){
                re=search_by_relation(temp->left,son);
            };
            if(search_by_relation(temp->right,son)!=NULL){
                re=search_by_relation(temp->right,son);
            };
        }
    }
    return re;
}
Ptr creat_Btree(Ptr root,int val){

    Ptr new_node ,temp_node,new_l_,new_r,ttemp_node;
    int k;
    new_node=(Ptr)malloc(sizeof(struct Node));
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->data=val;
    if(root ==NULL){
        return new_node;
    }
    temp_node=root;
    ttemp_node=root;
    while(temp_node){
        k=0;
        ttemp_node=temp_node;
        if (val>temp_node->data)
        {
            
            temp_node=temp_node->right;
            k=2;
        }
        else{
            
            temp_node=temp_node->left;
            k=1;
        }
    }
    if(k==2){
        
        ttemp_node->right=new_node;
    }
    else{
        
        ttemp_node->left=new_node;
    }
    return root;
}