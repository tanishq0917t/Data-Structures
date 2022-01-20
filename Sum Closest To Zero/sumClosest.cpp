#include <bits/stdc++.h>
using namespace std;
bool compare(int x, int y)
{
    return abs(x) < abs(y);
}
void findMinSum(vector<int> arr, int n)
{
    sort(arr.begin(),arr.end(), compare);
    /*for(int e:arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;*/
    int min = INT_MAX, x, y;
    for (int i = 1; i < n; i++) 
    {
        if (abs(arr[i - 1] + arr[i]) <= min) 
        {
            min = abs(arr[i - 1] + arr[i]);
            x = i - 1;
            y = i;
        }
    }
    cout << "The two elements whose sum is minimum are "<< arr[x] << " and " << arr[y]<<endl;
}
int main()
{
    vector<int>arr = { 70, -80, -10, 1, 60, 80 };
    int n = arr.size();
    findMinSum(arr, n);
    return 0;
}
