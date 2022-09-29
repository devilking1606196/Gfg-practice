#include<bits/stdc++.h>
using namespace std;
int findPivot(int arr[],int size){
    int sum=0,l=0,r=0;
    for(int i=0;i<size;i++)
    sum+=arr[i];
    r=sum-arr[0];
    l=sum-r-arr[0];
    for(int i=0;i<size;i++){
        if(r==l)
        return i;
        else{
            l+=arr[i];
            r-=arr[i+1];
        }
    }
    return -1;

}
int main(){
    int arr[]={2,5};
    int s=sizeof(arr)/sizeof(arr[0]);
    cout<<findPivot(arr,s)<<endl;
    

}