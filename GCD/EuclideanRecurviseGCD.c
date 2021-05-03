#include<stdio.h>
int gcd(int a,int b)
{
if(a%b==0) return b;
else return gcd(b,a%b);
}
int main()
{
int a,b;
printf("Enter first number: ");
scanf("%d",&a);
printf("Enter second number: ");
scanf("%d",&b);
if(b>a)printf("GCD of %d and %d is: %d",a,b,gcd(b,a));
else printf("GCD of %d and %d is: %d",a,b,gcd(a,b));
return 0;
}