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
int dia=INT_MIN;
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
int max_height = INT_MIN;
    int height(BSTNode* root){
        if(root==NULL){
            return 0;
        }
        
        int heightLeft=0, heightRight=0;
        if(root->left!=NULL){
            heightLeft = height(root->left);
        }
        if(root->right!=NULL){
            heightRight = height(root->right);
        }
        
        int curMax = max({heightLeft, heightRight, heightLeft+heightRight });
        max_height= max(curMax, max_height);
        return max(heightLeft, heightRight)+1;
    }
    int diameterOfBinaryTree(BSTNode* root) {
        height(root);
        return max_height;
    }
int main()
{
insertNode(100);
insertNode(50);
insertNode(25);
insertNode(90);
insertNode(75);
insertNode(200);
cout<<"Diameter of tree is: "<<diameterOfBinaryTree(root)+1<<endl;
return 0;
}
