#include<bits/stdc++.h>
using namespace std;
int rangeSum(int arr[],int size,int s,int e)
{
    int sum[size]={0};
    sum[0]=arr[0];
    for(int i=1;i<size;i++)
    {
        sum[i]+=sum[i-1]+arr[i];
    }
    if(s!=0)
    return(sum[e]-sum[s-1]);
    else
    return sum[e];
}
int main()
{
    int arr[]={2,8,3,9,6,5,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<rangeSum(arr,size,0,2)<<endl;
    cout<<rangeSum(arr,size,1,3)<<endl;
    cout<<rangeSum(arr,size,3,4)<<endl;
}