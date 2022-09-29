#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v,int indegree[])
{
    adj[u].push_back(v);
    indegree[v]++;
}

void storeIndegree(vector<int>adj[],int indegee[],int s,bool visited[])
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int curr=q.front();q.pop();
        for(int i:adj[curr])
        {
            if(visited[i]==false)
            q.push(i);
            visited[i]=true;
            indegee[i]++;
        }
    }
}

void printOrder(vector<int>adj[],int indegree[],int v)
{
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto i:adj[curr])
        {
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
}

void printTopologicalOrder(vector<int>adj[],int v)
{
    int indegree[v]={0};
    bool visited[v]={false};
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        storeIndegree(adj,indegree,i,visited);
    }
    printOrder(adj,indegree,v);
    cout<<endl;
}

void printIngere(vector<int>adj[],int v,int indegree[])  //only for acyclic directed graph
{
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(int i:adj[x])
        {
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
    cout<<endl;
}
int noConseBits(int query) {
        int t=query;
        vector<int>ans;
        int c=0,i=0;
        while(t>0)
        {
            
            if(t&1==1)
            {
                i++;
                c++;
            }
            else
            {
                // cout<<c<<" "<<i;
                int f=1;
                while(c>=3)
                {
                    ans.push_back(i-3*f);
                    f++;
                    c-=3;
                }
                i++;
                c=0;
            }
            t=t/2;
        }
        int f=1;
        while(c>=3)
                {
                    ans.push_back(i-3*f);
                    f++;
                    c-=3;
                }
        for(int a : ans)
        {
            cout<<a<<" ";
            query-=pow(2,a);
        }
        return query;
    }
int finLength(int N, vector<int> color, vector<int> radius) {
        stack<int> scolor,sradius;
        if(N>0)
        {
            scolor.push(color[0]);
            sradius.push(radius[0]);
        }
        for(int i=1;i<N;i++)
        {
            if(scolor.empty())
            {
                scolor.push(color[i]);
                sradius.push(radius[i]);
            }
            else if(scolor.top()==color[i]&&sradius.top()==radius[i])            
            {
                scolor.pop();
                sradius.pop();
            }
            else
            {
                scolor.push(color[i]);
                sradius.push(radius[i]);
            }
        }
        return scolor.size();
    }
int main()
{
    int v=6;
    vector<int>adj[v];
    int indegree[v]={0};
    addEdge(adj,0,1,indegree);
    addEdge(adj,0,2,indegree);
    addEdge(adj,2,3,indegree);
    addEdge(adj,1,3,indegree);
    addEdge(adj,0,4,indegree);
    addEdge(adj,0,5,indegree);
    addEdge(adj,1,4,indegree);
    printTopologicalOrder(adj,v);
    printIngere(adj,v,indegree);
}
