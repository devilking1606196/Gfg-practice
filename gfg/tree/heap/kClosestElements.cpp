#include<bits/stdc++.h>
using namespace std;
void printKclosestElements(int arr[],int size,int x,int k) //O(Nlog(N))
{
    sort(arr,arr+size);
    int s=0,e=size-1,ans;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==x)
        {
            ans=mid;
            break;
        }
        else if(arr[mid]<x)
        {
            ans=mid;
            s=mid+1;
        }
        else
        e=mid-1;
    }
    s=ans;
    int l=ans+1;
    while(k>0)
    {
        if(abs(arr[s]-x)<=abs(x-arr[l]))
        {
            cout<<arr[s]<<" ";
            s--;
        }
        else
        {
            cout<<arr[l]<<" ";
            l++;
        }
        k--;
    }
    cout<<endl;
}
void printKelemets(int arr[],int size,int x,int k)//O(NK)
{
    bool visited[size]={false};
    for(int i=0;i<k;i++)
    {
        int min_dif=INT_MAX;
        int min_dif_indx;
        for(int j=0;j<size;j++)
        {
            if(visited[j]==false&&abs(arr[j]-x)<min_dif)
            {
                min_dif=abs(arr[j]-x);
                min_dif_indx=j;
            }
        }
        visited[min_dif_indx]=true;
        cout<<arr[min_dif_indx]<<" ";
    }
    cout<<endl;
}
void printKele(int arr[],int size,int x,int k)
{
    
    priority_queue<pair <int,int>> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({abs(arr[i]-x),i});
    }
    for(int i=k;i<size;i++)
    {
        if(pq.top().first>abs(arr[i]-x))
        {
            pq.pop();
            pq.push({abs(arr[i]-x),i});
        }
        
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    while(!pq.empty())
    {
        // cout<<arr[pq.top().second]<<" ";
        p.push(pq.top());
        // cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    while(!p.empty())
    {
        cout<<arr[p.top().second]<<" ";
        p.pop();
    }

}
int main()
{
    int arr[]={10,30,5,40,38,80,70};
    int size=sizeof(arr)/sizeof(arr[0]);
    int x=35,k=3;
    printKclosestElements(arr,size,x,k);
    printKelemets(arr,size,x,k);
    printKele(arr,size,x,k);
}