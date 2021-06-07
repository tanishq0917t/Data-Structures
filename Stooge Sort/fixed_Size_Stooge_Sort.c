#include<stdio.h>
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
int x[5];
for(int e=0;e<5;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
stoogeSort(x,0,4);
for(int e=0;e<5;e++) printf("%d\n",x[e]);
return 0;
}
