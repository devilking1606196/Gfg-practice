#include<bits/stdc++.h>
using namespace std;
bool checkForRotatedString(string s1,string s2)
{
    if(s1.length()!=s2.length())
    return false;
    else
    return ((s1+s1).find(s2)!=string::npos);
}
int main()
{
    string s1="abcde",s2="eabcd";
    cout<<checkForRotatedString(s1,s2);
}