#include<bits/stdc++.h>
using namespace std;
int longestProperPrefixWhichIsSuffix(string s,int n)
{
    for(int len=n-1;len>0;len--)
    {
        bool flag =true;
        for(int i=0;i<len;i++)
        {
            if(s[i]!=s[n-len+i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        return len;
    }
    return 0;
}
void generateLPS(string s,int lps[])
{
    for(int i=0;i<s.length();i++)
    {
        lps[i]=longestProperPrefixWhichIsSuffix(s,i+1);
    }
}
int main()
{
    string s="ababacab";
    int n=s.length();
    int lps[n];
    generateLPS(s,lps);
    for(int i=0;i<s.length();i++)
    cout<<lps[i]<<" ";
}