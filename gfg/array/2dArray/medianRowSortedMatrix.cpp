#include<bits/stdc++.h>
using namespace std;
int median(vector<vector<int>> v)
{
    int mi=v[0][0];
    int ma=v[0][v[0].size()-1];
    for(int i=0;i<v.size();i++)    
    {
        mi=min(mi,v[i][0]);
        ma=max(ma,v[i][v[0].size()-1]);
    }
    int pos=(v.size()*v[0].size()+1)/2;
    while(mi<ma)
    {
        int mid=(mi+ma)/2;
        int p=0;
        for(int i=0;i<v.size();i++)
        {
            p+=upper_bound(v[i].begin(),v[i].end(),mid)-v[i].begin();
        }
        if(p<pos)
        {
            mi=mid+1;
        }
        else
        {
            ma=mid;
        }
    }
return mi;
}
int main()
{
    vector<vector<int>>v={{5,10,20,30,40},{1,2,3,4,6},{11,13,15,17,19}};
    // int arr[]={1,2,3,4,5,6,7,8,9,10};
    // cout<<upper_bound(v,v[3],4)-v;
    cout<<median(v);
}