#include<stdio.h>
#include<stdlib.h>
int main()
{
int rows,columns,**x,**y,**z;
printf("Enter number of rows: ");
scanf("%d",&rows);
printf("Enter number of columns: ");
scanf("%d",&columns);
x=(int **)malloc(sizeof(int*)*rows);
y=(int **)malloc(sizeof(int*)*rows);
z=(int **)malloc(sizeof(int*)*rows);
for(int e=0;e<rows;e++)x[e]=(int *)malloc(columns*sizeof(int));
for(int e=0;e<rows;e++)y[e]=(int *)malloc(columns*sizeof(int));
for(int e=0;e<rows;e++)z[e]=(int *)malloc(columns*sizeof(int));
printf("Enter contents for Matrix-A\n");
for(int e=0;e<rows;e++)
{
for(int j=0;j<columns;j++)
{
printf("Enter element: ");
scanf("%d",&x[e][j]);
}
}
printf("Enter contents for Matrix-B\n");
for(int e=0;e<rows;e++)
{
for(int j=0;j<columns;j++)
{
printf("Enter element: ");
scanf("%d",&y[e][j]);
}
}
for(int e=0;e<rows;e++)
{
for(int j=0;j<columns;j++)
{
z[e][j]=x[e][j]+y[e][j];
}
}
printf("Resultant Matrix-C, where C=A+B\n\n");
for(int e=0;e<rows;e++)
{
for(int j=0;j<columns;j++)
{
printf("%5d ",z[e][j]);
}
printf("\n");
}
free(x);
free(y);
free(z);
return 0;
}
