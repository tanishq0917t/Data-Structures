#include<stdio.h>
#include<stdlib.h>
typedef struct __stack_node
{
int data;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int size;
}Stack;
void initStack(Stack *stack)
{
stack->top=NULL;
stack->size=0;
}
void push(Stack *stack,int data)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=data;
t->next=stack->top;
stack->top=t;
stack->size++;
}
int pop(Stack *stack)
{
int data;
StackNode *t;
data=stack->top->data;
t=stack->top;
stack->top=stack->top->next;
free(t);
stack->size--;
return data;
}
int isEmpty(Stack *stack)
{
return stack->size==0;
}
int main()
{
int x[10],tmp;
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
int largest=x[0],smallest=x[0];
for(int e=1;e<10;e++)
{
if(smallest>x[e]) smallest=x[e];
if(largest<x[e]) largest=x[e];
}
//printf("%d %d",smallest,largest);
int range=(largest-smallest)+1;
Stack stk[range];
for(int e=0;e<range;e++) initStack(&stk[e]);
for(int e=0;e<10;e++)
{
tmp=x[e]-smallest;
push(&stk[tmp],x[e]);
}
int m=0;
for(int e=0;e<range;e++)
{
while(!isEmpty(&stk[e]))
{
x[m]=pop(&stk[e]);
m++;
}
}
for(int e=0;e<10;e++) printf("%d\n",x[e]);
return 0;
}
