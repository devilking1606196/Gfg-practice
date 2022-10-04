#include<bits/stdc++.h>
using namespace std;
void findTheExtraChar(const string &s1,const string &s2)
{
    char c=s2[s1.length()];
    for(int i=0;i<s1.length();i++)
    {
        c=c^s1[i];
        c^=s2[i];
    }
    cout<<c<<endl;
}
void findExtra(const string &s1,const string &s2)
{
    int count[256]={0};
    for(char i:s2)
    {
        count[i]++;
    }
    for(char i: s1)
    {
        count[i]--;
    }
    for(int i=0;i<256;i++)
    {
        if(count[i]==1)
        {
            cout<<char(i)<<endl;
        }
    }
    return ;
}
int main()
{
    string s1="abcd",s2="abecd";
    findTheExtraChar(s1,s2);
    findExtra(s1,s2);
}