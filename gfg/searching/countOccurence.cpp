#include<bits/stdc++.h>
using namespace std;
int firstIndex(int arr[],int size,int n)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==n)
        {
            if(mid==0||arr[mid]!=arr[mid-1])
            {
                return mid;
            }
            else
            {
                e=mid-1;
            }
        }
        else if(arr[mid]<n)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return -1;
}
int lastOccurence(int arr[],int size,int n)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==n)
        {
            if((mid==size-1)||arr[mid]!=arr[mid+1])
            {
                return mid;
            }
            else
            {
                s=mid+1;
            }
        }
        else if(arr[mid]<n)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
return -1;
}
int countOccurence(int arr[],int size,int n)
{
    int first=firstIndex(arr,size,n);
    if(first==-1)
    return 0;
    int last=lastOccurence(arr,size,n);
    return (last-first+1);
}
int main()
{
    int arr[]={10,10,10,10,20,20,30};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<countOccurence(arr,size,10);
}