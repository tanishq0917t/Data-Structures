#include<stdio.h>
int main()
{
int x[10],e=0,f,g,m=8;
for(int j=0;j<10;j++)
{
printf("Enter a number: ");
scanf("%d",&x[j]);
}
while(e<=8)
{
f=e+1;
while(f<=9)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}
for(int j=0;j<10;j++)printf("%d\n",x[j]);
return 0;
}
