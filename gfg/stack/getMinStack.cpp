#include<bits/stdc++.h>
using namespace std;
struct getMin //O(N) space
{
    stack<int>ms;
    stack<int>as;
    void push(int data)
    {
        ms.push(data);
        if(as.empty()||as.top()>=data)
        as.push(data);
    }
    void pop()
    {
        if(as.top()==ms.top())
        as.pop();
        ms.pop();
    }
    int getmin()
    {
        // if(!as.empty())
        return as.top();
    }
};
struct GetMin  //O(1)space for + enteris only
{
    stack<int> s;
    int min;
    void push(int data)
    {
        if(s.empty())
        {
            s.push(data);
            min=data;
            return;
        }
        if(data<min)
        {
            s.push(data-min);
            min=data;
        }
        else
        {
            s.push(data);
        }
    }
    int pop()
    {
        if(s.empty())
        {
            cout<<"empty";
            exit(0);
        }
        if(s.top()<0)
        {
            int item=min;
            min-=s.top();
            s.pop();
            return item;
        }
        else
        {
            int item=s.top();
            s.pop();
            return item;
        }
    }
    int getmin()
    {
        return min;
    }
};
struct getMIN
{
    stack<int>s;
    int min;
    void push(int data)
    {
        if(s.empty())
        {
            s.push(data);
            min=data;
        }
        else if(s.top()>data)
        {
            s.push(2*data-min);
            min=data;
        }
        else
        {
            s.push(data);
        }
    }
    int pop()
    {
        if(s.empty())
        {
            cout<<"empty";
            exit(0);
        }
        int tp=s.top();
        s.pop();
        if(tp<min)
        {
            int res=min;
            min=2*min-tp;
            return res;
        }
        else
        {
            return tp;
        }
    }
    int getmin()
    {
        if(s.empty())
        {
            cout<<"no item in stack";
            exit (0);
        }
        return min;
    }
};
int main()
{
    getMIN s;
    s.push(5);
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    // cout<<s.getmin()<<endl;
    s.push(4);
    s.push(9);
    cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    cout<<s.getmin()<<endl;
}