#include<bits/stdc++.h>
using namespace std;
typedef struct _node
{
int data;
struct _node *next;
}Node;
Node *start=NULL;
//********************* Add at End *********************
void addAtEnd()
{
printf("\n");
int data;
printf("Enter Data: ");
scanf("%d",&data);
Node *t,*j;
t=(Node *)malloc(sizeof(Node));
t->next=NULL;
t->data=data;
if(start==NULL)start=t;
else
{
j=start;
while(j->next!=NULL)j=j->next;
j->next=t;
}
printf("%d: Added to end of list\n",data);
printf("\n");
}
//********************* Add at Top *********************
void addAtTop()
{
printf("\n");
int data;
printf("Enter Data: ");
scanf("%d",&data);
Node *t;
t=(Node *)malloc(sizeof(Node));
t->data=data;
t->next=start;
start=t;
printf("%d: Added to top of list\n",data);
printf("\n");
}
//********************* Add at Position *********************
void addAtPosition()
{
printf("\n");
int data,pos,x=1;
Node *p1,*p2,*t;
printf("Enter Data: ");
scanf("%d",&data);
printf("Enter Position: ");
scanf("%d",&pos);
if(pos<0)pos=0;
t=(Node *)malloc(sizeof(Node));
t->data=data;
t->next=NULL;
if(start==NULL)
{
start=t;
return;
}
for(p1=start,x=1;p1!=NULL && x<=pos;x++)
{
p2=p1;
p1=p1->next;
}
if(p1==NULL)
{
p2->next=t;
return;
}
if(p1==start)
{
t->next=start;
start=t;
return;
}
t->next=p1;
p2->next=t;
printf("%d: Added to %d position of list\n",data,pos);
printf("\n");
}
//********************* Remove From End *********************
void removeFromEnd()
{
Node *p1,*p2;
p1=start;
if(start==NULL)return;
while(p1->next!=NULL)
{
p2=p1;
p1=p1->next;
}
printf("%d: Removed from end of the list\n",p1->data);
p2->next=NULL;
free(p1);
printf("\n");
}
//********************* Remove From Top *********************
void removeFromTop()
{
printf("\n");
if(start==NULL)return;
Node *t;
t=start;
printf("%d: Removed from top of the list\n",start->data);
start=start->next;
free(t);
printf("\n");
}
//********************* Remove From Position *********************
void removeFromPosition()
{
Node *p1,*p2;
int pos,x=0;
printf("Note-: Positions are 0-indexed\nEnter position of element: ");
scanf("%d",&pos);
p1=start;
if(start==NULL) return;
while(x<pos && p1!=NULL)
{
p2=p1;
p1=p1->next;
x++;
}
if(p1==start)
{
start=start->next;
free(p1);
return;
}
if(p1==NULL)
{
printf("Invalid position\n\n");
return;
}
printf("%d: Removed from %d position\n",p1->data,pos);
p2->next=p1->next;
free(p1);
printf("\n");
}
//********************* Traverse Top To Bottom *********************
void traverseTopToBottom()
{
printf("\n");
printf("List\n");
Node *t=start;
while(t!=NULL)
{
printf("%d\n",t->data);
t=t->next;
}
printf("\n");
}
//********************* Traverse Bottom To Top*********************
void _traverseBottomToTop(Node *p)
{
if(p==NULL)return;
_traverseBottomToTop(p->next);
printf("%d\n",p->data);
}
void traverseBottomToTop()
{
printf("\nList\n");
_traverseBottomToTop(start);
printf("\n");
}
void getMiddle(Node *head)
{
int count=0;
Node *mid=head;
while (head!=NULL)
{
if (count%2)
{
mid=mid->next;
}
count++;
head=head->next;
}
if(mid!=NULL) printf("Middle: %d\n",mid->data);
}
//********************* Main Funtion*********************
int main()
{
int ch;
while(1)
{
printf("1. Add at top\n");
printf("2. Add at position\n");
printf("3. Add at end\n");
printf("4. Remove from top\n");
printf("5. Remove from position\n");
printf("6. Remove from end\n");
printf("7. Traverse Top to Bottom\n");
printf("8. Traverse Bottom to Top\n");
printf("8. Get Middle Element\n");
printf("10. Exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
if(ch==1) addAtTop(); //Done
else if(ch==2) addAtPosition(); //Done
else if(ch==3) addAtEnd(); //Done
else if(ch==4) getMiddle(start);
else if(ch==5) removeFromPosition(); //Done
else if(ch==6) removeFromEnd(); //Done
else if(ch==7) traverseTopToBottom(); //Done
else if(ch==8) traverseBottomToTop();
else if(ch==9) getMiddle(start);
else if(ch==10) break;
else printf("Invalid Choice, Try again\n");
}
return 0;
}
