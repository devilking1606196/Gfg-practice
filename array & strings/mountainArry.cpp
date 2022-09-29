#include<bits/stdc++.h>
using namespace std;
int findMountain(int arr[],int size){
    int s=0,e=size-1,mid;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])
        return mid;
        else if(arr[mid]<arr[mid+1])
        s=mid+1;
        else if(arr[mid]<arr[mid-1])
        e=mid-1;
    }
    return -1;
}
int main(){
    int arr[]={24,69,100,99,79,78,67,36,26,19};
    int s=sizeof(arr)/sizeof(arr[0]);
    cout<<findMountain(arr,s)<<endl;
    int i=findMountain(arr,s);
    cout<<arr[i];
}