#include<stdio.h>
int main()
{
int x[5],key,mid,lb=0,ub=4,flag=0;
for(int e=0;e<5;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
printf("Enter number to search: ");
scanf("%d",&key);
while(lb<=ub)
{
mid=lb+(ub-lb)/2;
if(key==x[mid])
{
flag=1;
break;
}
if(key<x[mid])
{
ub=mid-1;
}
else
{
lb=mid+1;
}
}
if(flag) printf("%d is present in array",key);
else printf("%d is not present in array",key);
return 0;
}
