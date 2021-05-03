#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b)
{
if(a==0) return b;
if(b==0) return a;
return gcd(b,a%b);
}
int main()
{
int n,*x;
printf("Enter your requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
int hcf=x[0];
for(int e=1;e<n;e++)
{
hcf=gcd(x[e],hcf);
}
printf("GCD is: %d",hcf);
free(x);
return 0;
}