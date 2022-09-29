#include<bits/stdc++.h>
using namespace std;
int repeatingElement(int arr[],int size)//O(N) space and time
{
    bool ans[size-1]={false};
    for(int i=0;i<size;i++)
    {
        if(ans[arr[i]])
        return arr[i];
        ans[arr[i]]=true;
    }
    return -1;
}
//O(1) space and O(N) time

int findRep(int arr[],int size)// 0 not included 
{
    int slow=arr[0];
    int fast=arr[0];
    do
    {
        slow=arr[slow];//1 step
        fast=arr[arr[fast]];//2 steps
    }
    while(slow!=fast);
    slow=arr[0];
    while(slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
}
int findRepeative(int arr[],int size)// 0 included
{
    int slow=arr[0]+1;
    int fast =arr[0]+1;
    do
    {
        slow=arr[slow]+1;
        fast=arr[arr[fast]+1]+1;
    }while(slow!=fast);

    slow=arr[0]+1;
    while(slow!=fast)
    {
        slow=arr[slow]+1;
        fast=arr[fast]+1;
    }
    return slow-1;
}

int main()
{
    int arr[]={0,2,1,3,4,5,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<findRepeative(arr,size)<<endl;
    int arr1[]={2,1,3,4,5,6,7,3};
    size=sizeof(arr1)/sizeof(arr1[0]);
    cout<<findRep(arr1,size);
}