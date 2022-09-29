#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
class AdjListNode
{
    int v;
    int weight;
    public:
    AdjListNode(int _v,int _w)
    {
        v=_v;
        weight=_w;
    }
    int getv(){return v;}
    int getw(){return weight;}
};
class Graph
{
    int u;
    list<AdjListNode> *adj;
    void topologicalSort(int v,bool visited[],stack<int>&st);
    public:
    Graph(int V);
    void addEdge(int u,int v,int w);
    void shortestPath(int s);
};
Graph::Graph(int V)
{
    this->u=V;
    adj=new list<AdjListNode>[V];
}
void Graph::addEdge(int u,int v,int w)
{
    AdjListNode node(v,w);
    adj[u].push_back(node);
}
void Graph::topologicalSort(int v,bool visited[],stack<int>&st)
{
    visited[v]=true;
    for(auto i:adj[v])
    {
        if(!visited[i.getv()])
        topologicalSort(i.getv(),visited,st);
    }
    st.push(v);
}
void Graph::shortestPath(int s)
{
    stack<int>st;
    bool visited[this->u]={false};
    int dis[u];
    for(int i=0;i<u;i++)
    {
        dis[i]=INF;
    }
    dis[s]=0;
    topologicalSort(s,visited,st);
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        list<AdjListNode>::iterator i;
        if(dis[u]!=INF)
        {
            for(i=adj[u].begin();i!=adj[u].end();i++)
            {
                if(dis[i->getv()]>dis[u]+i->getw())
                {
                    dis[i->getv()]=dis[u]+i->getw();
                }
            }
        }
    }
    for(int i=0;i<u;i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Graph g(6);
    g.addEdge(0, 1, 2); 
	g.addEdge(0, 4, 1); 
	g.addEdge(1, 2, 3); 
	g.addEdge(4, 2, 2); 
	g.addEdge(4, 5, 1); 
	g.addEdge(2, 3, 6); 
	g.addEdge(5, 3, 1);
    g.addEdge(5,2,1);
    int s=0;
    g.shortestPath(s);
}