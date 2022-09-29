#include<bits/stdc++.h>
using namespace std;
void printMoreThanOccurence(int arr[],int size,int k) ///more than size/k occurence
{
    unordered_map<int,int> m;
    for(int i=0;i<size;i++)
    {
        m[arr[i]]++;
    }
    for(auto i: m)
    {
        if(i.second>size/k)
        {
            cout<<i.first<<" "; 
        }
    }
    return;
}
void printOccurenceForLargevalueOfN(int arr[],int size,int k)
{
    unordered_map<int,int>m;
    for(int i=0;i<size;i++)
    {
        if(m.find(arr[i])!=m.end())
        {
            m[arr[i]]++;
        }
        else if(m.size()<k-1)
        {
            m[arr[i]]++;        
        }
        else
        {
            for(auto i:m)
            {
                (i.second)--;
                if(i.second==0)
                m.erase(i.first);
            }
        }
    }
    for(auto i:m)
    {
        int c=0;
        for(int j=0;j<size;j++)
        {
            if(i.first==arr[j])
            c++;
        }
        if(c>size/k)
        cout<<i.first<<" ";
    }
}
int main()
{
    int arr[]={30,10,20,20,20,10,20,30,30};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    printMoreThanOccurence(arr,size,k);
    cout<<endl;
    printOccurenceForLargevalueOfN(arr,size,k);
}