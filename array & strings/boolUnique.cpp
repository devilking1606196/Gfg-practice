#include<iostream>
#include<vector>
using namespace std;


//brute force
bool unique(int arr[],int size){
    bool ans=true;
    vector<int> count;

    for(int i=0;i<size;i++){
        int temp=1;
        for(int j=i+1;j<size;j++){
            if(arr[i]==2000)
            break;
            else if(arr[i]==arr[j]){
            temp++;
            arr[j]=2000;
            }
        }
        if(arr[i]!=2000)
        count.push_back(temp);
    }
    int s=sizeof(count)/sizeof(count[0]);
    for(int i=0;i<s;i++){
        
        for(int j=i+1;j<s;j++){
            if(count[i]==count[j]&&count[i]!=0)
           ans= false;
        }
    }
    return ans;
}

//optmium solution
 
int main(){
    int arr[]={1,2,2,3,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    if(unique(arr,size))
    cout<<"true";
    else
    cout<<"false";
    cout<<endl;
   return 0;
}