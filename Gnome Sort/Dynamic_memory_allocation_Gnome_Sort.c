#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,g,*x;
printf("Enter requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
int j=0;
while(j<n)
{
if(j==0) j++;
if(x[j]>=x[j-1])j++;
else
{
g=x[j];
x[j]=x[j-1];
x[j-1]=g;
j--;
}
}
for(int e=0;e<n;e++)printf("%d\n",x[e]);
free(x);
return 0;
}
