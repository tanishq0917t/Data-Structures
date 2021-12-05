#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int x[n];
for(int e=0;e<n;e++) cin>>x[e];
int k;
cin>>k;
priority_queue<int>pq;
for(int e=0;e<k;e++) pq.push(x[e]);
for(int e=k;e<n;e++)
{
if(pq.top()>x[e])
{
pq.pop();
pq.push(x[e]);
}
}
for(int e=0;e<n;e++) cout<<x[e]<<" ";
cout<<"\nKth smallest element for k="<<k<<" is: "<<pq.top()<<endl;
return 0;
}
