#include<stdio.h>
#include<stdlib.h>
// Queue work starts
typedef struct _queue_node
{
int data;
struct _queue_node *next;
}QueueNode;
typedef struct _queue
{
QueueNode *start;
QueueNode *end;
int size;
}Queue;
void initQueue(Queue *q)
{
q->start=NULL;
q->end=NULL;
q->size=0;
}
int isEmpty(Queue *q)
{
return q->size==0;
}
void addToQueue(Queue *q,int data)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->data=data;
t->next=NULL;
if(q->start==NULL)
{
q->start=t;
q->end=t;
}
else
{
q->end->next=t;
q->end=t;
}
q->size++;
}
int removeFromQueue(Queue *q)
{
QueueNode *t;
int data;
data=q->start->data;
t=q->start;
q->start=q->start->next;
if(q->start==NULL) q->end=NULL;
free(t);
q->size--;
return data;
}
void clearQueue(Queue *queue)
{
QueueNode *t;
while(queue->start!=NULL)
{
t=queue->start;
queue->start=queue->start->next;
queue->size--;
free(t);
}
queue->end=NULL;
queue->size=0;
}
int size(Queue *queue)
{
return queue->size;
}


void sort(Queue *q,int lb,int ub)
{
int len=size(q);
int x[len],y=0,z,num;
for(int e=0;e<len;e++) x[e]=removeFromQueue(q);
while(y<len)
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
for(int e=0;e<len;e++)addToQueue(q,x[e]);
}
int hashFunction(int num,int dc)
{
int e;
e=1;
for(int i=0;i<dc-1;i++)
{
e*=10;
}
num=(num/e)%10;
return num;
}
int main()
{
int n,*x;
printf("Enter requirement:");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int i=0;i<n;i++) 
{
scanf("%d",&x[i]);
}
int max=x[0],e,f,g;
for(int i=1;i<n;i++) if(max<x[i]) max=x[i];
int dc=0;
while(max!=0)
{
dc++;
max/=10;
}
Queue queue[10];
for(int i=0;i<10;i++) initQueue(&queue[i]);
int num;
for(int i=0;i<n;i++)
{
num=hashFunction(x[i],dc);
addToQueue(&queue[num],x[i]);
if(size(&queue[num])>1) sort(&queue[num],0,size(&queue[num]));
}
int t;
t=0;
for(int i=0;i<10;i++)
{
while(size(&queue[i])>0)
{
x[t]=removeFromQueue(&queue[i]);
t++;
}
}
for(int i=0;i<n;i++) printf("\n%d ",x[i]);
free(x);
return 0;
}
