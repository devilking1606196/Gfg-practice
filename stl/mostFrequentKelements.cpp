#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second==p2.second)
    return p1.first<p2.first;
    return p1.second>p2.second;
}
class myComp
{
    public:
    bool operator()(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
        return p1.first>p2.first;
        return p1.second<p2.second;
    }
};
void printKmostFrequentElements(vector<int>v,int k)
{
    unordered_map<int,int>m;
    for(int i=0;i<v.size();i++)
    {
        m[v[i]]++;
    }
    vector<pair<int,int>>vp(m.begin(),m.end());
    sort(vp.begin(),vp.end(),compare);
    for(int i=0;i<k;i++)
    {
        cout<<vp[i].first<<" ";
    }
    cout<<endl;
}
void printUsingPriorityQueue(vector<int>v,int k)
{
    unordered_map<int,int>m;
    for(int i=0;i<v.size();i++)
    {
        m[v[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,myComp>pq(m.begin(),m.end());
    for(int i=0;i<k;i++)
    {
        cout<<pq.top().first<<" ";
        pq.pop();
    }
    cout<<endl;
}
void kMostFrequentElelments(vector<int>v,int k) // according to order of occurence 
{
    unordered_map<int,int>m;
    for(int i:v)
    m[i]++;
    vector<int> freq[v.size()+1];
    for(int i:v)
    {
        int ind=m[i];
        if(ind!=-1)
        {
            freq[ind].push_back(i);
            m[i]=-1;
        }
    }
    int count=0;
    for(int i=v.size();i>=0;i--)
    {
        for(auto j:freq[i])
        {
            if(count>=k)
            break;
            cout<<j<<" ";
            count++;
        }
    }
}
int main()
{
    vector<int>v={10,5,20,20,22,5,5,30};
    int k=3;
    printKmostFrequentElements(v,k);
    printUsingPriorityQueue(v,k);
    kMostFrequentElelments(v,k);
}