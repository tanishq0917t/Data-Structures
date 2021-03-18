#include<stdio.h>
#include<stdlib.h>
// Queue work starts
typedef struct _queue_node
{
int num;
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
void addToQueue(Queue *q,int num)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->num=num;
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
int num;
num=q->start->num;
t=q->start;
q->start=q->start->next;
if(q->start==NULL) q->end=NULL;
free(t);
q->size--;
return num;
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
void radixSort(int *x,int lb,int ub)
{
int y,e,f,num,largest,dc,k,m;
Queue q[10];
for(int i=0;i<10;i++) initQueue(&q[i]); //initializing queue
largest=x[lb];
for(int i=lb+1;i<=ub;i++) if(largest<x[i]) largest=x[i]; //finding largest element
dc=1;
num=largest;
while(num>9)
{
num=num/10;
dc++;
} //counting number of digits in largest number
//printf("\n%d dc\n",dc);
e=10;
f=1;
k=1;
while(k<=dc)
{
y=lb;
while(y<=ub)
{
num=x[y];
m=(num%e)/f; //finding the m'th digit of the number
addToQueue(&q[m],num); //adding the number to m'th queue
//printf("\n%d number added\n",m);
y++;
}
m=lb;
y=0;
while(y<=9)
{
while(!isEmpty(&q[y]))
{
num=removeFromQueue(&q[y]);
x[m]=num;
m++;
}//moving element from queue to array
//printf("\n");
y++;
}
e=e*10;
f=f*10;
k++;
//for(int e=lb;e<=ub;e++) printf("%d ",x[e]);
}//finally sorted
}
int main()
{
int *x,n;
printf("Enter your requirement: ");
scanf("%d",&n);
x=(int *)malloc(sizeof(int)*n);
for(int e=0;e<n;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
int e=0,y=0,g,count=0;
while(y<n)
{
if(x[y]<0)
{
g=x[e];
x[e]=x[y];
x[y]=g;
e++;
count++;
}
y++;
}
if(count>0)
{
for(int e=0;e<count;e++)x[e]*=-1;
radixSort(x,0,count-1);
int ee=0,ff=count-1;
while(ee<ff)
{
g=x[ee];
x[ee]=x[ff];
x[ff]=g;
ee++;
ff--;
}
for(int e=0;e<count;e++)x[e]*=-1;
radixSort(x,count,n-1);
}
else 
{
radixSort(x,0,n-1);
}
for(int e=0;e<n;e++) printf("%d ",x[e]);
free(x);
return 0;
}
