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
BSTNode * mergeBSTs(BSTNode *root1,BSTNode *root2)
{
/*
Step-1: Check if root1 is null, if is null then return root2 (if root2 is also null then null will returned)
Step-2: same as step1 check is for root2
Step-3: If we are at this step that means we are not at leaf node in both BST, so we will add 2nd Tree's value of 1st Tree's Node
Step-4: After adding value of current node, we will move on to left node for addition, that will open a new copy and checks will be 
        performed if not null then values will be added
Step-5: Same as step4, this step is for right node
Step-6: Return Root of 1st Tree
*/
if(root1==NULL) return root2;
if(root2==NULL) return root1;
root1->data+=root2->data;
root1->left=mergeBSTs(root1->left,root2->left);
root1->right=mergeBSTs(root1->right,root2->right);
return root1;
}
int main()
{
BSTNode *root1=NULL;
BSTNode *root2=NULL;
cout<<"Inorder of Tree 1\n";
root1=insertNode(10,root1);
root1=insertNode(5,root1);
root1=insertNode(15,root1);
root1=insertNode(12,root1);
inorder(root1);
cout<<"Inorder of Tree 2\n";
root2=insertNode(50,root2);
root2=insertNode(100,root2);
root2=insertNode(200,root2);
root2=insertNode(35,root2);
root2=insertNode(40,root2);
inorder(root2);
cout<<"Inorder of Merged Tree 1 and 2\n";
BSTNode *root3=mergeBSTs(root1,root2);
//cout<<root3<<endl;
inorder(root3);
cout<<endl;
return 0;
}
