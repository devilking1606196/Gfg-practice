#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int> &v,int indx)
{
    if(indx==0)
    return v[indx];
    if(indx<0)
    return 0;
    int pick=v[indx]+maxSum(v,indx-2);
    int notPick=maxSum(v,indx-1);
    return max(pick,notPick);
}
int maxSumDP(vector<int> &v,int indx,vector<int> &dp)  //memoization
{
    if(indx==0)
    return v[indx];
    if(indx<0)
    return 0;
    if(dp[indx]!=-1)
    return dp[indx];
    int pick=v[indx]+maxSumDP(v,indx-2,dp);
    int notPick=maxSumDP(v,indx-1,dp);
    return dp[indx]=max(pick,notPick);
}
int maxSumDP1(vector<int> &v,int indx)  //tabulation
{
    vector<int> dp(indx+1,0);
    for(int i=0;i<=indx;i++)
    {
        int pick=(i-2<0)?v[i]:v[i]+dp[i-2];
        int notPick=(i-1<0)?0:dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[indx];
}
int sumOptimized(vector<int> &v,int indx)
{
    int prev1=0,prev=0;  //prev can be v[0] as the base case To start loop from i=1
    for(int i=0;i<=indx;i++)
    {
        int pick=(i-2<0)?v[i]:v[i]+prev1;
        int notPick=(i-1<0)?0:prev;
        int curr=max(pick,notPick);
        prev1=prev;
        prev=curr;
    }
    return prev;
}
int main()
{
    vector<int> v={3,4,5,6,7,12,11,3};
    cout<<maxSum(v,v.size()-1)<<endl;
    vector<int>dp(v.size()+1,-1);
    cout<<maxSumDP(v,v.size()-1,dp)<<endl;
    cout<<maxSumDP1(v,v.size()-1)<<endl;
    cout<<sumOptimized(v,v.size()-1)<<endl;
}