#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n,vector<int> &dp)
{
    if(n<=1)
    {
        return n;
    }
    if(dp[n]!=-1)
    return dp[n];
    
    dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibonacci(n,dp)<<endl;
    int p1=0,p=1;
    if(n<1)
    cout<<p1;
    else
    {for(int i=2;i<=n;i++)
    {
        int curi=p1+p;
        p1=p;
        p=curi;
    }
    cout<<p;}
}