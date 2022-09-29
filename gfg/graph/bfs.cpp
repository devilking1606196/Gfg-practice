#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int size,int source)
{
    bool visited[size]={false};
    queue<int>q;
    q.push(source);
    visited[source]=true;
    while(!q.empty())
    {
        int ind=q.front();
        q.pop();
        cout<<ind<<" ";
        for(int i:adj[ind])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    vector<int> adj[5];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,3,4);
    int size=adj->size();
    bfs(adj,size,4);

}