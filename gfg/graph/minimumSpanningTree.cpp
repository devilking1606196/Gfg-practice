// i.e. to convert a undirected graph into a tree that is to remove the cycle here to find the minimum spanning tree
//PRIM'S Algorithm
#include<bits/stdc++.h>
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
    int V;
    list<AdjListNode> *adj;
    void topologicalSort(int topo[],bool visited[],int s);
    public:
    Graph(int v)
    {
        V=v;
        adj=new AdjListNode[v];
    }
    void addEdge(int u,int v,int w);
    int minSpanningTree(int s);
};
void Graph:: topologicalSort(vector<int> topo[],bool visited[],int s)
{
    stack<int>st;
    st.push(s);
    visited[s]=true;
    int i=0;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        topo[i]=u;
        for(auto j:adj[u])
        {
            if(!visited[j.getv()])
            {
                visited[j.getv()]=true;
                st.push(j.getv());
            }
        }
        i++;
    }
} 
void Graph::addEdge(int u,int v,int w)
{
    AdjListNode node1(v,w);
    AdjListNode node2(u,w);
    adj[u].push_back(node1);
    adj[v].push_back(node2);
}
int Graph::minSpanningTree(int s)
{
    bool  visited[V]={false};
    stack<int>st;
    visited[s]=true;
    st.push(s);
    while(!st.empty())
    {
        
    }
}
int main()
{
    Graph g(4);
    g.addEdge(0,1,5);
    g.addEdge(0,2,8);
    g.addEdge(2,3,8);
    g.addEdge(0,3,10);
    g.addEdge(1,3,7);

}