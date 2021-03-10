#include<stdio.h>
#include<stdlib.h>
void merge(int *x,int lb,int mid,int ub)
{
int i1,i2,i3,tmpsize,lb1,lb2,ub1,ub2,lb3,ub3;
tmpsize=ub-lb+1;
int *tmp;
tmp=(int *)malloc(sizeof(int)*tmpsize);
lb1=lb;
ub1=mid;
lb2=mid+1;
ub2=ub;
lb3=0;
ub3=tmpsize-1;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
i3++;
}
else
{
tmp[i3]=x[i2];
i2++;
i3++;
}
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i3++;
i1++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i1++;
}
i3=0;
i1=lb1;
while(i1<=ub2)
{
x[i1]=tmp[i3];
i3++;
i1++;
}
free(tmp);
}
void mergeSort(int *x,int lb,int ub)
{
if(lb<ub)
{
int mid=(lb+ub)/2;
mergeSort(x,lb,mid);
mergeSort(x,mid+1,ub);
merge(x,lb,mid,ub);
}
}
int main()
{
int *x,n;
printf("Enter Requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter number: ");
scanf("%d",&x[e]);
}
mergeSort(x,0,n-1);
printf("After Sorting\n");
for(int e=0;e<n;e++)printf("%d\n",x[e]);
free(x);
return 0;
}
