#include<stdio.h>
#include<stdlib.h>
char * containsDuplicate(int *x,int n)
{
for(int e=0;e<n;e++)
{
for(int f=e+1;f<n;f++)
{
if(x[e]==x[f]) return "YES";
}
}
return "NO";
}
int main()
{
int n;
printf("Enter Size: ");
scanf("%d",&n);
int *x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
printf("Is there any duplicacy in array: %s",containsDuplicate(x,n));
free(x);
return 0;
}
