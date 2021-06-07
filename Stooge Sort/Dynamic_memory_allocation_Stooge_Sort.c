#include<stdio.h>
#include<stdlib.h>
void stoogeSort(int *x,int lb,int ub)
{
if(lb>=ub) return;
int g,size=(ub-lb)+1;
if(x[lb]>x[ub])
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
int l=(size)/3;
if(size<=2) return;
stoogeSort(x,lb,ub-l);
stoogeSort(x,lb+l,ub);
stoogeSort(x,lb,ub-l);
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
stoogeSort(x,0,n-1);
for(int e=0;e<n;e++) printf("%d\n",x[e]);
free(x);
return 0;
}
