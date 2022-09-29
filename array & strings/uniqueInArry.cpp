#include<iostream>
using namespace std;

// int findUnique(int arr[],int size){
//     for(int i=0;i<size;i++){
//         int count=0;
//         for(int j=0;j<size;j++){
//             if(arr[i]==arr[j])
//             count++;
//         }
//         if(count==1)
//         return arr[i];
//     }
//    return 0;
// }

int findUnique(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans^=arr[i];
    }
    return ans;
}


int main(){

    int arr[]={1,2,4,2,5,12,12,45,4,1,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int a=findUnique(arr,size);
     cout<<a<<endl;
    
    return 0;
}