#include<bits/stdc++.h>
using namespace std;
int searchInRoatated(int arr[],int size,int n)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==n)
        {
            return mid;
        }
        if(arr[s]<=arr[mid])
        {
            if((n>=arr[s]) && (n<arr[mid]))
            {
                e=mid-1;
            }
            else
            s=mid+1;
        }
        else
        {
            if((n<=arr[e])&&(n>arr[mid]))
            {
                s=mid+1;
            }
            else
            e=mid-1;
        }
    }
return -1;
}
int main()
{
    int arr[]={100,200,10,20,30,40 ,50};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<searchInRoatated(arr,size,50);
}