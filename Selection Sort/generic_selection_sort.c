#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void selectionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int w,e=0,f,iep,oep,si;
iep=cs-1;
oep=cs-2;
void *a,*b,*c;
c=(void *)malloc(es);
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
a=ptr+(f*es);
b=ptr+(si*es);
w=p2f(a,b);
if(w<0)si=f;
f++;
}
a=ptr+(e*es);
b=ptr+(si*es);
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
e++;
}
free(c);
}
int myComparator(void *left,void *right)
{
int *num1,*num2;
num1=(int *)left;
num2=(int *)right;
return *num1-*num2;
}
int main()
{
int req,*x;
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
for(int y=0;y<req;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
selectionSort(x,req,sizeof(int),myComparator);
for(int y=0;y<req;y++)printf("%d\n",x[y]);
free(x);
return 0;
}
