#include<iostream>
using namespace std;
void reverse(int arr[],int start,int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int arr[]={1,6,4,7,2,8,5,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    reverse(arr,0,size-1);
    // for(int i=0,j=size-1;i<=j;i++,j--){
    //     swap(arr[i],arr[j]);
    // }
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}