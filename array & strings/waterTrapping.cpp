#include<bits/stdc++.h>
using namespace std;
vector <int> lmax(int arr[],int n)
{
    int t=0;
    vector <int> ans;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>t)
        {
            ans.push_back(arr[i]);
            t=ans[i];
        }
        else
        ans.push_back(t);
    }
    return ans;
}
vector <int> rmax(int arr[],int n)
{
    int t=0;
    reverse(arr,arr+n);
    vector <int> ans;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>t)
        {
            ans.insert(ans.begin(),arr[i]);
            t=ans[i];
        }
        else
        ans.insert(ans.begin(),t);
    }
    return ans;
}

int waterStored(int arr[],int n,vector<int>l,vector<int> r)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int height=min(l[i],r[i]);
        ans=ans+height-arr[i];
    }
    return ans;

}
int main()
{
    int arr[]={4,2,0,3,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector <int> l,r;
    l=lmax(arr,n);
    r=rmax(arr,n);
    // for(int i:l)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(int i:r)
    // {
    //     cout<<i<<" ";
    // }
    cout<<"ans "<<waterStored(arr,n,l,r)<<endl;


}