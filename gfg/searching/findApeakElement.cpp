#include<bits/stdc++.h>
using namespace std;
int peakElement(int arr[],int size)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        int mid=e+(s-e)/2;
        if((mid==0||arr[mid]>=arr[mid-1])&&(mid==size-1||arr[mid]>=arr[mid+1]))
        {
            return arr[mid];
        }
        else if(arr[mid-1]>=arr[mid])
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
return -1;
}
int main()
{
    int arr[]={33,33,25,37,3,50,67};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<peakElement(arr,size);
}