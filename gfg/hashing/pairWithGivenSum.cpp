#include<bits/stdc++.h>
using namespace std;
bool pairSum(int arr[],int n,int sum)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(sum-arr[i])!=s.end())        
        {
            return true;
        }
        else
        s.insert(arr[i]);
    }
    return false;
}
int main()
{
    int arr[]={8,3,2,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<pairSum(arr,n,6);
}