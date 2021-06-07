#include<stdio.h>
int main()
{
int x[10],g,e,f,flag,size=10;
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
while(1)
{
flag=0;
e=1;
f=e+1;
while(e!=size-1)
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
while(e!=size)
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
for(int e=0;e<10;e++) printf("%d\n",x[e]);
return 0;
}
