#include<stdio.h>
#include<stdlib.h>
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb])f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
int *lbStack,*ubStack,top,size,pp,lb,ub;
size=(upperBound-lowerBound)+1;
lbStack=(int *)malloc(sizeof(int)*size);
ubStack=(int *)malloc(sizeof(int)*size);
top=size;
top--;
lbStack[top]=lowerBound;
ubStack[top]=upperBound;
while(top!=size)
{
lb=lbStack[top];
ub=ubStack[top];
top++;
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub)
{
top--;
lbStack[top]=pp+1;
ubStack[top]=ub;
}
if(lb<pp-1)
{
top--;
lbStack[top]=lb;
ubStack[top]=pp-1;
}
}
free(ubStack);
free(lbStack);
}
int main()
{
int *x,req;
printf("Enter you requirement: ");
scanf("%d",&req);
x=(int *)malloc(sizeof(int)*req);
for(int e=0;e<req;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
quickSort(x,0,req-1);
for(int e=0;e<req;e++)printf("%d\n",x[e]);
return 0;
}
