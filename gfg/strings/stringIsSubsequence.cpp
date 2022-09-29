#include<bits/stdc++.h>
using namespace std;
void generateSubstring(string s)
{
    int n=pow(2,s.length());
    for(int i=0;i<n;i++)
    {
        string substr="";
        int j=i,c=0;
        while(j>0)
        {
            if(j%2==1)
            {
                substr+=s[c];
            }
            j/=2;
            c++;
        }
        cout<<substr<<endl;
    }
}
bool isSubSequence(string s1,string s2)
{
    int n=pow(2,s1.length());
    for(int i=0;i<n;i++)
    {
        string substr="";
        int j=i,c=0;
        while(j>0)
        {
            if(j%2)
            {
                substr+=s1[c];
            }
            j/=2;
            c++;
        }
        if(substr==s2)
        return true;
    }
    return false;
}
bool subsequence(string &s1,string &s2)
{
    int i=0,j=0;
    while(i<s1.length()&&j<s2.length())
    {
        if(s1[i]==s2[j])
        {
            i++;j++;
        }
        else
        {
            i++;
        }
    }
    if(j==s2.length())
    return true;
    else
    return false;
}
bool seq(string s1,string s2,int n,int m)
{
    if(m==0)
    {
        return true;
    }
    if(n==0)
    {
        return false;
    }
    if(s1[n-1]==s2[m-1])
    {
        return seq(s1,s2,n-1,m-1);
    }
    else
    {
        return seq(s1,s2,n-1,m);
    }
}
int main()
{
    string s="abcd";
    string s2="ad";
    // generateSubstring(s);
    // cout<<endl;
    cout<<isSubSequence(s,s2)<<" "<<subsequence(s,s2)<<" "<<seq(s,s2,s.length(),s2.length());
}