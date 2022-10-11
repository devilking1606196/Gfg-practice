#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> p1,pair<int,int>p2)
{
    double r1=(double)p1.second/p1.first;
    double r2=(double)p2.second/p2.first;
    return (r1>r2);
}
double maximumCapacity(int weight[],int value[],int cap,int n)
{
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++)
    {
        vp.push_back({weight[i],value[i]});
    }
    sort(vp.begin(),vp.end(),cmp);
    double ans=0.0;
    int i=0;
    while(i<n&&(cap-vp[i].first>=0))
    {
        ans+=vp[i].second;
        cap-=vp[i].first;
        i++;
    }
    if(i<n&&cap>0)
    {
        ans+=double(vp[i].second*cap)/vp[i].first;
    }
    return ans;
}
int main()
{
    int weight[]={11,5,13};
    int value[]={200,50,100};
    int n=sizeof(weight)/sizeof(weight[0]);
    int cap=23;
    cout<<maximumCapacity(weight,value,cap,n)<<endl;
}