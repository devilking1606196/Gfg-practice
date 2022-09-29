#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfs(vector<int> adj[],bool visited[],int s)
{
    visited[s]=true;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int a=q.front();q.pop();
        cout<<a<<" ";
        for(auto i:adj[a])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
void dissBFS(vector<int> adj[],int v)
{
    int ans=0;
    bool visited[v]={false};
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            ans++;
            bfs(adj,visited,i);
        }
    }
    cout<<"\nisland = "<<ans<<endl;
}
int main()
{
    int v=9;   //number of vertices
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,0,3);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,4,6);
    addEdge(adj,5,8);
    addEdge(adj,7,8);
    dissBFS(adj,v);
}