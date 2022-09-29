#include<bits/stdc++.h>
using namespace std;
void sortKSortedArray(int arr[],int size,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<=k;i++)
    {
        pq.push(arr[i]);
    }
    int indx=0;
    for(int i=k+1;i<size;i++)
    {
        arr[indx]=pq.top();
        pq.pop();
        pq.push(arr[i]);
        indx++;
    }
    while(!pq.empty())
    {
        arr[indx]=pq.top();
        pq.pop();
        indx++;
    }
}
int main()
{
    int arr[]={9,8,7,18,19,17};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    sortKSortedArray(arr,size,k);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}