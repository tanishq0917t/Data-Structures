#include<stdio.h>
int main()
{
int a,b,c,d;
printf("Enter first number: ");
scanf("%d",&a);
printf("Enter second number: ");
scanf("%d",&b);
while(1)
{
c=a/b;
d=a%b;
if(d==0)
{
printf("GCD is: %d",b);
break;
}
a=b;
b=d;
}
return 0;
}
