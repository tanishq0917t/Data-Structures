class Solution {
public:
    vector<int> helper(TreeNode *root,vector<int>&v)
    {
        if(!root) return v;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
        return v;
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int>ans;
        return helper(root,ans)[k-1];
    }
};
