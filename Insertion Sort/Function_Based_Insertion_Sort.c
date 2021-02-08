#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *ptr,int size)
{
int y=1,z,num;
while(y<size)
{
num=ptr[y];
z=y-1;
while(z>=0 && ptr[z]>num)
{
ptr[z+1]=ptr[z];
z--;
}
ptr[z+1]=num;
y++;
}
}
int main()
{
int req,*x;
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<=0) return 0;
x=(int *)malloc(sizeof(int)*req);
for(int e=0;e<req;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
insertionSort(x,req);
printf("After Sorting\n");
for(int e=0;e<req;e++) printf("%d\n",x[e]);
free(x);
return 0;
}
