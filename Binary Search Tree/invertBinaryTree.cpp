#include<bits/stdc++.h>
using namespace std;
typedef struct _bstNode
{
int data;
struct _bstNode *left;
struct _bstNode *right;
}BSTNode;
BSTNode *root=NULL;
BSTNode * createNode()
{
BSTNode *t;
t=(BSTNode *)malloc(sizeof(BSTNode));
t->left=NULL;
t->right=NULL;
return t;
}

void insertNode(int data)
{
BSTNode *t,*j;
t=createNode();
t->data=data;
if(!root){root=t;return;}
j=root;
while(1)
{
if(t->data>j->data) //right case
{
if(j->right==NULL) //adding node to end
{
j->right=t;
break;
}
else
{
j=j->right;  //iterating over right node
}
}
else  //left case
{
if(j->left==NULL) //adding node to end
{
j->left=t;
break;
}
else  //iterating over left node
{
j=j->left;
}
}
}
}

void inorder(BSTNode *root)
{
if(root==NULL) return;
inorder(root->left);
cout<<root->data<<endl;
inorder(root->right);
}
void invertTree(BSTNode *root)
{
/*
Step-1: At every step we will check that the current node is NULL or not if null then destroy that copy
Step-2: After checking simply we will swap the addresses of the right child and left child to invert
Step-3: After swapping we will call the function recursively for current node's left child and right child
*/
if(!root) return;
swap(root->left,root->right);
invertTree(root->left);
invertTree(root->right);
}
int main()
{
insertNode(100);
insertNode(50);
insertNode(75);
insertNode(25);
insertNode(60);
insertNode(200);
insertNode(150);
insertNode(175);
cout<<"Inorder before inverting\n";
inorder(root);
invertTree(root);
cout<<"Inorder after inverting\n";
inorder(root);
return 0;
}
