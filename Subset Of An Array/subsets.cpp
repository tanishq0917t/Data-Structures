#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &ans,vector<int>&nums,vector<int> &temp,int i);
vector<vector<int>> getSubsets(vector<int> &num)
{
    vector<vector<int>>ans;
    vector<int>temp;
    dfs(ans,num,temp,0);
    return ans;
}
void dfs(vector<vector<int>> &ans,vector<int>&nums,vector<int> &temp,int i)
{
    if(i>=nums.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    dfs(ans,nums,temp,i+1);
    temp.pop_back();
    dfs(ans,nums,temp,i+1);
}
int main()
{
    vector<int> v={1,2,3};
    vector<vector<int>>subsets=getSubsets(v);
    sort(subsets.begin(),subsets.end());
    for(vector<int>e:subsets)
    {
        cout<<'[';
        for(int f:e)
        {
            cout<<f<<" ";
        }
        cout<<']'<<endl;
    }
    return 0;
}
