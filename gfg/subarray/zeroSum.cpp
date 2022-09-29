#include<bits/stdc++.h>
using namespace std;

            // O(N^2)
// bool subarrayZeroSum(int arr[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         int sum=0;
//         for(int j=i;j<n;j++)
//         {
//             sum+=arr[j];
//             if(sum==0)
//             return true;
//         }
//     }
// return false;
// }

bool subarrayZeroSum(int arr[],int n)     //check it out
{
    unordered_set <int>s;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(s.find(sum)!=s.end())
        return true;
        if(sum==0)
        return true;
        s.insert(sum);
    }
    return false;
}

int main()
{
    int arr[]={1,4,-5,-3,-10,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<boolalpha<<subarrayZeroSum(arr,n);
}