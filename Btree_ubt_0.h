#ifndef BTREE0_H
#define BTREE0_H

struct Node{
    struct Node * left;
    struct Node * right;
    int data;
};
typedef struct Node* Ptr;


//二叉树创建函数的声明
struct Node* creat_Btree(struct Node* root,int val);
//search() function returns the  
// pointer of the to-be-searched node 
// through preorder traversal.
Ptr search(Ptr root,int val);
Ptr search_by_relation(Ptr root,Ptr son);
void show(Ptr);

#endif