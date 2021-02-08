#include<stdio.h>
int main()
{
int x[5],y=1,num,z;
for(int e=0;e<5;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
while(y<5)
{
num=x[y];
z=y-1;
while(z>=0 && x[z]>num)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
y++;
}
for(int e=0;e<5;e++) printf("%d\n",x[e]);
return 0;
}
