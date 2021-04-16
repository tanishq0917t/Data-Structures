#include<stdio.h>
int main()
{
int x[10],count=0;
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
for(int e=0;e<9;e++)
{
for(int f=e+1;f<10;f++)
{
if(x[e]>x[f])count++;
}
}
printf("\nNumber of inversions: %d",count);
return 0;
}
