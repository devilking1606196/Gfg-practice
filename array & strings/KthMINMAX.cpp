#include<iostream>
#include<numeric>
// #include<bits/stdc++.h>
#include<vector>
using namespace std;
struct numbers{
    int max;
    int min;
};
void sortArr(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j])
            swap(arr[i],arr[j]);
        }

    }
}
void swap (int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
numbers findKthMinMAx(int arr[],int size,int k){
    struct numbers num;
    sortArr(arr,size);
    num.max=arr[size-k];
    num.min=arr[k-1];
    return num;
}



int main(){
    int arr[]={5,7 ,10 ,4 ,20 ,15,4};
    int k=1;
    int size=sizeof(arr)/sizeof(arr[0]);
    // sortArr(arr,arr+size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    struct numbers nums = findKthMinMAx(arr,size,k);
    
    cout<<"max: "<<nums.max<<" min: "<<nums.min;
    cout<<endl;
    return 0;
}