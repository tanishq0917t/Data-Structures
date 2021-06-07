#include<stdio.h>
#include<stdlib.h>
int main()
{
int *x,n;
printf("Enter you requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
int e=0,f,m,g,si;
for(int j=0;j<n;j++)
{
printf("Enter a number: ");
scanf("%d",&x[j]);
}
while(e<=n-2)
{
si=e;
f=e+1;
while(f<=n-1)
{
if(x[f]<x[si]) si=f;
f++;
}
g=x[si];
x[si]=x[e];
x[e]=g;
e++;
}
for(int j=0;j<n;j++)printf("%d\n",x[j]);
free(x);
return 0;
}
