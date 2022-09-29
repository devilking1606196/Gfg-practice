#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<int> temp;
   vector<vector<int>> ans;
   for(int i=0;i<arr.size();i++){
       for(int j=i+1;j<arr.size();j++){
           if(arr[i]+arr[j]==s)
           {
                vector<int> temp={arr[i],arr[j]};
                // temp.push_back(min(arr[i],arr[j]));
                // temp.push_back(max(arr[i],arr[j]));
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
           }
       }

   }
   sort(ans.begin(),ans.end());
   return ans;
}

 int main(){
     vector<vector<int>> res;
     vector <int> arr={1,2,3,4,5};
     res=pairSum(arr,5);
     for(int i=0;i<res.size();i++){
         for(int j=0;j<res[i].size();j++)
         cout<<res[i][j]<<" ";
         cout<<endl;
     }
     cout<<endl;
     return 0;
 }