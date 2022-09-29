#include<bits/stdc++.h>
using namespace std;
struct kstack
{
    int cap,k,*arr,*nextFree,*top,freeTop;
    kstack(int c,int K)
    {
        freeTop=0;
        k=K;
        cap=c;
        arr=new int[cap];
        nextFree=new int [cap];
        top=new int [K];
        for(int i=0;i<K;i++)
        {
            top[i]=-1;
        }
        for(int i=0;i<cap-1;i++)
        {
            nextFree[i]=i+1;
        }
        nextFree[cap-1]=-1;
    }
    void push(int data,int sn)
    {
        if(freeTop>=cap)
        {
            cout<<"stack full";
            exit (1);
        }
        arr[freeTop]=data;
        int i=freeTop;
        freeTop=nextFree[freeTop];
        nextFree[i]=top[sn];
        top[sn]=i;
    }
    int pop(int sn)
    {
        if(top[sn]==-1)
        {
            cout<<"stack empty";
            exit (1);
        }
        int i=top[sn];
        top[sn]=nextFree[i];
        int res=arr[i];
        nextFree[i]=freeTop;
        freeTop=i;
        return res;
    }
    void printStack(int sn)
    {
        int i=top[sn];
        while(i!=-1)      
        {
            cout<<arr[i]<<" ";
            i=nextFree[i];
        }
        cout<<endl;
    }
};
kstack s(11,3);
void f(){
    for(int i=0;i<s.cap;i++)
    {
        cout<<s.arr[i]<<" ";
    }
    cout<<endl;
    // for(int i=0;i<s.cap;i++)
    // {
    //     cout<<s.nextFree[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<s.k;i++)
    {
        cout<<s.top[i]<<" ";
    }
    cout<<endl;
    s.printStack(0);
    s.printStack(1);
    s.printStack(2);
    }
int main()
{
    
    int a[]={10,20,30,40,50,60,70,80};
    int size=sizeof(a)/sizeof(a[0]);
    int i=0;
    for(;i<size-4;i++)
    {
        s.push(a[i],1);
    }
    for(;i<size-2;i++)
    {
        s.push(a[i],2);
    }
    for(;i<size;i++)
    {
        s.push(a[i],1);
    }
    
    f();
    s.pop(1);
    f();
    
}