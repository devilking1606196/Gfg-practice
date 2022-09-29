#include<bits/stdc++.h>
using namespace std;
void printCeil(int arr[],int n)
{
    set<int>s;
    for(int i=0;i<n;i++)
    {
        if(s.lower_bound(arr[i])==s.end())
        {
            cout<<"-1"<< " ";
        }
        else
        {
            cout<<*s.lower_bound(arr[i])<<" ";
        }
        s.insert(arr[i]);
    }
    return;
}
int main()
{
    int arr[]={2,8,30,15,25,12};
    int size=sizeof(arr)/sizeof(arr[0]);
    printCeil(arr,size);
}