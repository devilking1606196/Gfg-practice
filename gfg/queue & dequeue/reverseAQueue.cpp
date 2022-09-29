#include<bits/stdc++.h>
using namespace std;
void revreseQueue(queue<int> &q)
{
    stack <int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void recursiveReverse(queue<int> &q)
{
    if(q.empty())
    {
        return;
    }
    int top=q.front();
    q.pop();
    recursiveReverse(q);
    q.push(top);
}
int main()
{
    queue <int> q;
    for(int i=0;i<5;i++)
    q.push(i+1);
    revreseQueue(q);
    recursiveReverse(q);
    while (q.empty()==false)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}