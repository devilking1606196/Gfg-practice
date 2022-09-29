#include<bits/stdc++.h>
using namespace std;
void distinct(int arr[],int size,int k)
{
    for(int h=0;h<size-k+1;h++)
    {
        int c=0;
        for(int i=h;i<h+k;i++)
        {
            int n=arr[i];
            bool b=false;
            for(int j=i-1;j>=h;j--)
            {
                if(n==arr[j])
                b=true;
            }
            if(!b)
            {
                c++;
            }
        }
        cout<<c<<" ";
    }
}
void ditinctElementsInWindow(int arr[],int size,int k)
{
    unordered_map<int,int> m;
    for(int j=0;j<k;j++)
        {
            m[arr[j]]++;
        }
    for(int i=0;i<size-k+1;i++)
    {
        cout<<m.size()<<" ";
        m[arr[i]]--;
        if(m[arr[i]]==0)
        {
            m.erase(arr[i]);
        }
        m[arr[i+k]]++;
    }
}
int main()
{
    int arr[]={10,20,20,10,30,40,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    ditinctElementsInWindow(arr,size,k);cout<<endl;
    distinct(arr,size,k);
}