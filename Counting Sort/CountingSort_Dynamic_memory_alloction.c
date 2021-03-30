#include<stdio.h>
#include<stdlib.h>
int main()
{
int *x,n,*y;
printf("Enter requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
int largest=x[0];
for(int e=1;e<n;e++)
{
if(largest<x[e]) largest=x[e];
}
y=(int *)malloc(sizeof(int)*(largest+1));
for(int e=0;e<=largest;e++) y[e]=0;
for(int e=0;e<n;e++)
{
y[x[e]]++;
}
//for(int e=0;e<=largest;e++) printf("%d ",y[e]);
int m=0;
for(int e=0;e<=largest;e++)
{
while(y[e]--)
{
x[m]=e;
m++;
}
}
for(int e=0;e<n;e++) printf("%d\n",x[e]);
free(x);
free(y);
return 0;
}
