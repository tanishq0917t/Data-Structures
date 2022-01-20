#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int low, int high)
{
    if(high >= low)
    {
        int mid = low + (high - low)/2;
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1) return mid;
        else if (arr[mid] == 0) return binarySearch(arr, (mid + 1), high);
        else return binarySearch(arr, low, (mid -1));
    }
    return -1;
}
int main()
{
    vector<vector<int>>v={{0,0,0,1},{0,1,1,1},{0,1,1,1},{1,1,1,1}};
    int mn=4;
    int j=-1;
    int ans=-1;
    for(int e=0;e<v.size();e++)
    {
        for(int f=0;f<v[e].size();f++)
        {
            j=binarySearch(v[e],0,3);
            if(j<mn)
            {
                mn=j;
                ans=e;
                if(j==v[e].size()-1) break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
