#include<bits/stdc++.h>
using namespace std;
int minOperationToZero(vector<int> &v,int x)
{
int target=-x;
for(int e:v) target+=e;
if(target==0) return v.size();
map<int,int> m;
m[0]=-1;
int ans=-1,sum=0;
for(int e=0;e<v.size();e++)
{
sum+=v[e];
if(m.find(sum-target)!=m.end())
{
ans=max(ans,e-m[sum-target]);
}
m[sum]=e;
}
if(ans==-1) return -1;
return v.size()-ans;
}
int main()
{
vector<int> v={3,2,20,1,1,3};
int k=10;
cout<<minOperationToZero(v,k)<<endl;
return 0;
}

/*
min moves to reduce x to zero can be rephrased as max subarray length of sum = total-target
*/
