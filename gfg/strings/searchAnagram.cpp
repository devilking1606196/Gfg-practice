#include<bits/stdc++.h>
using namespace std;
void searchAnagram(string s1,string s2)
{
    for(int i=0;i<=s1.length()-s2.length();i++)
    {
        int Char[128]={0};
        bool flag=true;
        for(int j=0;j<s2.length();j++)
        {
            Char[s2[j]]++;
            Char[s1[i+j]]--;
        }
        for(int j=0;j<128;j++)
        {
            if(Char[j]!=0)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        cout<<i<<" ";
    }
}
bool checkAnagram(string s1,string s2)
{
    int count[128]={0};
    int n=s1.length(),m=s2.length();
    for(int i=0;i<m;i++)
    {
        count[s2[i]]++;
        count[s1[i]]--;
    }
    for(int i=0;i<n-m;i++)
    {
        bool flag=true;
        for(int j=0;j<128;j++)
        {
            if(count[j]!=0)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        return true;
        count[s1[i]]++;
        count[s1[i+m]]--;
    }
    return false;
}
int main()
{
    string s1="geeksforgeeksfrogs";
    string s2="frog";
    searchAnagram(s1,s2);
    cout<<endl<<checkAnagram(s1,s2);
}