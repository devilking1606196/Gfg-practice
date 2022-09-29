//maximum sum of continious subarray
#include<bits/stdc++.h>
using namespace std;
int sumOfSubarray(int arr[],int size)
{
    int ans=INT_MIN,tsum=0;
    for(int i=0;i<size;i++)
    {
        tsum=0;
        for(int j=i;j<size;j++)
        {
            tsum+=arr[j];
            ans=max(ans,tsum);
        }
    }
    return ans;
}
// int sumOfSubarray(int arr[],int size)//MAXIMUM SUM ENDING WITH THE PREVIOUS VALUE
// {
//     int t=arr[0],ans=arr[0];

//     for(int i=1;i<size;i++)
//     {
//         if(t>0)
//         {
//             t+=arr[i];
//             ans=max(ans,t);
//         }        
//         else
//         {
//             t=arr[i];
//             ans=max(ans,t);
//         }
//     }
//     return ans;
// }




// {
//     int res=arr[0],maxending=arr[0];
//     for(int i=1;i<size;i++)
//     {
//         maxending=max(maxending+arr[i],arr[i]);
//         res=max(res,maxending);
//     }
//     return res;
// }
int main()
{
    int arr[]={5,-2,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<sumOfSubarray(arr,size);
}