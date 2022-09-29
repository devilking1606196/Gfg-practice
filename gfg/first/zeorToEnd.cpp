#include<bits/stdc++.h>
using namespace std;
void zerosEnd(int arr[],int n)
{
    int s=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            arr[s]=arr[i];
            s++;
        }
    }
    for(int i=s;i<n;i++)
    {
        arr[i]=0;
    }
    // for(int i=0;i<n;i++)
    // {
    //     if(arr[i]==0)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(arr[j]!=0)
    //             {
    //             swap(arr[i],arr[j]);
    //             break;
    //             }
    //         }
    //     }
    // }

}
int main()
{
    int arr[]={0,0,8,5,0,10,0,20,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    zerosEnd(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}