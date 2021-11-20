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
else //left case
{
if(j->left==NULL) //adding node to end
{
j->left=t;
break;
}
else //iterating over left node
{
j=j->left;
}
}
}
}

void levelOrderTraversal(BSTNode *root)
{
BSTNode *t;
queue<BSTNode *> q;
if(root) q.push(root);
while(!q.empty())
{
t=q.front();
cout<<t->data<<endl;
q.pop();
if(t->left) q.push(t->left);
if(t->right) q.push(t->right);
}
}

void search(BSTNode* &cur, int item, BSTNode* &parent)
{
while(cur != NULL && cur->data != item)
{
parent = cur;
if(item < cur->data) cur = cur->left;
else
cur = cur->right;
}
}

BSTNode* findMinimum(BSTNode* cur)
{
while(cur->left != NULL)
{
cur = cur->left;
}
return cur;
}

void deleteNode(BSTNode*& root, int item)
{
BSTNode* parent = NULL;
BSTNode* cur = root;
search(cur, item, parent);
if(cur == NULL) return;
if(cur->left == NULL && cur->right == NULL) //node has no child
{
if(cur != root)
{
if(parent->left == cur) parent->left = NULL;
else
parent->right = NULL;
}
else root = NULL;
free(cur);
}
else if(cur->left && cur->right) //node has 2 childs
{
BSTNode* succ = findMinimum(cur->right);
int val = succ->data;
deleteNode(root, succ->data);
cur->data = val;
}
else //node has 1 child
{
BSTNode* child;
if(cur->left) child=cur->left;
else child=cur->right;
if(cur != root)
{
if(cur == parent->left) parent->left = child;
else parent->right = child;
}
else root = child;
free(cur);
}
}
int main()
{
insertNode(100);
insertNode(150);
insertNode(200);
insertNode(125);
insertNode(75);
insertNode(95);
insertNode(93);
insertNode(98);
insertNode(60);
levelOrderTraversal(root);
cout<<endl;
deleteNode(root,75);
levelOrderTraversal(root);
return 0;
}
