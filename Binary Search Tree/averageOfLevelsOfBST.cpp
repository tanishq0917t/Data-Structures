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
vector<vector<int>> levelOrderTraversal(BSTNode *root)
{
    vector<vector<int>> ans;
    if (!root) return ans;
    queue<BSTNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> tmp;
        while (size--)
        {
            BSTNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            tmp.push_back(node->data);
        }
        ans.push_back(tmp);
    }
    return ans;
}
vector<double> averageOfLevels(BSTNode *root)
{
    vector<vector<int>> v = levelOrderTraversal(root);
    vector<double> ans;
    for (vector<int> a : v)
    {
        ans.push_back(accumulate(a.begin(), a.end(), 0.0) / a.size());
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
    vector<double>average=averageOfLevels(root);
    for(double a:average)
    {
        cout<<a<<" ";
    }
    return 0;
}
