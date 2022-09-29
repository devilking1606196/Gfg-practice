#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfsRec(vector<int>adj[],int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(auto i:adj[s])
    {
        if(!visited[i])
        dfsRec(adj,i,visited);
    }
}
void dfs(vector<int> adj[],int v,int s)
{
    // int count=0;  //for no. of disconnections
    bool visited[v]={false};
    for(int i=0;i<v;i++)  // work for both disconnected and normal
    {
        if(visited[i]==false)
        dfsRec(adj,i,visited);//{count++;}
    }
    return;
}
int main()
{
    int v=7;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,5,6);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    dfs(adj,v,0);
}