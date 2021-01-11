#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
int rollNumber;
char name[21];
};
void bubbleSort(void *ptr,int cs,int es,int(*p2f)(void *,void *))
{
int e,f,m=cs-2,w;
void *a,*b,*c;
c=(void *)malloc(es);
while(m>=0)
{
e=0;
f=1;
while(e<=m)
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
e++;
f++;
}
m--;
}
free(c);
}
int myComparator(void *left,void *right)
{
struct Student *i,*j;
i=(struct Student *)left;
j=(struct Student *)right;
return strcmp(i->name,j->name);
}
int main()
{
int req;
printf("Enter the requirement: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement");
return 0;
}
struct Student *s;
s=(struct Student *)malloc(sizeof(struct Student)*req);
if(s==NULL)
{
printf("Unable to allocate memory");
return 0;
}
for(int e=0;e<req;e++)
{
printf("Enter the Roll Number: ");
scanf("%d",&s[e].rollNumber);
printf("Enter the Name: ");
scanf("%s",s[e].name);
}
bubbleSort(s,req,sizeof(struct Student),myComparator);
printf("After Sorting\n");
for(int e=0;e<req;e++)
{
printf("Roll-: %d      Name-: %s\n",s[e].rollNumber,s[e].name);
}
free(s);
return 0;
}
