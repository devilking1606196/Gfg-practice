#include<bits/stdc++.h>
using namespace std;

//tle
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(arr1[i]==arr2[j]){
               arr2[j]*=-1;
           ans.push_back(arr1[i]);
           break;
           }
       }
   }
   return ans;
}
vector<int> findArrayInter(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    int i=0,j=0;
    while(i<n&&j<m){
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;j++;
        }
        else if(arr1[i]<arr2[j])
        i++;
        else
        j++;
    }
    return ans;
}




int main(){
    vector<int> res;
    vector <int> a={1 ,2 ,2, 2 ,3 ,4},b={2 ,2 ,2 ,3 ,3};
    int n=a.size(),m=b.size();
    res=findArrayInter(a,n,b,m);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}