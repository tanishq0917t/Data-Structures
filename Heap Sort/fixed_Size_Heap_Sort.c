#include<stdio.h>
int main()
{
int x[10],y,ci,ri,lci,rci,g,swi;
for(int e=0;e<10;e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
y=1;
while(y<10)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(x[ci]>x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}
else
{
break;
}
}
y++;
}
//now max heap is created
//now we can implement heap-Sort
y=9;
while(y>0)
{
g=x[0];
x[0]=x[y];
x[y]=g;
y--;
ri=0;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y)
{
swi=lci;
}
else
{
if(x[lci]>x[rci]) swi=lci;
else swi=rci;
}
if(x[swi]>x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}
else break;
}
}
for(int e=0;e<10;e++)printf("%d\n",x[e]);
return 0;
}
