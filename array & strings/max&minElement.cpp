#include<iostream>
using namespace std;
struct Pair{
    int min;
    int max;
};

Pair findMaxMIn(int arr[],int size){
    struct Pair a;
    a.max=arr[0];
    a.min=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>a.max)
        a.max=arr[i];
        if(arr[i]<a.min)
        a.min=arr[i];
    }
    return a;
    }



int main(){
    int arr[]={12,4,34,65,2,56,176,-9};
    int size=sizeof(arr)/sizeof(arr[0]);
    struct Pair b =findMaxMIn(arr,size);
    cout<<b.max<<b.min;
    cout<<endl;
    return 0;
}