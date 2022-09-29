#include<bits/stdc++.h>
using namespace std;
int maxLengthSubArray(int arr[],int n,int sum)
{
    unordered_map <int,int> m;
    int preSum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        preSum+=arr[i];
        if(preSum==sum)
        {
            ans=i+1;
        }
        if(m.find(preSum)==m.end())
        {
            m.insert({preSum,i});
        }
        if(m.find(preSum-sum)!=m.end())
        {
            ans=max(ans,i-m[preSum-sum]);
        }

    }
    return ans;
}
int main()
{
    int arr[]={8,3,1,5,-6,6,2,2};
    int n=sizeof(arr)/sizeof(arr[0]),sum=4;
    cout<<maxLengthSubArray(arr,n,sum);
    // unordered_map <int,int> m;
    // m.insert({8,0});
    // m.insert({12,1});
    // m.insert({13,2});
    // m.insert({12,3});
    // cout<<m[8];
}