#include<iostream>
using namespace std;
//brute force
int findDuplicate(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j])
            return arr[i];
        }
    }
return 0;
}

//using xor
int finddup(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^i^arr[i];
    }
    return ans;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    int a=finddup(arr,size);
    cout<<a<<endl;

}