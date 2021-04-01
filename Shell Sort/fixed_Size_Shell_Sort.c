#include<stdio.h>
int main()
{
int x[10],z,num,size,diff,lb=0,ub=9,y;
size=(ub-lb)+1;
diff=size/2;
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
while(diff>=1)
{
y=lb+diff;
while(y<=ub)
{
num=x[y];
z=y-diff;
while(z>=0 && x[z]>num)
{
x[z+diff]=x[z];
z=z-diff;
}
x[z+diff]=num;
y+=diff;
}
diff/=2;
}
for(int e=0;e<10;e++) printf("%d\n",x[e]);
return 0;
}
