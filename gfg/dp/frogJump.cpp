#include<bits/stdc++.h>
using namespace std;
int minEnergy(int height[],int n,vector<int> &dp)
{
    if(n==0)
    return 0;

    if(dp[n]!=-1)
    return dp[n];

    int l=minEnergy(height,n-1,dp)+abs(height[n]-height[n-1]);
    int r=INT_MAX;
    if(n>1)
    r=minEnergy(height,n-2,dp)+abs(height[n-2]-height[n]);
    
    return dp[n]=min(l,r);
}
int main()
{
    int height[]={30,10,60,10,60,50};
    int n=sizeof(height)/sizeof(height[0]);
    vector<int>dp(n+1,-1);
    cout<<minEnergy(height,n-1,dp);
}