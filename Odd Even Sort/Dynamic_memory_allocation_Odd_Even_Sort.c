#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,*x;
printf("Enter requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
int g,e,f,flag,ub=n-1;
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
while(1)
{
flag=0;
e=1;
f=e+1;
while(e!=ub-1)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
flag=1;
}
e++;
f++;
}
e=0;
f=e+1;
while(e!=ub)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
flag=1;
}
e++;
f++;
}
if(!flag) break;
}
for(int e=0;e<n;e++) printf("%d\n",x[e]);
free(x);
return 0;
}
