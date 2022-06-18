#include<bits/stdc++.h>
using namespace std;
int cc=0;
/* Bottom to Top
int solve(vector<vector<int>> &v,int i,int j)
{
if(i<0 || j<0) return 0;
if(i==0 && j==0) return 1;
return solve(v,i-1,j)+solve(v,i,j-1);
}
int uniquePaths(vector<vector<int>> &v)
{
return solve(v,v.size()-1,v[0].size()-1);
}
*/
// Top to Bottom
int solve(vector<vector<int>> &v,int i,int j)
{
if(i==v.size() || j==v[0].size()) return 0;
if(i==v.size()-1 && j==v[0].size()-1) return 1;
cc++;
return solve(v,i+1,j)+solve(v,i,j+1);
}
int uniquePaths(vector<vector<int>> &v)
{
return solve(v,0,0);
}
int main()
{
//vector<vector<int>> v ={{1,2},{4,5}};
//vector<vector<int>> v ={{1,2,3},{4,5,6},{7,8,9}};
vector<vector<int>> v ={{1,2,3,0},{4,5,6,0},{7,8,9,0},{10,11,12,0}};
cout<<"Unqiue Paths exists are: "<<uniquePaths(v)<<endl;
cout<<"Number of copies made: "<<cc<<endl;
return 0;
}
