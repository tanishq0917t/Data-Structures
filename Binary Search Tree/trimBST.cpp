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
BSTNode * trimBST(BSTNode *root,int low,int high)
{
    if(!root) return root;
    if(root->data>high) return trimBST(root->left,low,high);
    if(root->data<low) return trimBST(root->right,low,high);
    root->left=trimBST(root->left,low,high);
    root->right=trimBST(root->right,low,high);
    return root;
}
vector<vector<int>> levelOrderTraversal(BSTNode *root)
{
    vector<vector<int>>ans;
    if(!root) return ans;
    queue<BSTNode *>q;
    q.push(root);
    int size;
    while(!q.empty())
    {
        size=q.size();
        vector<int>temp;
        while(size--)
        {
            BSTNode *node=q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            temp.push_back(node->data);
        }
        ans.push_back(temp);
    }
    return ans;
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
    trimBST(root,4,8);
    vector<vector<int>>v=levelOrderTraversal(root);
    for(int e=0;e<v.size();e++)
    {
        cout<<"Level: "<<e+1<<endl;
        for(int f=0;f<v[e].size();f++)
        {
            cout<<v[e][f]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
