#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int *x,int size)
{
int m=size-2,e,f,g;
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
}
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
bubbleSort(x,n);
printf("After Sorting\n");
for(int e=0;e<5;e++)
{
printf("%d\n",x[e]);
}
return 0;
}
