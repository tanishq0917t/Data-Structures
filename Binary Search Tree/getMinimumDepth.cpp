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
int getMinimumDepth(BSTNode *root)
{
int leftDepth,rightDepth;
if(!root) return 0;
if(root->left==NULL && root->right==NULL) return 1;
if(root->left) leftDepth=getMinimumDepth(root->left);
if(root->right) rightDepth=getMinimumDepth(root->right);
return min(leftDepth,rightDepth)+1;
}
int main()
{
insertNode(100);
insertNode(50);
insertNode(75);
insertNode(25);
insertNode(60);
insertNode(10);
insertNode(4);
insertNode(150);
insertNode(200);
insertNode(125);
insertNode(110);
insertNode(200);
insertNode(250);
insertNode(170);
cout<<"Recursive Inorder Traversal\n";
inorder(root);
cout<<"Minimum Depth of Tree is: "<<getMinimumDepth(root)<<endl;
return 0;
}
