#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearSort(void *ptr,int cs,int es, int (*p2f)(void *,void *))
{
int e,f,oep,iep,w;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
for(e=0;e<=oep;e++)
{
for(f=e+1;f<=iep;f++)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
}
free(c);
}
int myComparator(void *left,void *right)
{
int *p2num1,*p2num2;
p2num1=(int *)left;
p2num2=(int *)right;
return (*p2num1)-(*p2num2);
}
int main()
{
int *x,req;
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
linearSort(x,req,sizeof(int),myComparator);
for(int y=0;y<req;y++)printf("%d\n",x[y]);
free(x);
return 0;
}
