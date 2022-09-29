#include<bits/stdc++.h>
using namespace std;
vector <int> heap={40,20,30,35,25,80,32,100,70,60};
void insert(int x)
{
    int n=heap.size();
    
    heap.push_back(x);
    
    int parent=(n-1)/2;
    while(parent>=0&&heap[parent]>heap[n])
    {
        swap(heap[parent],heap[n]);
        n=parent;
        parent=(n-1)/2;
    }
}
void decreaseKey(int i,int x)
{
    heap[i]=x;
    int parent=(i-1)/2;
    while(parent>=0&&heap[parent]>heap[i])
    {
        swap(heap[parent],heap[i]);
        i=parent;
        parent=(i-1)/2;
    }
}
void minHeapify(int i)
{
    int lt=(2*i+1);
    int rt=(2*i+2);
    int min=i;
    if(lt<heap.size()&&heap[lt]<heap[i])
    min=lt;
    if(rt<heap.size()&&heap[rt]<heap[min])
    min=rt;
    if(min!=i)
    {
        swap(heap[min],heap[i]);
        minHeapify(min);
    }
}
void extraction()
{
    int n=heap.size();
    if(n==0)
    return;
    n--;
    swap(heap[0],heap[n]);
    heap.pop_back();
    minHeapify(0);
}
void deleteKey(int i)
{
    decreaseKey(i,INT_MIN);
    extraction();
}

int main()
{
    // int arr[]={100,30,40,50,44};
    // int size=sizeof(arr)/sizeof(arr[0]);
    // for(int i=size-1;i>=0;i--)
    // {
    //     minHeapify(i);
    // }
    // for(int i=0;i<size;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    minHeapify(0);
    for(int i=0;i<heap.size();i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    insert(12);
    for(int i=0;i<heap.size();i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    extraction();
    // deleteKey(3);
    for(int i=0;i<heap.size();i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    
}