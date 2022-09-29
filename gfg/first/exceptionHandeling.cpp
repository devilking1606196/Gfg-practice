#include<bits/stdc++.h>
using namespace std;
int averagecalc(int arr[],int n)
{
    if(n==0)
    {
        throw string("Array size is zero");
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum/n;
}
void f1()
{
    cout<<"f1 begins"<<endl;
    throw int(23);
    cout<<"f1 ends"<<endl;
}
void f2()
{
    cout<<"f2 begins"<<endl;
    f1();
    cout<<"f2 ends"<<endl;
}
int main()
{
    int arr[]={1,2,3,4,5};
    int n=0;
    // try 
    // {
    //     int ans=averagecalc(arr,n);
    //     cout<<ans;
    // }
    // catch (string &s)
    // {
    //     cout<<s;
    // }
    try 
    {
        f2();
    }
    catch(int i)
    {
        cout<<"caught exception";
    }
    cout<<endl<<"bye"<<endl;
    // cout<<typeid(arr).name();
    vector <int> v={0X1A,2,3,4,5,6};
    for(int i:v)
    {
        cout<<i<<" ";
    }
}