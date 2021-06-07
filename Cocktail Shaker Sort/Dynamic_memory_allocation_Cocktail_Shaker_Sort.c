#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,*x;
printf("Enter your requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
int flag;
int lb=0,ub=n-1,e,f,g;
while(flag)
{
//printf("Start of outer loop\n");
int flag=0;
e=lb;
f=e+1;
//printf("Start of inner loop 1\n");
while(e<ub)
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
if(!flag)break;
//printf("End of inner loop 1\n");
ub--;
e=ub-1;
f=ub;
//printf("Start of inner loop 2\n");
while(e>=0)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
flag=1;
}
e--;
f--;
}
//printf("End of inner loop 2\n");
lb++;
if(!flag)break;
}//outer loop ends
for(int e=0;e<n;e++)printf("%d\n",x[e]);
free(x);
return 0;
}
