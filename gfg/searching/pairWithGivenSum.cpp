#include<bits/stdc++.h>
using namespace std;
bool sumOfPair(int arr[],int size,int sum)
{
    int s=0,e=size-1;
    while(s<e)
    {
        if(arr[s]+arr[e]==sum)
        {
            return true;
        }
        else if(arr[s]+arr[e]<sum)
        {
            s++;
        }
        else
        {
            e--;
        }
    }
    return false;
}
bool sumOfTriplet(int arr[],int size,int n)
{
    if(arr[size-1]<n)
    {
        if(sumOfPair(arr,size-1,n-arr[size-1]))
        return true;
    }
    for(int i=0;i<size-1;i++)
    {
        swap(arr[i],arr[size-1]);
        int s=n-arr[size-1];
        if(sumOfPair(arr,size-1,s))
        return true;
        swap(arr[i],arr[size-1]);
    }
    return false;
}
int main()
{
    // int arr[]={2,5,8,12,30};
    int arr[]={2,3,4,8,9,20,40};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<boolalpha<<sumOfPair(arr,size,16)<<endl;
    cout<<boolalpha<<sumOfTriplet(arr,size,10);
}