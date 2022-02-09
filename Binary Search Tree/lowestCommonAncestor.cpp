#include <bits/stdc++.h>
using namespace std;
typedef struct _bstNode
{
    int data;
    struct _bstNode *left;
    struct _bstNode *right;
} BSTNode;
BSTNode *root = NULL;
BSTNode *createNode()
{
    BSTNode *t;
    t = (BSTNode *)malloc(sizeof(BSTNode));
    t->left = NULL;
    t->right = NULL;
    return t;
}

void insertNode(int data)
{
    BSTNode *t, *j;
    t = createNode();
    t->data = data;
    if (!root)
    {
        root = t;
        return;
    }
    j = root;
    while (1)
    {
        if (t->data > j->data) // right case
        {
            if (j->right == NULL) // adding node to end
            {
                j->right = t;
                break;
            }
            else
            {
                j = j->right; // iterating over right node
            }
        }
        else // left case
        {
            if (j->left == NULL) // adding node to end
            {
                j->left = t;
                break;
            }
            else // iterating over left node
            {
                j = j->left;
            }
        }
    }
}
BSTNode * lowestCommonAncestor(BSTNode *root,int a,int b)
{
    if(!root) return root;
    if(root->data<a && root->data<b) return lowestCommonAncestor(root->right,a,b);
    if(root->data>a && root->data>b) return lowestCommonAncestor(root->left,a,b);
    return root;
}
int main()
{
    insertNode(5);
    insertNode(3);
    insertNode(4);
    insertNode(6);
    insertNode(2);
    insertNode(1);
    insertNode(7);
    insertNode(9);
    insertNode(8);
    insertNode(0);
    insertNode(-1);
    cout<<"Lowest Common Ancestor of 4 and 2 is: "<<lowestCommonAncestor(root,4,2)->data<<endl;
    return 0;
}
