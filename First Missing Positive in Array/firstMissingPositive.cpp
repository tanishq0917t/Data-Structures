#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int> &v,int n)
{
    for(int e=0;e<n;e++)
    {
        while(1<=v[e]<=n && v[e]!=v[v[e]-1])
        {
            swap(v[e],v[v[e]-1]);
        }
    }
    for(int e=0;e<n;e++)
    {
        if(e+1!=v[e]) return e+1;
    }
    return n+1;
}
int main()
{
    vector<int>v={4,8,1,5,-1,0,2};
    cout<<firstMissingPositive(v,7)<<endl;
    return 0;
}

/*
  APPROACH-:
  We will ignore the steps on -ve numbers and number greater than size of the array.
  1. We will iterate over the array and will determine that number at ith index is i-1 or not (since array is 0-indexed).
  2. If element at ith indexed is not on the correct place then we will swap the element at ith index and x[x[i]-1] so that the ith index element will get its correct position.
  3. After iterating over the whole array, we will iterate again and will check that x[e]==e+1 or not if not than e+1 is the first missing positive number.
*/
