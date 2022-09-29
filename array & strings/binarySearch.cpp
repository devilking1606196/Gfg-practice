#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int key){
    int start=0,end=size-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key)
        return mid;
        else if(arr[mid]>key)
        end=mid-1;
        else if(arr[mid]<key)
        start=mid+1;
    }
    return -1;
}
int main(){
    int arr[]={3,5,6,7,8,13,25,34,43};
    int s=sizeof(arr)/sizeof(arr[0]);
    cout<<binarySearch(arr,s,5)<<" ";
}