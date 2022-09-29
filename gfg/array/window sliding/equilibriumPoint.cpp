#include<bits/stdc++.h>
using namespace std;
int rangeSum(int arr[],int size,int s,int e)
{
    int preSum[size]={0};
    preSum[0]=arr[0];
    for(int i=1;i<size;i++)
    {
        preSum[i]+=preSum[i-1]+arr[i];
    }
    if(s!=0)
    {
        return (preSum[e]-preSum[s-1]);
    }
    else
    {
        return (preSum[e]);
    }
}
//O(N) extra space
// bool equilibriumPoint(int arr[],int size)
// {
//     int l=0,r=rangeSum(arr,size,1,size-1);
//     if(l==r)
//         return true;
//     for(int i=1;i<size;i++)
//     {
//         l=rangeSum(arr,size,0,i-1);
//         r=rangeSum(arr,size,i+1,size-1);
//         if(l==r)
//         return true;
//     }
//     return false;
// }
//O(1) extre space
bool equilibriumPoint(int arr[],int size)
{
    int sum=0,lSum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    for(int i=0;i<size;i++)
    {
        if(lSum==sum-arr[i])
        return true;
        lSum+=arr[i];
        sum-=arr[i];
    }
    return false;
}
int main()
{
    int arr[]={3,4,8,-9,20,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<boolalpha<<equilibriumPoint(arr,size)<<endl;
}
