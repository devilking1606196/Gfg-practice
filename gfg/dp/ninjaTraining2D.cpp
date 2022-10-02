#include<bits/stdc++.h>
using namespace std;
int maxPoints(vector<vector<int>> task,int day,int last,vector<vector<int>> &dp)
{
    if(day==0)
    {
        int maxi=INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            maxi=max(maxi,task[day][i]);
        }
        return maxi;
    }
    if(dp[day][last]!=-1)
    return dp[day][last];
    int maxi=INT_MIN;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            int point=task[day][i]+maxPoints(task,day-1,i,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
}
int maxTabulation(vector<vector<int>> task)
{
    int n=task.size();
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0]=max(task[0][1],task[0][2]);
    dp[0][1]=max(task[0][0],task[0][2]);
    dp[0][2]=max(task[0][1],task[0][0]);
    dp[0][3]=max(dp[0][0],task[0][0]);
    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                {
                    int point=task[day][i]+dp[day-1][i];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}
int maxSpaceOptimized(vector<vector<int>> task)
{
    vector<int> prevDp(4,0);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i!=j)
            prevDp[i]=max(prevDp[i],task[0][j]);
        }
    }
    for(int day=1;day<task.size();day++)
    {
        vector<int> currDp(4,0);
        for(int last=0;last<4;last++)
        {
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                {
                    int point=task[day][i]+prevDp[i];
                    currDp[last]=max(currDp[last],point);
                }
            }
        }
        prevDp=currDp;
    }
    return prevDp[3];
}
int main()
{
    vector<vector<int>> task={
        {2,1,3},
        {6,4,3},
        {10,1,6},
        {8,3,7}
    };
    int n=task.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
    cout<<maxPoints(task,n-1,3,dp)<<endl;
    cout<<maxTabulation(task)<<endl;
    cout<<maxSpaceOptimized(task)<<endl;
}