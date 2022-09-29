#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}
void dfs(vector<int>adj[],stack<int>&s,int source,bool visited[])
{
    visited[source]=true;
    for(auto i:adj[source])
    {
        if(!visited[i])
        dfs(adj,s,i,visited);
    }
    s.push(source);
}
void printTopologicalSort(vector<int>adj[],int v)
{
    bool visited[v]={false};
    stack<int>s;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        dfs(adj,s,i,visited);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    int v=5;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,3,4);
    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,3);
    // addEdge(adj,1,3);
    // addEdge(adj,4,3);
    // addEdge(adj,4,5);
    // addEdge(adj,5,6);
    printTopologicalSort(adj,v);
}