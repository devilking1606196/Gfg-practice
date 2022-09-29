#include<bits/stdc++.h>
using namespace std;
void printSubStr(string s,int n)
{
    int sCount=1<<n;
    for(int i=0;i<sCount;i++)
    {
        string ans=" ";
        for(int j=0;j<n;j++)
        {
            if(((i>>j)&1)==1)
            {
                ans+=s[n-j-1];
            }
        }
        cout<<ans<<" ";
    }
}
int main()
{
    string s="abc";
    printSubStr(s,s.length());
}