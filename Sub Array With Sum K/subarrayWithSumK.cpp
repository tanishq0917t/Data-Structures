#include<bits/stdc++.h>
using namespace std;
int countSubarrays(vector<int>&v,int k)
{
    int count=0;
    int curSum=0;
    unordered_map<int,int>mp;
    for(int e=0;e<v.size();e++)
    {
        curSum+=v[e];
        if(curSum==k) count++;
        if(mp.find(curSum-k)!=mp.end()) count+=mp[curSum-k];
        mp[curSum]+=1;
    }
    return count;
}
int main()
{
    vector<int> v={3,4,7,2,-3,1,4,2};
    cout<<"Number of Subarray's with sum equals k are: "<<countSubarrays(v,7)<<endl;
    return 0;
}
