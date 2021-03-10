#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct __stack_node
{
void *ptr;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int elementSize;
int size;
}Stack;
void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->elementSize=elementSize;
stack->size=0;
}
int push(Stack *stack,void *ptr)
{
StackNode *node;
if(stack==NULL)return 0;
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL)return 0;
if(ptr!=NULL)
{
node->ptr=(void *)malloc(stack->elementSize);
if(node->ptr==NULL)
{
free(node);
return 0;
}
memcpy(node->ptr,(const void *)ptr,stack->elementSize);
}
else
{
node->ptr=ptr;
}
node->next=stack->top;
stack->top=node;
stack->size++;
return 1;
}//push ends
int pop(Stack *stack,void *ptr)
{
int j;
StackNode *node;
if(stack==NULL)return 0;
if(stack->top=NULL) return 0;
if(stack->top->ptr==NULL)
{
for(j=0;j<stack->elementSize;j++)
{
*((char *)(ptr+j))=(char)0;
}
}
else
{
memcpy(ptr,(const void *)stack->top->ptr,stack->elementSize);
}
node=stack->top;
stack->top=stack->top->next;
if(node->ptr!=NULL) free(node->ptr);
free(node);
stack->size--;
return 1;
}//pop ends
int isEmpty(Stack *stack)
{
if(stack==NULL)return 1;
if(stack->size==0)return 1;
return 0;
}
void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
int size1,size2,size3;
int *tmp;
int i1,i2,i3;
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=size1+size2;
tmp=(int *)malloc(sizeof(int)*size3);
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
x[i1]=tmp[i3];
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
x[i2]=tmp[i3];
i2++;
i3++;
}
free(tmp);
}//merge ends
void mergeSort(int *x,int lowerBound,int upperBound)
{
struct LBUB
{
int lb,ub;
};
struct LBUB lbub;
int a,b,mid;
Stack stack1,stack2;
initStack(&stack1,sizeof(struct LBUB));
initStack(&stack2,sizeof(struct LBUB));
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,(void *)&lbub);
while(!isEmpty(&stack1))
{
pop(&stack1,(void *)&lbub);
push(&stack2,(void *)&lbub);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub);
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void *)&lbub);
}
}
while(!isEmpty(&stack2))
{
pop(&stack2,(void *)&lbub);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,a,mid,mid+1,b);
}
}//mergeSort ends
int main()
{
int x[10];
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
mergeSort(x,0,9);
for(int e=0;e<10;e++)printf("%d\n",x[e]);
return 0;
}
