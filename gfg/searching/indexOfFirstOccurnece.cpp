#include<bits/stdc++.h>
using namespace std;
// int firstIndex(int arr[],int s,int e,int n)
// {
//     if(s>e)
//     return -1;
//     int mid=(s+e)/2;
//     if(arr[mid]==n)
//     {
//         if(mid==0||arr[mid]!=arr[mid-1])
//         {
//             return mid;
//         }
//         else
//         return firstIndex(arr,s,mid-1,n);
//     }
//     else if(arr[mid]<n)
//     {
//         return firstIndex(arr,mid+1,e,n);
//     }
//     else
//     {
//         return firstIndex(arr,s,mid-1,n);
//     }
// }
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
int main()
{
    int arr[]={1,10,10,10,20,20,30};
    int size=sizeof(arr)/sizeof(arr[0]);
    // cout<<firstIndex(arr,0,size-1,11);
    cout<<firstIndex(arr,size,30);
}