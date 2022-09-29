#include<bits/stdc++.h>
using namespace std;
void rotateByOne(int arr[],int n)
{
    int t;
    t=arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=t;
}
void rotateByK(int arr[],int n,int k)
{
    
    int temp[k];
    for(int i=0;i<k;i++)
    {
        temp[i]=arr[i];
    }
    for(int i=0,j=0;i<n;i++)
    {
        if(i+k<n)
        arr[i]=arr[i+k];
        else
        {
            arr[i]=temp[j];
            j++;
        }
    }

}
void rotateByKusingO(int arr[],int n,int k)
{
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    rotateByKusingO(arr,n,4);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}