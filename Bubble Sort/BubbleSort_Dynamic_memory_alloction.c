#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,*x;
printf("Enter Requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter the number: ");
scanf("%d",&x[e]);
}
int m=n-2,e,f,g;
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
for(int e=0;e<n;e++)
{
printf("%d\n",x[e]);
}
return 0;
}
