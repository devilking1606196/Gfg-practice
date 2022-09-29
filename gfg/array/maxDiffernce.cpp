#include<bits/stdc++.h>
using namespace std;
// int maxDiffernce(int arr[],int size)
// {
//     int ans=INT_MIN;
//     for(int i=0;i<size;i++)
//     {
//         for(int j=i+1;j<size;j++)
//         {
//             int t=arr[j]-arr[i];
//             if(t>ans)
//             ans=t;
//         }
//     }
//     return ans;
// }
int maxDiffernce(int arr[],int size)
{
    int ans=INT_MIN,min=arr[0],t;
    for(int i=1;i<size;i++)
    {
        t=arr[i]-min;
        if(arr[i]<min)
        {
            min=arr[i];
        }
        if(t>ans)
        {
            ans=t;
        }
    }
    return ans;
}
int main()
{
    int arr[]={44,50,2,10,9,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<maxDiffernce(arr,size);
}