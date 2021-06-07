#include<stdio.h>
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
int x[10];
for(int i=0;i<10;i++) 
{
printf("Enter a number: ");
scanf("%d",&x[i]);
}
int index,e,f,g;
for(int i=9;i>=0;i--)
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
for(int e=0;e<10;e++) printf("%d\n",x[e]);
return 0;
}
