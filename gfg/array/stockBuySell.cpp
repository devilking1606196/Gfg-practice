#include<bits/stdc++.h>
using namespace std;
int maxProfit(int arr[],int size)
{
    int buy=arr[0],profit=0;
    for(int i=0;i<size;i++)
    {
        if(i==size-1)
        {
            profit=profit+arr[i]-buy;
        }
        else if(arr[i+1]<arr[i])
        {
            profit=profit+arr[i]-buy;
            buy=arr[i+1];
        }
    }
    return profit;
}
int main()
{
    int arr[]={1,5,3,1,2,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<maxProfit(arr,size);

}