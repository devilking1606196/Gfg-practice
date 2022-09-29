#include<bits/stdc++.h>
using namespace std;
void reverseWordsInString(string &s)
{
    stack<string> words;
    string temp="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            words.push(temp);
            temp="";
        }
        else
        {
            temp+=s[i];
        }
    }
    words.push(temp);
    s="";
    while(!words.empty())
    {
        if(words.size()>1)
        {
            s=s+words.top()+" ";
        }
        else
        {
            s+=words.top();
        }
        words.pop();
    }
}
void stringReverse(string &s,int low,int high)
{
    while(low<high)
    {
        swap(s[low],s[high]);
        low++;high--;
    }
}
void reverseString(string &s)
{
    int start=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            stringReverse(s,start,i-1);
            start=i+1;
        }
    }
    stringReverse(s,start,s.length()-1);
    stringReverse(s,0,s.length()-1);
}
int main()
{
    string s="I love coding";
    reverseWordsInString(s);
    cout<<s;
    reverseString(s);
    cout<<endl<<s;
}
