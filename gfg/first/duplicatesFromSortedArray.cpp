#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(int arr[],int n)
{
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(arr[res]!=arr[i])
        {
            res++;
            arr[res]=arr[i];
        }
    }
    return res+1;
}
int main()
{
    int arr[]={10,10,20,20,30,30,30,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    n=removeDuplicates(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}