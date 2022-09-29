//MAXIMUM LENTH OD ODD-EVEN SUNARRAY
#include <bits/stdc++.h>
using namespace std;
int maxLenthOddEven(int arr[],int size)
{
    int count=1,ans=1;
    for(int i=0;i<size;i++)
    {
        arr[i]=arr[i]&1;
    }
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]^arr[i+1])
        {
            count++;
            ans=max(ans,count);
        }
        else
        {
            count=1;
        }
    }
    return ans;
}
int  main()
{
    int arr[]={7,10,13,12,1,14};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<maxLenthOddEven(arr,size);
}