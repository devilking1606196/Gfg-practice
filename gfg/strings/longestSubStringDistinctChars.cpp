#include<bits/stdc++.h>
using namespace std;
int longestSubStringWithDistinctCharacters(string s)
{
    int n=s.length(),ans=0;
    for(int i=0;i<n;i++)
    {
        bool visited[256]={false};
        int c=0;
        for(int j=i;j<n;j++)
        {
            if(visited[s[j]])
            {
                break;
            }
            else
            {
                visited[s[j]]=true;
                c++;
                ans=max(ans,c);
            }

        }
    }
    return ans;
}
int DistinctLenght(string s)
{
    vector<int> visited(256,-1);
    int start=0,res=0;
    for(int i=0;i<s.length();i++)
    {
        if(visited[s[i]]<0)
        {
            visited[s[i]]=i;
        }
        else
        {
            if(visited[s[i]]+1>=start)
            {
                res=max(res,i-start);
                start=visited[s[i]]+1;
            }
            visited[s[i]]=i;
        }
    }
    return res;
}
int main()
{
    string s="abaacdbab";
    cout<<longestSubStringWithDistinctCharacters(s)<<endl<<DistinctLenght(s);
}