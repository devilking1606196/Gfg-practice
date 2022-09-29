#include<bits/stdc++.h>
using namespace std;
int leftmostRepeatingChar(string s)
{
    for(int i=0;i<s.length();i++)
    {
        for(int j=i+1;j<s.length();j++)
        {
            if(s[i]==s[j])
            {
                return i;
            }
        }
    }
    return -1;
}
int leftRepeating(string s)
{
    int c=128,ans=INT_MAX;
    int index[c];
    fill(index,index+c,-1);
    for(int i=0;i<s.length();i++)
    {
        if(index[s[i]]==-1)
        {
            index[s[i]]=i;
        }
        else
        {
            ans=min(ans,index[s[i]]);
        }
    }
    return ans==INT_MAX?-1:ans;
}
int main()
{
    string s="~!%'}<>,?/*<>,*";
    cout<<leftmostRepeatingChar(s)<<endl<<leftRepeating(s);
}