#include<bits/stdc++.h>
using namespace std;
int firstIndex(bool arr[],int size,int n)
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
int countOnes(bool arr[],int size)
{
    int first=firstIndex(arr,size,1);
    if(first==-1)
    {
        return 0;
    }
    return size-first;
}
int main()
{
    bool arr[]={0,0,0,0,1,1,1,1,1,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<countOnes(arr,size);
}