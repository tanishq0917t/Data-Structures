#include<stdio.h>
#include<stdlib.h>
int kthSmallest(int *x,int size,int k)
{
int y=0,z,num;
while(y<size)
{
num=x[y];
z=y-1;
while(z>=0 && x[z]>num)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
y++;
}
return x[k-1];
}
int main()
{
int n,*x,k;
printf("Enter your requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
printf("Enter the value of k for finding Kth Smallest Number: ");
scanf("%d",&k);
printf("Kth(%d) Smallest number is: %d",k,kthSmallest(x,n,k));
free(x);
return 0;
}
