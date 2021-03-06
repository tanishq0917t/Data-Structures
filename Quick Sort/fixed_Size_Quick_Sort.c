#include<stdio.h>
int main()
{
int x[10],e,f,g,pp,ub,lb,stk[10][2],lowerBound=0,upperBound=9,top=10;
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
top--;
stk[top][0]=lowerBound;
stk[top][1]=upperBound;
while(top!=10)
{
lb=stk[top][0];
ub=stk[top][1];
top++;
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
pp=f;
if(pp+1<ub)
{
top--;
stk[top][0]=pp+1;
stk[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stk[top][0]=lb;
stk[top][1]=pp-1;
}
}
for(int e=0;e<10;e++)printf("%d\n",x[e]);
return 0;
}
