//panagram means a string contains all the alphabets of the english in upper or lower case
#include<bits/stdc++.h>
using namespace std;
bool panagramCheck(const string & s)
{
    if(s.length()<26)
    return false;
    int count[26]={0};
    for(char c:s)
    {
        if(tolower(c)>='a'&&tolower(c)<='z')
        count[tolower(c)-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(count[i]==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s="The quick brown Fox jumps over the lazy dog";
    cout<<boolalpha<<panagramCheck(s);
}