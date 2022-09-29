#include<bits/stdc++.h>
using namespace std;
void unionOfArrays(int arr1[],int arr2[],int n1,int n2)
{
    int ans=INT_MIN,i=0,j=0;
    while(i<n1&&j<n2)
    {
        if(i>0&&arr1[i-1]==arr1[i])
        {
            i++;
            continue;
        }
        if(j>0&&arr2[j-1]==arr2[j])
        {
            j++;
            continue;
        }
        if(arr1[i]<arr2[j])
        {
            cout<<arr1[i]<<" ";
            ans=arr1[i];
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            cout<<arr2[j]<<" ";
            ans=arr2[j];
            j++;
        }
        else if(arr1[i]==arr2[j])
        {
            cout<<arr1[i]<<" ";
            ans=arr1[i];
            i++;j++;
        }
    }
    while(i<n1)
    {
        if(i>0&&arr1[i-1]!=arr1[i])
        cout<<arr1[i]<<" ";
        i++;
    }
    while(j<n2)
    {
        if(j>0&&arr2[j-1]!=arr2[j])
        cout<<arr1[j]<<" ";
        j++;
    }
}
int main()
{
    int arr1[]={3,5,10,10,10,15,15,20,20,20,30,55,55,55,66,66,67};
    int arr2[]={5,9,10,10,15,20,20,20,20,27,29,30};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    unionOfArrays(arr1,arr2,n1,n2);
}