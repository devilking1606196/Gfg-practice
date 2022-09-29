#include <bits/stdc++.h>
using namespace std;
int waterCollected(int arr[],int size)//BY MAKING TWO ARRAY OF LMAX AND RMAX
{
    int ans=0;
    for(int i=1;i<size-1;i++)
    {
        int lmax=arr[i],rmax=arr[i];
        for(int j=0;j<i;j++)
        {
            lmax=max(lmax,arr[j]);
        }
        for(int j=i+1;j<size;j++)
        {
            rmax=max(rmax,arr[j]);
        }
        ans+=min(lmax,rmax)-arr[i];
    }
    return ans;
}
int main()
{
    // int arr[]={2,0,6,4,0,1,5,3};
    int arr[]={3,6,1,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<waterCollected(arr,size);
}