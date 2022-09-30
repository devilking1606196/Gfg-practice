#include<bits/stdc++.h>
using namespace std;
int KjumpFrog(vector<int> height,int n,int k)
{
    if(n==0)
    return 0;
    int jumps=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        jumps=min(jumps,KjumpFrog(height,n-i,k)+abs(height[n-i]-height[n]));
    }
    return jumps;
}
int KjumpFrogDP(vector<int> height,int n,int k,vector<int> &dp) //using dp
{
    if(n==0)
    return 0;
    if(dp[n]!=-1)
    return dp[n];
    int jumps=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        jumps=min(jumps,KjumpFrogDP(height,n-i,k,dp)+abs(height[n-i]-height[n]));
    }
    dp[n]=jumps;
    return jumps;
}
int main()
{
    vector<int> height={10,20,50,30,10,25,23};
    int k=4;
    cout<<KjumpFrog(height,height.size()-1,k)<<endl;
    vector<int>dp(height.size()+1,-1);
    cout<<KjumpFrogDP(height,height.size()-1,k,dp)<<endl;
    vector<int>d(height.size(),INT_MAX);
    d[0]=0;
    for(int i=1;i<height.size();i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            d[i]=min(d[i],d[i-j]+abs(height[i]-height[i-j]));
        }
    }
    cout<<d[height.size()-1]<<endl;
}