#include<stdio.h>
int main()
{
int x[10];
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
int largest=x[0];
for(int e=1;e<10;e++)
{
if(largest<x[e]) largest=x[e];
}
int y[largest+1];
for(int e=0;e<=largest;e++) y[e]=0;
for(int e=0;e<10;e++)
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
for(int e=0;e<10;e++) printf("%d\n",x[e]);
return 0;
}
