#include<bits/stdc++.h>
using namespace std;
// finding pivot
int findPivot(vector<int> arr,int size){
    int s=0,e=size-1,mid;
    while(s<e)
    {
        mid=(s+e)/2;
        if(arr[mid]>=arr[0])
        {
            s=mid+1;
        } 
        else
        {
            e=mid;
        }
    }
    return s;    
}
//binary search
int binarySearch(vector<int> arr,int s,int e,int k){
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]==k)
        return mid;
        else if(arr[mid]<k)
        s=mid+1;
        else
        e=mid-1;
    }
    return -1;
}

//seraching in rotated array
int findPosition(vector<int>& arr, int size, int k)
{
    int pivot= findPivot(arr,size);
    if(arr[pivot]==k)
    return pivot;
    else if(arr[pivot]<=k&&k<=arr[size-1])
    {
        return binarySearch(arr,pivot,size-1,k);
    }
    else if(arr[pivot-1]>=k&&arr[0]<=k)
    return binarySearch(arr,0,pivot,k);
    return -1;
}




int main()
{
    vector <int> arr={8};
    cout<<findPosition(arr,arr.size(),4)<<" ";
    cout<<findPivot(arr,arr.size());

}