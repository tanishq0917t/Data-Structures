#include<bits/stdc++.h>
using namespace std;
typedef struct _node
{
struct _node *left,*right;
int data;
}Node;
Node *root=NULL;
void add(int data)
{
Node *node=(Node *)malloc(sizeof(Node));
node->left=NULL;
node->right=NULL;
node->data=data;
Node *head=root;
//cout<<node->data<<endl;
if(root==NULL) root=node;
else
{
while(1)
{
if(head->data > data)
{
if(head->left) head=head->left;
else {head->left=node;break;}
}
else
{
if(head->right) head=head->right;
else {head->right=node;break;}
}
}
}
}
void help(Node *root,map<int,Node *> &mp,int pos)
{
if(!root) return;
mp[pos]=root;
if(root->left) help(root->left,mp,pos-1);
if(root->right) help(root->right,mp,pos+1);
}
void printBottom(Node *root)
{
map<int,Node *> mp;
if(!root) return;
help(root,mp,0);
for(auto it:mp) cout<<it.first<<" "<<it.second->data<<endl;
}

int main()
{
add(5);
add(3);
add(12);
add(2);
add(1);
add(8);
add(16);

printBottom(root);
return 0;
}
