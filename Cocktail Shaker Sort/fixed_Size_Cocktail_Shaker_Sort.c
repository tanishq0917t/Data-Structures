#include<stdio.h>
int main()
{
int x[5];
for(int e=0;e<5;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
int flag;
int lb=0,ub=4,e,f,g;
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
if(!flag)break;
lb++;
}//outer loop ends
for(int e=0;e<5;e++)printf("%d\n",x[e]);
return 0;
}
