#include<stdio.h>
#include<stdlib.h>
int main()
{
int n;
printf("Enter requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
int y=1,num,z;
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
while(y<n)
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
for(int e=0;e<n;e++) printf("%d\n",x[e]);
free(x);
return 0;
}
