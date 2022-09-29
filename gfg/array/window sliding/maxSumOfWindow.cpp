#include<bits/stdc++.h>
using namespace std;
int maxSum(int arr[],int size,int k)
{
    int maxSum,currSum=0;
    for(int i=0;i<k;i++)
    {
        currSum+=arr[i];
        maxSum=currSum;
    }
    for(int i=k;i<size;i++)
    {
        currSum+=arr[i]-arr[i-k];
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}
int main()
{
    int arr[]={1,8,3,-5,9,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<maxSum(arr,size,3);
}