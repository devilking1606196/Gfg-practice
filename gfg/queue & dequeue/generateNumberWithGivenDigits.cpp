#include<bits/stdc++.h>
using namespace std;
void printFirstNnumbers(int n)
{
    queue<string> q;
    q.push("1");
    q.push("2");
    q.push("3");
    q.push("4");
    q.push("5");
    q.push("6");
    q.push("7");
    q.push("8");
    q.push("9");
    for(int i=0;i<n;i++)
    {
        string s=q.front();
        q.pop();
        cout<<s<<" ";
        q.push(s+"0");
        q.push(s+"1");
        q.push(s+"2");
        q.push(s+"3");
        q.push(s+"4");
        q.push(s+"5");
        q.push(s+"6");
        q.push(s+"7");
        q.push(s+"8");
        q.push(s+"9");
    }
}
int main()
{
    printFirstNnumbers(50);
}