#include<bits/stdc++.h>
using namespace std;
void mergeTwo(int a[],int b[],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[0])
        { 
            pop_heap(b,b+m,greater<int>());
            swap(a[i],b[m-1]);
            push_heap(b,b+m,greater<int>());
        }
    }
    sort(b,b+m);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++)
    cout<<b[i]<<" ";
}
int main()
{
    int a[]={3,7,9,20,40};
    int b[]={2,2,6,10,12,24,54};
    // int b[]={3,6,2,5,45,3,43,23,11};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    mergeTwo(a,b,n,m);
}