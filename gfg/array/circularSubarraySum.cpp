#include<bits/stdc++.h>
using namespace std;
// int circularSum(int arr[],int size)
// {
//     int ans=arr[0],t;
//     for(int i=0;i<size;i++)
//     {
//         int c=0,k=0;
//         for(int j=0;j<size;j++)
//         {
//             c=(i+j)%size;
//             k+=arr[c];
//             ans=max(ans,k);       
//         }
//     }
//     return ans;
// }

// minimum sum subarray is to be subtracted with the total sum of the array
int minimumSum(int arr[],int size)
{
    int ans=0,temp=arr[0];
    for(int i=1;i<size;i++)
    {
        temp=min(temp+arr[i],arr[i]);
        ans=min(ans,temp);
    }
    return ans;
}
int maxSum(int arr[],int size)
{
    int ans=arr[0],temp=arr[0];
    for(int i=1;i<size;i++)
    {
        temp=max(temp+arr[i],arr[i]);
        ans=max(ans,temp);
    }
    return ans;
}
int circularSum(int arr[],int size)
{
    int normalSum=maxSum(arr,size);
    if(normalSum<0)
    return normalSum;
    int sum=0,t=minimumSum(arr,size);
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    int circularSum=sum-t;
    return max(normalSum,circularSum);
}
int main()
{
    int arr[]={-4,-3,-5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<circularSum(arr,size);
}