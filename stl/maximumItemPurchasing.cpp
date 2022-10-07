#include<bits/stdc++.h>
using namespace std;
int maxItemsThatCanBePurchased(vector<int>v,int cost)
{
    priority_queue<int>pq;
    int c=0,sum=0;
    for(int i=0;i<v.size();i++)
    {
        if(pq.empty()&&sum+v[i]<=cost)
        {
            c++;
            sum+=v[i];
            pq.push(v[i]);
        }
        else if(!pq.empty())
        {
            if(pq.top()<v[i]&&v[i]+sum<cost)
            {
                c++;
                sum+=v[i];
                pq.push(v[i]);
            }
            else if(pq.top()>v[i])
            {
                while(sum+v[i]>cost)
                {
                    c--;
                    sum-=pq.top();
                    pq.pop();
                }
                c++;
                sum+=v[i];
                pq.push(v[i]);
            }
        }
    }
    return c;
}
int main()
{
    vector<int>v={20,10,5,30,7,100,3,4};
    int cost=14;
    cout<<maxItemsThatCanBePurchased(v,cost);
}