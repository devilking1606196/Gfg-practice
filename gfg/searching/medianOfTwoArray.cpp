//median of two sorted array 
#include<bits/stdc++.h>
using namespace std;
double medainOfArrays(int arr1[],int arr2[],int n1,int n2)
{
    int s=0,e=n1-1;
    while(s<=e)
    {
        int mid1=(s+e)/2;
        int mid2=(n1+n2+1)/2;mid2-=mid1;
        int max1=(mid1==0)?INT_MIN:arr1[mid1-1]; //largest element in left side of arr1
        int min1=(mid1==n1-1)?INT_MAX:arr1[mid1];  // minimum element in right side of arr1
        int max2=(mid2==0)?INT_MIN:arr2[mid2-1];
        int min2=(mid2==n2-1)?INT_MAX:arr2[mid2];
        if(max1<=min2 && max2<=min1)   // when left half of both array is smaller than the right half of other array
        {
            if((n1+n2)%2)
            {
                return (double)max(max1,max2);
            }
            else
            {
                double med=(max(max1,max2)+min(min1,min2))/2;
                return (double)med;
            }
        }
        else if(max2>min1)
        {
            s=mid1+1;
        }
        else
        {
            e=mid1-1;
        }
    }
return 0;
}
int main()
{
    int arr1[]={2,15,27,30,45};
    int arr2[]={13,17,35,50,67,99};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    cout<<medainOfArrays(arr1,arr2,n1,n2);
}