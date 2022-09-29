#include<bits/stdc++.h>
using namespace std;
//O(n^2)
void countFrequency(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int count =1;
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]!=INT_MIN&&arr[i]==arr[j])
            {
                count++;
                arr[j]=INT_MIN;
            }
        }
        if(arr[i]!=INT_MIN)
        cout<<arr[i]<<" "<<count<<endl;
    }
}
//O(Nlog(N))
void countFrequencyL(int arr[],int size)
{
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        int count=0,t=arr[i];
        while(t==arr[i])
        {
            count++;
            i++;
        }
        cout<<t<<" "<<count<<endl;
        i--;
    }
}
//O(N) using hashmap
void countFreq(int arr[],int size)
{
    unordered_map <int,int> m;
    // for(int i=0;i<size;i++)
    // {
    //     pair<int,int> s;
    //     if(m.find(arr[i])==m.end())
    //     {
    //         s={arr[i],1};
    //         m.insert(s);
    //     }
    //     else
    //     {
    //         m[arr[i]]++;
    //     }
    // }
    for(int i=0;i<size;i++)
    {
        m[arr[i]]++;
    }
    for(auto i: m)//dose not gaureente the order ....for order we can transverse the array
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
int main()
{
    int arr[]={10,12,10,15,10,20,12,12,20};
    int size=sizeof(arr)/sizeof(arr[0]);
    countFreq(arr,size);
}