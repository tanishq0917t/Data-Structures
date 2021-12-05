import java.util.*;
import java.io.*;
class Tanishq
{
public static void main(String gg[])
{
PriorityQueue<Integer> pq=new PriorityQueue<>();
int x[]={10,-15,90,424,24,109,-953,291,11,-42};
Scanner sc=new Scanner(System.in);
int k=sc.nextInt();
for(int e=0;e<k;e++)
{
pq.add(x[e]);
}
for(int e=k;e<10;e++)
{
if(pq.peek()<x[e])
{
pq.poll();
pq.add(x[e]);
}
}
System.out.println("Kth Largest element of x where k= "+k+" is: "+pq.peek());
}
}
