#include<bits/stdc++.h>
using namespace std;
bool anagramCheck(string s1,string s2)
{
    if(s1.length()!=s2.length())
    {
        return false;
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return (s1==s2);
}
bool checkAnagram(string s1,string s2)
{
    if(s1.length()!=s2.length())
    {
        return false;
    }
    const int c=256;    // 128 for ASCII characters
    int count[256]={0};
    for(int i=0;i<s1.length();i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i=0;i<c;i++)
    {
        if(count[i]!=0)
        return false;
    }
    return true;
}
int main()
{
    string s1="hey listen";
    string s2="hey silent";
    cout<<boolalpha<<checkAnagram(s1,s2)<<endl<<anagramCheck(s1,s2);
}