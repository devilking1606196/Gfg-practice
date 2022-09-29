#include<bits/stdc++.h>
using namespace std;
int largestAreaInHistogram(int arr[],int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
    {
        int l=arr[i];
        for(int j=i;j<size;j++)
        {
            l=min(l,arr[j]);
            int area=l*(j-i+1);
            ans=max(ans,area);
        }
    }
    return ans;
}
void prevSmallest(int arr[],int ps[],int size)
{
    stack <int> s;
    s.push(0);
    for(int i=0;i<size;i++)
    {
        while(!s.empty()&&arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        ps[i]=s.empty()?-1:s.top();
        s.push(i);
    }
}
void nextSmallest(int arr[],int ns[],int size)
{
    stack <int> s;
    s.push(size-1);
    for(int i=size-1;i>=0;i--)
    {
        while(!s.empty()&&arr[s.top()]>=arr[i])
        s.pop();
        ns[i]=s.empty()?size:s.top();
        s.push(i);
    }
}
int largestAreaUsingSmallestNextAndPrev(int arr[],int size)
{
    int ans=0;
    int ps[size],ns[size];
    prevSmallest(arr,ps,size);
    // for(int i=0;i<size;i++)
    // {
    //     bool flag=true;
    //     for(int j=i-1;j>=0;j--)
    //     {
    //         if(arr[j]<arr[i])
    //         {
    //             flag=false;
    //             ps[i]=j;
    //             break;
    //         }
    //     }
    //     if(flag)
    //     {
    //         ps[i]=-1;
    //     }
    // }
    nextSmallest(arr,ns,size);
    // for(int i=size-1;i>=0;i--)
    // {
    //     bool flag=true;
    //     for(int j=i+1;j<size;j++)
    //     {
    //         if(arr[j]<arr[i])
    //         {
    //             flag=false;
    //             ns[i]=j;
    //             break;
    //         }
    //     }
    //     if(flag)
    //     {
    //         ns[i]=size;
    //     }
    // }
    for(int i=0;i<size;i++)
    {
        ans=max(ans,arr[i]*(ns[i]-ps[i]-1));
    }
return ans;
}

int largestAreaInOneTraversal(int arr[],int size)
{
    int ans=0;
    stack<int>s;
    for(int i=0;i<size;i++)
    {
        while(s.empty()==false&&arr[s.top()]>=arr[i])   
        {
            int tp=s.top();
            s.pop();
            int curr=arr[tp]*(s.empty()?i:i-s.top()-1);
            ans=max(ans,curr);
        }
        s.push(i);
    }
    while(!s.empty())
    {
        int tp=s.top();
        s.pop();
        int curr=arr[tp]*(s.empty()?size:size-s.top()-1);
        ans=max(ans,curr);
    }
    return ans;
}
int main()
{
    int arr[]={4,4,3,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<largestAreaInHistogram(arr,size)<<endl;
    cout<<largestAreaUsingSmallestNextAndPrev(arr,size)<<endl;
    cout<<largestAreaInOneTraversal(arr,size);
}