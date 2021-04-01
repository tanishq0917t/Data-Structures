#include<stdio.h>
#include<stdlib.h>
int main()
{
int size,*x;
printf("Enter requirement: ");
scanf("%d",&size);
x=(int *)malloc(sizeof(int)*size);
int z,num,diff,lb=0,ub=size-1,y;
size=(ub-lb)+1;
diff=size/2;
for(int e=0;e<size;e++)
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
for(int e=0;e<size;e++) printf("%d\n",x[e]);
free(x);
return 0;
}
