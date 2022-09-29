#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int s,int e,int n)
{
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==n)
        {
            return mid;
        }
        else if(arr[mid]<n)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return -1;
}
int searchInfinity(int arr[],int n)
{
    if(arr[0]==n)
    return 0;
    int i=1;
    while (i)
    {
        cout<<i<<endl;
        if(arr[i]==n)
        {
            return i;
        }
        else if(arr[i]>n)
        {
            return binarySearch(arr,i/2,i,n);
        }
        else
        {
            i*=2;
        }
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,25,26,27,28,29,30,31,32,46,53,75,234,1332,5332,5634,65434};
    cout<<searchInfinity(arr,33);
}