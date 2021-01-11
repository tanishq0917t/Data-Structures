#include<stdio.h>
int main()
{
int x[5],e,f,g,m=3;
for(int e=0;e<5;e++)
{
printf("Enter the number: ");
scanf("%d",&x[e]);
}
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
m--;
}
printf("After Sorting\n");
for(int e=0;e<5;e++)
{
printf("%d\n",x[e]);
}
return 0;
}
