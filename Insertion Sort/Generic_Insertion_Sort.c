#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int y=1,z;
void *block;
block=(void *)malloc(es);
while(y<cs)
{
//num=ptr[y];
memcpy(block,(void *)(ptr+(y*es)),es);
z=y-1;
//while(z>=0 && ptr[z]>num)
while(z>=0 && p2f(ptr+(z*es),block)>0)
{
//ptr[z+1]=ptr[z];
memcpy(ptr+((z+1)*es),(const void *)(ptr+(z*es)),es);
z--;
}
//ptr[z+1]=num;
memcpy(ptr+((z+1)*es),(const void *)block,es);
y++;
}
}
int myComparator(void *left,void *right)
{
int *a=(int *)left,*b=(int *)right;
return *a-*b;
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
insertionSort(x,req,sizeof(int),myComparator);
printf("After Sorting\n");
for(int e=0;e<req;e++) printf("%d\n",x[e]);
free(x);
return 0;
}
