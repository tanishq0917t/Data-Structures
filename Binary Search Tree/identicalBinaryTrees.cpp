#include<bits/stdc++.h>
using namespace std;
typedef struct _bstNode
{
int data;
struct _bstNode *left;
struct _bstNode *right;
}BSTNode;

BSTNode * createNode()
{
BSTNode *t;
t=(BSTNode *)malloc(sizeof(BSTNode));
t->left=NULL;
t->right=NULL;
return t;
}

BSTNode * insertNode(int data,BSTNode *root)
{
//cout<<"Insert got called\n";
BSTNode *t,*j;
t=createNode();
t->data=data;
if(!root){root=t;return root;}
j=root;
while(1)
{
if(t->data>j->data) //right case
{
if(j->right==NULL) //adding node to end
{
j->right=t;
return root;
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
return root;
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
//cout<<"I got called\n";
if(root==NULL) return;
inorder(root->left);
cout<<root->data<<endl;
inorder(root->right);
}
bool identicalTrees(BSTNode *root1,BSTNode *root2)
{
/*
Step-1: If both nodes are NULL that means we are at leaf nodes of both tree then it is identical node
Step-2: If one node is NULL and another is not NULL then both trees are not identical
Step-3: If both nodes are NOT NULL then compare data, if doesn't match then, both trees are not identical
Step-4: Call function recursively for current node's left child and right for checking identical nodes
*/
if(!root1 && !root2) return true;
if(!root1 || !root2) return false;
if(root1->data != root2->data) return false;
return identicalTrees(root1->left,root2->left) && identicalTrees(root1->right,root2->right);
}
int main()
{
BSTNode *root1=NULL;
BSTNode *root2=NULL;
cout<<"Inorder of Tree 1\n";
root1=insertNode(10,root1);
root1=insertNode(15,root1);
root1=insertNode(5,root1);
root1=insertNode(20,root1);
inorder(root1);
cout<<"Inorder of Tree 2\n";
root2=insertNode(10,root2);
root2=insertNode(15,root2);
root2=insertNode(5,root2);
root2=insertNode(20,root2);
inorder(root2);
if(identicalTrees(root1,root2))cout<<"Both trees are identical\n";
else cout<<"Both trees are not identical\n";
return 0;
}
