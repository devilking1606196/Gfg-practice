#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n);
void selectionSort(int arr[],int n);
void bubbleSort(int arr[],int n);


int main()
{
    int arr[]={1,4,7,8,12,3,123,200};
    int n=sizeof(arr)/sizeof(arr[0]);
    // bubbleSort(arr,n);
    // selectionSort(arr,n);
    insertionSort(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}


void bubbleSort(int arr[],int n)
{
    
    for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<n-1-i;j++)
        {
            swapped=true;
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
        if(!swapped)
        return;
    }
}
void selectionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[min])
            min=j;
        }
        swap(arr[i],arr[min]);
    }
}
void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            swap(arr[j],arr[j-1]);
        }
    }
}
