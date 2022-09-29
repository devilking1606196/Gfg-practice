#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v,int indegree[])
{
    adj[u].push_back(v);
    indegree[v]++;
}
bool detectCycle(vector<int>adj[],int indegree[],int v)
{
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        count++;
        int t=q.front();
        q.pop();
        for(auto i:adj[t])
        {
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
    return count!=v;
}
int main()
{
    int v=5;
    vector<int>adj[v];
    int indegree[v]={0};
    addEdge(adj,0,1,indegree);
    addEdge(adj,4,0,indegree);
    addEdge(adj,1,2,indegree);
    addEdge(adj,2,3,indegree);
    addEdge(adj,3,1,indegree);
    cout<<detectCycle(adj,indegree,v);    
}