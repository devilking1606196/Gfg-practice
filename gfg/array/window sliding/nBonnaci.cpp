#include<bits/stdc++.h>
using namespace std;
void nBonnaci(int n,int terms)
{
    int arr[terms]={0},curr=1;
    arr[n-1]=1;
    arr[n]=1;
    for(int i=n+1;i<terms;i++)
    {
        curr+=arr[i-1]-arr[i-n-1];
        arr[i]+=curr;
    }
    for(int i=0;i<terms;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    nBonnaci(5,20);
}