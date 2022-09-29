#include<bits/stdc++.h>
using namespace std;
vector<pair <int,int>> localMaxMin(vector <int> v,int n)
{
    vector<pair <int,int>> final;
    pair <int,int> ans;
    for(int i=0;i<n;i++)
    {
        if(v[i]<v[i+1]&&i==0)
        {
            ans.first=v[i];
        }
        else if(v[i]<v[i+1]&&v[i]<v[i-1])
        {
            ans.first=v[i];
        }

        if(v[i]>v[i-1]&&i==n-1)
        {
            ans.second=v[i];
            final.push_back(ans);
        }
        else if(v[i]>v[i-1]&&v[i]>v[i+1])
        {
            ans.second=v[i];
            final.push_back(ans);
        }
        
    }
    return final;

}
int main()
{
    vector <int> v={1,5,3,8,12};
    vector<pair <int,int>> a=localMaxMin(v,v.size());
    for(auto i:a)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    //buy and sell stocks to maximize the profit
    int profit=0;
    for(auto i:a)
    {
        profit+=i.second-i.first;
    }
    cout<<profit<<endl;
}