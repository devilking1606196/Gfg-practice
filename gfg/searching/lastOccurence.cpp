#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    int arr[]={1,10,10,10,20,20,30};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<lastOccurence(arr,size,20);
}