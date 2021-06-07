#include<stdio.h>
int main()
{
int x[10],e=0,f,m,g,si;
for(int j=0;j<10;j++)
{
printf("Enter a number: ");
scanf("%d",&x[j]);
}
while(e<=8)
{
si=e;
f=e+1;
while(f<=9)
{
if(x[f]<x[si]) si=f;
f++;
}
g=x[si];
x[si]=x[e];
x[e]=g;
e++;
}
for(int j=0;j<10;j++)printf("%d\n",x[j]);
return 0;
}
