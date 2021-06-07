#include<stdio.h>
#include<stdlib.h>
int findIndex(int *x,int lb,int ub)
{
int largest=x[lb],max=lb;
for(int i=lb+1;i<=ub;i++)
{
if(largest<x[i])
{
largest=x[i];
max=i;
}
}
return max;
}
int main()
{
int n,*x;
printf("Enter requirement:");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int i=0;i<n;i++) 
{
printf("Enter a number: ");
scanf("%d",&x[i]);
}
int index,e,f,g;
for(int i=n-1;i>=0;i--)
{
index=findIndex(x,0,i);
if(index==i) continue;
e=0;
f=index;
while(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
e++;
f--;
}
e=0;
f=i;
while(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
e++;
f--;
}
}
for(int e=0;e<n;e++) printf("%d\n",x[e]);
free(x);
return 0;
}
