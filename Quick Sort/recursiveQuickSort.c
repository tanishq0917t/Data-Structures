#include<stdio.h>
#include<stdlib.h>
//function to find the partition index
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(x[e]<=x[lb] && e<f) e++;
while(x[f]>x[lb])f--;
if(e<f) //swapping data at e'th and f'th index
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else //swapping data at lb'th and f'th index // or we can say that moving pivot element to its correct position in the sorted array
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f; // returning the partition index now two parts of array will be processed ie (lb,f-1) and (f+1,ub)
}
void quickSort(int *x,int lb,int ub)
{
if(lb<=ub)
{
int pp=findPartitionPoint(x,lb,ub);
quickSort(x,lb,pp-1); //recursively calling the quickSort function for the 1st partition of array
quickSort(x,pp+1,ub); //recursively calling the quickSort function for the 2nd partition of array
}
}
int main()
{
int *x, n;
printf("Enter your requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n); //dynamic memory allocation as required
for(int e=0;e<n;e++) //input of the data for the array
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
quickSort(x,0,n-1); //calling the quickSort function for the array
printf("After Sorting\n");
for(int e=0;e<n;e++)printf("%d ",x[e]); //traversing on the sorted array 
free(x); //releasing the allocated memory for the array
return 0;
}
