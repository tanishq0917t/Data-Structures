#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k;
cin>>n;
set<int>s;
for(int e=0;e<n;e++)
{
cin>>k;
s.insert(k);
}
if(s.size()==n)cout<<"No Duplicates";
else cout<<"Duplicates exist";
return 0;
}
