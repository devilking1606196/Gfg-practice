#include <bits/stdc++.h>
using namespace std;
int indexOfNonrepaet(string s)
{
    for(int i=0;i<s.length();i++)
    {
        bool flag=false;
        for(int j=0;j<s.length();j++)
        {
            if(i!=j && s[i]==s[j])
            {
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            return i;
        }
    }
    return -1;
}
int indexOfNonRepaeatingCahr(string &s)
{ 
    int count[128]={0};
    for(int i=0;i<s.length();i++)
    {
        count[s[i]]++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(count[s[i]]==1)
        {
            return i;
        }
    }
    return -1;
}
int indexOneTraversalOfString(string s)
{
    int Char=256;
    int count[Char];
    fill(count,count+Char,-1);
    for(int i=0;i<s.length();i++)
    {
        if(count[s[i]]==-1)
        {
            count[s[i]]=i;
        }
        else if(count[s[i]]>=0)
        {
            count[s[i]]=-2;
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<Char;i++)
    {
        if(count[i]>=0)
        ans=min(ans,count[i]);
    }
    return ans==INT_MAX?-1:ans;
}
int main()
{
    string s="geeksforgeeks";
    cout<<indexOfNonRepaeatingCahr(s)<<endl<<indexOfNonrepaet(s)<<endl<<indexOneTraversalOfString(s);
}
