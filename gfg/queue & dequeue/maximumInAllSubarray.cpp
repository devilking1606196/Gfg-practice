#include<bits/stdc++.h>
using namespace std;
void maximumInSubarrayOfSizeK(int arr[],int size,int k)
{
    deque<int> q;
    for(int i=0;i<k;i++)
    {
        while(!q.empty()&&arr[q.back()]<=arr[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for(int i=k;i<size;i++)
    {
        cout<<arr[q.front()]<<" ";
        while(!q.empty()&&q.front()<i-k+1)
        {
            q.pop_front();
        }
        while(!q.empty()&&arr[q.back()]<=arr[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()];
}
int main()
{
    int arr[]={10,8,5,12,15,7,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    maximumInSubarrayOfSizeK(arr,size,3);
}