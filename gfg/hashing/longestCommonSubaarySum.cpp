#include<bits/stdc++.h>
using namespace std;
int longestWithSum(int a[],int b[],int size)
{
    int ans=0;
    int t[size];
    for(int i=0;i<size;i++)
    {
        t[i]=a[i]-b[i];
    }
    int psum=0;
    unordered_map<int,int> m;
    for(int i=0;i<size;i++)
    {
        psum+=t[i];
        if(psum==0)
        {
            ans=max(ans,i+1);
        }
        if(m.find(psum)==m.end())
        {
            m.insert({psum,i});
        }
        if(m.find(psum)!=m.end())
        {
            ans=max(ans,i-m[psum]);
        }
    }
    return ans;
}
int longestCommonSpanSubarrayWithGivenSum(int a[],int b[],int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
    {
        int s1=0,s2=0;
        for(int j=i;j<size;j++)
        {
            s1+=a[j];
            s2+=b[j];
            if(s1==s2)
            {
                ans=max(ans,j-i+1);
            }
        }
    }
    return ans;
}
int main()
{
    int a[]={0,1,0,1,1,1,1};
    int b[]={1,1,1,1,1,0,1};
    int size=sizeof(a)/sizeof(a[0]);
    cout<<longestCommonSpanSubarrayWithGivenSum(a,b,size)<<endl<<longestWithSum(a,b,size);
}