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
// Queue work ends
int main()
{
int x[10],y,e,f,num,largest,dc,k,m;
Queue q[10];
for(int i=0;i<10;i++) initQueue(&q[i]); //initializing queue
for(int i=0;i<10;i++)
{
printf("Enter a number: ");
scanf("%d",&x[i]);
}
largest=x[0];
for(int i=1;i<10;i++) if(largest<x[i]) largest=x[i]; //finding largest element
dc=1;
num=largest;
while(num>9)
{
num=num/10;
dc++;
} //counting number of digits in largest number
e=10;
f=1;
k=1;
while(k<=dc)
{
y=0;
while(y<=9)
{
num=x[y];
m=(num%e)/f; //finding the m'th digit of the number
addToQueue(&q[m],num); //adding the number to m'th queue
y++;
}
m=0;
y=0;
while(y<=9)
{
while(!isEmpty(&q[y]))
{
num=removeFromQueue(&q[y]);
x[m]=num;
m++;
}//moving element from queue to array
y++;
}
e=e*10;
f=f*10;
k++;
}//finally sorted
for(int a=0;a<10;a++) printf("%d\n",x[a]);
return 0;
}
