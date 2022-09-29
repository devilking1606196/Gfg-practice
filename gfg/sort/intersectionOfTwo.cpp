#include<bits/stdc++.h>
using namespace std;
void intersectionOfTwoArray(int arr1[],int arr2[],int  n1,int n2)
{
    int i=0,j=0,ans=INT_MIN;
    while(i<n1&&j<n2)
    {
        if(arr1[i]==arr2[j]&&ans!=arr1[i])
        {
            cout<<arr1[i]<<" ";
            ans=arr1[i];
            i++;j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}
int main()
{
    int arr1[]={3,5,10,10,10,15,15,20,20,20,30,55};
    int arr2[]={5,10,10,15,20,20,20,20,30};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    intersectionOfTwoArray(arr1,arr2,n1,n2);
}