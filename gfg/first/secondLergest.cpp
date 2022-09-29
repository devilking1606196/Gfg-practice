#include<bits/stdc++.h>
using namespace std;
// int secondMax(int arr[],int n)
// {
//     int f=0;
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]>arr[f])
//         {
//             f=i;
//         }
//     }
//     int s=-1;
//     int res=INT_MIN;
//     for(int i=0;i<n;i++)
//     { 
//         if(arr[i]==arr[f])
//         continue;
//         if(arr[i]>res)
//         s=i;
//     }
//     return s;

// }
int secondMax(int arr[],int n)
{
    int firstLargest=0,secondlargest=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[firstLargest])
        {
            secondlargest=firstLargest;
            firstLargest=i;
        }
        else if(arr[i]<arr[firstLargest])
        {
            if(secondlargest!=-1&&arr[secondlargest]<arr[i])
            secondlargest=i;
        }
    }
    return secondlargest;
}
int main()
{
    int arr[]={5,20,12,20,8};
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<secondMax(arr,n);

}