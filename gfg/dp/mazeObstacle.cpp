#include<bits/stdc++.h>
using namespace std;
int mod=(int)1e9+7;
int pathThroughMaze(vector<vector<int>> maze,int x,int y,vector<vector<int>> &dp)
{
    if(x<0||y<0)
    return 0;
    if(x==0&&y==0)
    return 1;
    if(maze[x][y]==-1)
    return 0;
    if(dp[x][y]!=-1)
    return dp[x][y];
    int left=pathThroughMaze(maze,x,y-1,dp);
    int up=pathThroughMaze(maze,x-1,y,dp);
    return dp[x][y]=up+left;
}
int pathTabulation(vector<vector<int>> maze)
{
    int x=maze.size();
    int y=maze[0].size();
    vector<vector<int>> dp(x,vector<int>(y,0));
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(maze[i][j]==-1)
            dp[i][j]=0;
            else if(i==0&&j==0&&maze[i][j]!=-1)
            {    
                dp[i][j]=1;
            }
            else
            {
                int l=0,u=0;
                if(j>0)
                    l=dp[i][j-1];
                if(i>0)
                    u=dp[i-1][j];
                dp[i][j]=l+u;
            }
        }
    }
    return dp[x-1][y-1];
}
int pathSpaceOptimized(vector<vector<int>> maze)
{
    int n=maze.size();
    int m=maze[0].size();
    vector<int> prev(n,0);
    for(int i=0;i<n;i++)
    {
        vector<int>curr(n,0);
        for(int j=0;j<m;j++)
        {
            if(maze[i][j]==-1)
            curr[j]=0;
            else if(i==0&&j==0)
            curr[j]=1;
            else
            {
                int l=0,u=0;
                if(j>0)
                l=curr[j-1];
                if(i>0)
                u=prev[j];
                curr[j]=u+l;
            }
        }
        prev=curr;
    }
    return prev[n-1];
}
int main()
{
    vector<vector<int>> maze={
                            {0,0,0},
                            {0,-1,0},
                            {0,0,0}};
    int x=maze.size();
    int y=maze[0].size();
    vector<vector<int>>dp(x,vector<int>(y,-1));
    cout<<pathThroughMaze(maze,x-1,y-1,dp)<<endl;
    cout<<pathTabulation(maze)<<endl;
    cout<<pathSpaceOptimized(maze)<<endl;
}