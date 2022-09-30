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
int frogJump(int height[],int n)
{
    vector<int>dp(n,0);
    dp[0]=0; //base case
    for(int i=1;i<n;i++)
    {
        int l=dp[i-1]+abs(height[i]-height[i-1]);
        int r=INT_MAX;
        if(i>1)
        r=dp[i-2]+abs(height[i-2]-height[i]);
        dp[i]=min(l,r);
    }
    return dp[n-1];
}

int frogJump1(int height[],int n) //space optimization
{
    int prev=0; //base case
    int prev1=0;
    for(int i=1;i<n;i++)
    {
        int l=prev+abs(height[i]-height[i-1]);
        int r=INT_MAX;
        if(i>1)
        r=prev1+abs(height[i-2]-height[i]);
        prev1=prev;
        prev=min(l,r);
    }
    return prev;
}
int main()
{
    int height[]={30,10,60,10,60,50};
    int n=sizeof(height)/sizeof(height[0]);
    vector<int>dp(n+1,-1);
    cout<<minEnergy(height,n-1,dp)<<endl;
    cout<<frogJump(height,n)<<endl;
    cout<<frogJump1(height,n)<<endl;
}