#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    int ans=1;
    if(n==0)
    return 1;
    while(n>0)
    {
        ans*=n;
        n--;
    }
    return ans;
}
int lexoRankOfString(string s)
{
    int ans=0;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=i+1;j<n;j++)
        {
            if(s[j]<s[i])
            count++;
        }
        ans+=count*fact(n-i-1);
    }
    return ans+1;
}
int lexoRank(string s) //O(N)
{
    int ans=0;
    int n=s.length(),count[128]={0};
    int small=fact(n);
    for(int i=0;i<n;i++)
    {
        count[s[i]]++;
    }
    for(int i=1;i<128;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=0;i<n;i++)
    {
        small/=n-i;
        ans+=count[s[i]-1]*small;
        for(int j=s[i];j<128;j++)
        count[j]--;
    }
    return ans+1;
}
int main()
{
    string s="silent";
    cout<<lexoRankOfString(s)<<endl<<lexoRank(s);
}