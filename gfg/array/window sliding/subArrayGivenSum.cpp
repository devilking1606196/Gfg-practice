#include<bits/stdc++.h>
using namespace std;
bool sumPossible(int arr[],int size,int k,int sum)
{
    int currSum=0;
    for(int i=0;i<k;i++)
    {
        currSum+=arr[i];
    }
    if(currSum==sum)
    return true;
    for(int i=k;i<size;i++)
    {
        currSum+=arr[i]-arr[i-k];
        if(currSum==sum)
        return true;
    }
    return false;
}
int main()
{
    int arr[]={1,8,3,-5,9,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<sumPossible(arr,size,4,7);
}