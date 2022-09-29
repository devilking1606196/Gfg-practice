#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int v,int u)
{
    adj[v].push_back(u);
}
bool dfs(vector<int>adj[],bool visited[],bool recVis[],int s)
{
    visited[s]=true;
    recVis[s]=true;
    for(auto i:adj[s])
    {
        if(!visited[i]&&dfs(adj,visited,recVis,i))
        {
            return true;            
        }
        else if(recVis[i])
        {
            return true;
        }
    }
    recVis[s]=false;
    return false;
}
bool detectLoop(vector<int> adj[],int v)
{
    bool visited[v]={false};
    bool recVis[v]={false};
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        if(dfs(adj,visited,recVis,i))
        return true;
    }
    return false;
}
int main()
{
    int v=6;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,3);
    cout<<boolalpha<<detectLoop(adj,v);
}