#include<stdio.h>
int main()
{
int x[10],g;
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
int j=0;
while(j<=9)
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
for(int e=0;e<10;e++)printf("%d\n",x[e]);
return 0;
}
