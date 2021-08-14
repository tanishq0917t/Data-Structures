#include<bits/stdc++.h>
using namespace std;
void leftRotate(int *x,int s,int e)
{
for(;s<e;e--,s++)
{
swap(x[s],x[e]);
}
}
void rotateArray(int *x,int n,int k)
{
leftRotate(x,0,k-1);
leftRotate(x,k,n-1);
leftRotate(x,0,n-1);
}
int main()
{
int n;
cout<<"Enter Length of the Array: ";
cin>>n;
cout<<"Enter elements of the Array\n";
for(int e=0;e<9;e++) cin>>x[e];
cout<<"Enter Number of Left Rotations: ";
cin>>k;
rotateArray(x,n,k);
cout<<"Elements of the Array after Roations\n";
for(int e=0;e<9;e++)cout<<x[e]<<" ";
return 0;
}
