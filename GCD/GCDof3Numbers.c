#include<stdio.h>
int gcd(int a, int b)
{
if(a==0) return b;
if(b==0) return a;
return gcd(b,a%b);
}
int main()
{
int a,b,c;
printf("Enter first number: ");
scanf("%d",&a);
printf("Enter second number: ");
scanf("%d",&b);
printf("Enter third number: ");
scanf("%d",&c);
printf("GCD of %d, %d and %d is: %d",a,b,c,gcd(gcd(a,b),c));
return 0;
}