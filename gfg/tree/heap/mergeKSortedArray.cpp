#include<bits/stdc++.h>
using namespace std;
struct Triplet
{
    int val;
    int num;
    int indx;
    Triplet(int a,int b,int c)
    {
        val=a;num=b;indx=c;
    }
};
struct MyComp
{
    bool operator()(Triplet &t1,Triplet &t2)
    {
        return t1.val>t2.val;
    }
};

vector<int> mergeKSortedArray(vector<vector<int>> &v)
{
    priority_queue<Triplet,vector<Triplet>,MyComp>pq;
    vector<int> res;
    for(int i=0;i<v.size();i++)
    {
        Triplet t(v[i][0],i,0);
        pq.push(t);
    }
    while(!pq.empty())    
    {
        Triplet curr=pq.top();
        pq.pop();
        res.push_back(curr.val);
        int a=curr.indx;
            a++;
        if(a<v[curr.num].size())
        {
            Triplet t(v[curr.num][a],curr.num,a);
            pq.push(t);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>>v={{10,20,30},
                          {5,15},
                          {1,9,11,18}};
    vector<int> ans=mergeKSortedArray(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}