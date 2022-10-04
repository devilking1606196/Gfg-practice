#include<bits/stdc++.h>
using namespace std;
void printIndexOfPattern(string s,string s1)
{
    bool ans=true;
    for(int i=0;i<s.length()-s1.length()+1;i++)
    {
        if(s[i]==s1[0])
        {
            bool flag=true;
            for(int j=1;j<s1.length();j++)
            {
                if(s[i+j]!=s1[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                ans=false;
                cout<<i<<" ";
            }
        }
    }
    if(ans)
    cout<<"Not Present";
}
void printIndexOfAllPattern(string &s,string &s1)
{
    int pos=s.find(s1);
    while(pos!=string::npos)
    {
        cout<<pos<<" ";
        pos=s.find(s1,pos+1);
    }
}
int main()
{
    string s="geeksforgeeks";
    string s1="eeks";
    printIndexOfPattern(s,s1);
    cout<<endl;
    printIndexOfAllPattern(s,s1);
}