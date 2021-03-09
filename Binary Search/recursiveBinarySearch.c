#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr,int lb,int ub,int key)
{
if(lb<=ub)
{
int mid=(lb+ub)/2;
if(arr[mid]==key) return mid;
if(arr[mid]>key) return binarySearch(arr,lb,mid-1,key);
if(arr[mid]<key) return binarySearch(arr,mid+1,ub,key);
}
return -1;
}
int main()
{
int *x,n,key;
printf("Enter your requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
printf("Enter the number to search: ");
scanf("%d",&key);
int k=binarySearch(x,0,n,key);
if(k!=-1) printf("%d is present is the array at %d index\n",key,k);
else printf("%d is not present in the array\n",key);
free(x);
return 0;
}
