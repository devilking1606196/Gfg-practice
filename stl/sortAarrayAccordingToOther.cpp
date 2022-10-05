#include<bits/stdc++.h>
using namespace std;
void sortArray(int a[],char b[],int n)
{
    pair<int,char>p[n];
    for(int i=0;i<n;i++)
    {
        p[i]={a[i],b[i]};
    }
    sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        cout<<p[i].second<<" ";
    }
}
int main()
{
    int a[]={3,1,2,2};
    char b[]={'g','e','k','q'};
    int n=sizeof(a)/sizeof(a[0]);
    sortArray(a,b,n);
}