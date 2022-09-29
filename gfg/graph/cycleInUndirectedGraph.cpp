#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v) //u & v are points of connection
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool dfsRec(vector<int>adj[],int s,int parent,bool visited[])
{
    visited[s]=true;
    for(auto i:adj[s])
    {
        if(!visited[i])
        {
            if(dfsRec(adj,i,s,visited))
            return true;
        }
        else if(parent!=i)
        {
            return true;
        }
    }
    return false;
}
bool detectLoop(vector<int>adj[],int v,int s)
{
    bool visited[v]={false};
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            if(dfsRec(adj,i,-1,visited)==true)
            return true;
        }
    }
    return false;
}
bool bfs(vector<int>adj[],int s,bool visited[],int v)
{
    vector<int> parent(v,-1);
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int curr=q.front();q.pop();
        for(int i:adj[curr])
        {
            if(!visited[i])
            {
                visited[i]=true;
                parent[i]=curr;
                q.push(i);
            }
            else if(parent[curr]!=i)
            {
                return true;
            }
        }
    }
    return false;
}
bool loopDetectUsinfBfs(vector<int>adj[],int v,int s)
{
    bool visited[v]={false};
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            if(bfs(adj,i,visited,v))
            return true;
        }
    }
    return false;
}
int main()
{
    int v=6;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,5,4);
    cout<<boolalpha<<detectLoop(adj,v,0)<<endl<<loopDetectUsinfBfs(adj,v,0)<<endl;
}