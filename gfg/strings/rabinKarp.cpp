#include<bits/stdc++.h>
using namespace std;
void patternSearchUsingRabinKarp(string s1,string s2) //basic Rabin  Karp
{
    int n=s1.length(),m=s2.length();
    int rabinK=0,match=0;
    for(int i=0;i<m;i++)
    {
        rabinK+=s1[i];
        match+=s2[i];
    }
    for(int i=0;i<=n-m;i++)
    {
        if(rabinK==match)
        {
            bool flag=true;
            for(int j=0;j<m;j++)
            {
                if(s1[i+j]!=s2[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                cout<<i<<" ";
            }
        }
        if(i<n-m)
        rabinK=rabinK-s1[i]+s1[i+m];
    }
}

// Advance Rabin Karp ******************************************************************************
void advanceRabinKarp(string s1,string s2)
{
    int  h=1;int d='e';//d=5
    int q=7919;
    int n=s1.length(),m=s2.length();
    for(int i=0;i<m-1;i++)
    {
        h=(h*d)%q;
    }
    int match=0,rabinK=0;
    for(int i=0;i<m;i++)
    {
        rabinK=(d*rabinK+s1[i])%q;
        match=(d*match+s2[i])%q;
    }
    for(int i=0;i<=n-m;i++)
    {
        // cout<<match<<" "<<rabinK<<endl;
        if(match==rabinK)
        {
            bool flag=true;
            for(int j=0;j<m;j++)
            {
                if(s1[i+j]!=s2[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                cout<<i<<" ";
            }
        }
        if(i<n-m)
        {
            rabinK=(d*(rabinK-s1[i]*h)+s1[i+m])%q;
            if(rabinK<0)
            rabinK+=q;
        }
    }

}
int main()
{
    string s="geeksforgeeks";
    string s1="eks";
    patternSearchUsingRabinKarp(s,s1);
    cout<<endl;
    advanceRabinKarp(s,s1);
}