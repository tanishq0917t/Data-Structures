#include<stdio.h>
int main()
{
int x[10],stack1[10][2],stack2[10][2],tmp[10];
int lb1,lb2,lb3,ub1,ub2,ub3;
int i1,i2,i3;
int a,b;
int mid;
int top1=10,top2=10;
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
top1--;
stack1[top1][0]=0;
stack1[top1][1]=9;
while(top1!=10)
{
a=stack1[top1][0];
b=stack1[top1][1];
top1++;
top2--;
stack2[top2][0]=a;
stack2[top2][1]=b;
mid=(a+b)/2;
if(a<mid)
{
top1--;
stack1[top1][0]=a;
stack1[top1][1]=mid;
}
if(mid+1<b)
{
top1--;
stack1[top1][0]=mid+1;
stack1[top1][1]=b;
}
}
while(top2!=10)
{
lb1=stack2[top2][0];
ub2=stack2[top2][1];
top2++;
ub1=(lb1+ub2)/2;
lb2=ub1+1;
lb3=lb1;
ub3=ub2;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i3=lb1;
while(i3<=ub3)
{
x[i3]=tmp[i3];
i3++;
}
}
for(int e=0;e<10;e++)printf("%d\n",x[e]);
return 0;
}
