#include<bits/stdc++.h>
using namespace std;
// int majorityElement(int arr[],int size)
// {
//     for(int i=0;i<size;i++)
//     {
//         int count=1;
//         for(int j=i+1;j<size;j++)
//         {
//             if(arr[i]==arr[j])
//             {
//                 count++;
//             }
//         }
//         if(count>size/2)
//         {
//             return arr[i];
//         }
//     }
//     return -1;
// }
int majorityElement(int arr[],int size)
{
    int resIndex=0,count=1;
    for(int i=1;i<size;i++)
    {
        if(arr[resIndex]==arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count==0)
        {
            count=1;resIndex=i;
        }
    }
    count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[resIndex]==arr[i])
        count++;
    }
    if(count>size/2)
    return arr[resIndex];
    return -1;
}
int main()
{
    int arr[]={8,3,3,4,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<majorityElement(arr,size);
}