#include<bits/stdc++.h>
using namespace std;
int solve(int *w,int *v,int size,int capacity)
{
cout<<endl;
int table[size+1][capacity+1],ans=0;
for(int e=0;e<=size;e++)table[e][0]=0;
for(int e=0;e<=capacity;e++)table[0][e]=0;
for(int e=1;e<=size;e++)
{
for(int f=1;f<=capacity;f++)
{
if(f<w[e-1]) table[e][f]=table[e-1][f];
else
{
table[e][f]=max(table[e-1][f],table[e-1][f-w[e-1]]+v[e-1]);
}
}
}
for(int e=0;e<=size;e++)
{
for(int f=0;f<=capacity;f++)
{
printf("%5d ",table[e][f]);
}
cout<<"\n";
}
return table[size][capacity];
}
int main()
{
int n;
cin>>n;
int x[n],y[n];
for(int e=0;e<n;e++)cin>>x[e];
for(int e=0;e<n;e++)cin>>y[e];
int cap;
cin>>cap;
cout<<"Maximum weight that be taken in a bag of Capacity "<<cap<<" is: "<<solve(x,y,n,cap);
return 0;
}
