#include<bits/stdc++.h>
using namespace std;
int uniquePath(int x,int y)
{
    if(x==0&&y==0)
    return 1;
    if(x<0||y<0)
    return 0;
    int left=uniquePath(x,y-1);
    int up=uniquePath(x-1,y);
    return left+up;
}
int uniqueMemorization(int x,int y,vector<vector<int>> &dp)
{
    if(x==0&&y==0)
    return 1;
    if(x<0||y<0)
    return 0;
    if(dp[x][y]!=-1)
    return dp[x][y];
    int l=uniqueMemorization(x,y-1,dp);
    int u=uniqueMemorization(x-1,y,dp);
    return dp[x][y]=l+u;
}
int uniqueTabulation(int x,int y)
{
    int n=x+1;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        dp[0][i]=1;
        dp[i][0]=1;
    }
    for(int ix=1;ix<n;ix++)
    {
        for(int iy=1;iy<n;iy++)
        {
            int l=dp[ix][iy-1];
            int u=dp[ix-1][iy];
            dp[ix][iy]=l+u;
        }
    }
    return dp[x][y];
}
int uniqueSpaceOptimization(int n)
{
    if(n==1)
    return 1;
    vector<int> left(n,1);
    vector<int> up(n,1);
    for(int x=1;x<n;x++)
    {
        for(int y=1;y<n;y++)
        {
            int l=left[y];
            int u=up[x];
            left[y]=up[x]=l+u;
        }
    }
    return left[n-1];
}
int main()
{
    int side=4;
    vector<vector<int>> dp(side,vector<int>(side,-1));
    cout<<uniquePath(side-1,side-1)<<endl;
    cout<<uniqueMemorization(side-1,side-1,dp)<<endl;
    cout<<uniqueTabulation(side-1,side-1)<<endl;
    cout<<uniqueSpaceOptimization(side)<<endl;
}