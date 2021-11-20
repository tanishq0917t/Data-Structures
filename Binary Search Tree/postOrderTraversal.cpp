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

void postOrderIterative(BSTNode *root)
{
BSTNode *t=root;
stack<BSTNode *>s;
while(1)
{
while(t)
{
if(t->right) s.push(t->right);
s.push(t);
t=t->left;
}
t=s.top();
s.pop();
if(t->right!=NULL && t->right==s.top())
{
s.pop();
s.push(t);
t=t->right;
}
else
{
cout<<t->data<<endl;
t=NULL;
}
if(s.empty()) break;
}
}
int main()
{
insertNode(100);
insertNode(50);
insertNode(75);
insertNode(25);
insertNode(35);
insertNode(20);
insertNode(23);
insertNode(24);
insertNode(10);
insertNode(70);
insertNode(60);
insertNode(90);
insertNode(95);
insertNode(85);
insertNode(200);
insertNode(150);
insertNode(175);
insertNode(250);
insertNode(300);
cout<<"Iterative Post Order Traversal\n";
postOrderIterative(root);
return 0;
}
