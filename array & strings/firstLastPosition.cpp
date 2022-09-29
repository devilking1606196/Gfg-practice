#include<bits/stdc++.h>
using namespace std;

int findFirstAndLast(int arr[],int size,int key){
    int left,right,mid,start=0,end=size-1;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==key){
            left=mid;
            end=mid-1;
        }
        else if(arr[mid]>key)
        end=mid-1;
        else
        start=mid+1;
    }
    start=0,end=size-1;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==key){
            right=mid;
            start=mid+1;
        }
        else if(arr[mid]>key)
        end=mid-1;
        else
        start=mid+1;
 }


return right;


}
int main(){
    int arr[]={3,5,6,7,8,8,8,8,8,8,13,25,34,43};
    int s=sizeof(arr)/sizeof(arr[0]);
    cout<<findFirstAndLast(arr,s,8)<<" ";

}