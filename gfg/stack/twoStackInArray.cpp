#include<bits/stdc++.h>
using namespace std;
struct twoStack
{
    int n,top1,top2;
    int *arr;
    twoStack(int cap)
    {
        top1=-1;
        top2=cap;
        n=cap;
        arr=new int[cap];
    }
    void push1(int data)
    {
        if(top1<top2-1)
        {
            top1++;
            arr[top1]=data;
        }
        else
        {
            cout<<"stack overflow";
            exit (0);
        }
    }
    void push2(int data)
    {
        if(top1<top2-1)
        {
            top2--;
            arr[top2]=data;
        }
        else
        {
            cout<<"stack overflow";
            exit (0);
        }
    }
    int pop1()
    {
        if(top1>=0)
        {
            top1--;
            return arr[top1+1] ;
        }
        else
        {
            cout<<"stack underflow";
            exit (1);
        }
    }
    int pop2()
    {
        if(top2<n)
        {
            top2++;
            return arr[top2-1] ;
        }
        else
        {
            cout<<"stack underflow";
            exit (1);
        }
    }
    void print()
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    twoStack s(5);
    s.push2(11);
    s.push2(10);
    s.push2(12);
    s.push2(13);
    s.push2(11);
    s.print();
    cout<<s.pop2()<<endl;
    s.push1(2);
    s.print();
    cout<<s.top2;
}