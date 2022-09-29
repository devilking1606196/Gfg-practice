#include<bits/stdc++.h>
using namespace std;
//brute force
vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector <int> ans;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
                i+=2;
            }
            else
                i++;
        }
        return ans;
    }


// optimized
vector <int> findDup(vector<int>& nu){
    vector <int> ans;
    for(int i=0;i<nu.size();i++){
        if(nu[abs(nu[i])-1]<0){
            ans.push_back(abs(nu[i]));
        }
        else{
            nu[abs(nu[i])-1]*=-1;
        }
    }
    return ans;
}


int main(){
    vector <int> a;
    vector <int> num={4,3,2,7,8,2,3,1};
    a=findDup(num);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;

    }

}