#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int low,int mid,int high)
{
    int n1=mid-low+1,n2=high-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
    {
        left[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=low;              //IMPORTANT
    while(i<n1&&j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            k++;i++;
        }
        else
        {
            arr[k]=right[j];
            k++;j++;
        }
    }
    while(i<n1)
    {
        arr[k]=left[i];
        k++;i++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        k++;j++;
    }
}

void mergeSort(int arr[],int low,int high)
{
    if(high<=low)
    return;
    
        int mid=(high+low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
}

int main()
{
    int arr[]={5,21,15,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
