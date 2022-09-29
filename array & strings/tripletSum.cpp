#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==K){
                    vector<int> t={arr[i],arr[j],arr[k]};
                    ans.push_back(t);
                }

            }
        }
    }
	// Write your code here.
    return ans;
}

 int main(){
     vector<vector<int>> res;
     vector<int> arr={1 ,2 ,3 ,1 ,2 ,3};
     int n=arr.size();
     res=findTriplets(arr,n,6);
    for(int i=0;i<res.size();i++){
         for(int j=0;j<res[i].size();j++)
         cout<<res[i][j]<<" ";
         cout<<endl;
     }
     cout<<endl;



 }