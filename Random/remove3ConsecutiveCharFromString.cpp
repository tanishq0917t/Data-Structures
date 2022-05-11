#include<bits/stdc++.h>
using namespace std;
string solve(string m)
{
if(m.length()<3) return m;
int e=1;
while(e<m.length()-1)
{
if(m[e-1]==m[e] && m[e]==m[e+1])
{
if(e==1)
{
if(m.length()==3) return "";
m=m.substr(3);
}
else
{
m=m.substr(0,e-1)+m.substr(e+2);
}
e=1;
continue;
}
e++;
}
return m;
}
int main()
{
string m;
cin>>m;
cout<<solve(m)<<endl;
return 0;
}

/*
SAMPLE TESTCASE-1 => INPUT->aabbccdddcba OUTPUT->""
aabbccdddcba
-> aabbcc + (ddd) + cbbaa => aabbcccba (removing ddd)
aabbcccba
-> aabb + (ccc) + ba => aabbba (removing ccc)
aabbba
-> aa + (bbb) + a => aaa (removing bbb)
aaa
-> ""+ (aaa) +"" =>"" (removing aaa)
ANSWER=> ""
*/
