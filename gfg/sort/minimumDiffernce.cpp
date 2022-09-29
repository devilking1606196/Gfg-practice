#include<bits/stdc++.h>
using namespace std;
int minDiff(int arr[],int size)
{
    sort(arr,arr+size);
    int ans = INT_MAX;
    for(int i=1;i<size;i++)
    {
        if(arr[i]-arr[i-1]<ans)
        {
            ans=arr[i]-arr[i-1];
        }
    }
    return ans;
}
int main()
{
    int arr[]={10,-1,-4,4,32};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<minDiff(arr,size);
}