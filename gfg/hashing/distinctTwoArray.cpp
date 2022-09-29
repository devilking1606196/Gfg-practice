#include<bits/stdc++.h>
using namespace std;
void print (int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
cout<<endl;
}
int countDistinct(int a[],int b[],int n1,int n2)
{
    int c=0;
    int t=INT_MIN;
    sort(a,a+n1);
    sort(b,b+n2);
    for(int i=0;i<n1;i++)
    {
        if(t!=a[i])
        if(binary_search(b,b+n2,a[i]))
        {
            cout<<a[i]<<" ";
            t=a[i];c++;
        }
    }
    cout<<endl;
    return c;
}
int countDisUsingHashing(int a[],int b[],int n1,int n2)
{
    int res=0;
    unordered_set <int> s(a,a+n1);
    for(int i=0;i<n2;i++)
    {
        if(s.find(b[i])!=s.end())
        {
            res++;
            s.erase(b[i]);
        }
    }
    return res;
}
int countDistinctInOneArray(int a[],int n)//distinct elements in a array
{
    unordered_set<int> s(a,a+n);
    return s.size();
}
int main()
{
    int a[]={10,15,5,20,30};
    int b[]={30,5,30,80};
    int n1=sizeof(a)/sizeof(a[0]);
    int n2=sizeof(b)/sizeof(b[0]);
    // cout<<countDistinct(a,b,n1,n2);
    cout<<countDisUsingHashing(a,b,n1,n2);//common in two arrays
    cout<<countDistinctInOneArray(a,n1);
}