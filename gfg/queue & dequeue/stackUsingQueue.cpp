#include<bits/stdc++.h>
using namespace std;
struct stackUsingQueue
{
    queue<int> q1,q2;
    void push(int data)
    {
        if(q1.empty())
        {
            q1.push(data);
        }
        else
        {
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(data);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    int pop()
    {
        if(q1.empty())
        {
            cout<<"stack empty";
            exit(0);
        }
        int t=q1.front();
        q1.pop();
        return t;
    }
};
int main()
{
    stackUsingQueue s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
}