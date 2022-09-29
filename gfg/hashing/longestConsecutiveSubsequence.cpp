#include<bits/stdc++.h>
using namespace std;
int longestConsecutiveSubSequence(int arr[],int size)
{
    int ans=1,count=1;
    sort(arr,arr+size);
    for(int i=1;i<size;i++)
    {
        if(arr[i]==arr[i-1]+1)
        {
            count++;
        }
        else
        {
            ans=max(ans,count);
            count=1;
        }
    }
    return max(ans,count);
}
int longestConsSeq(int arr[],int size)
{
    int ans=1;
    unordered_set <int> s(arr,arr+size);
    for(auto i:s)
    {
        int c=1;
        if(s.find(i-1)!=s.end())
        continue;
        else
        {
            while(s.find(i+c)!=s.end())
            {
                c++;
            }
        }
        ans=max(ans,c);
    }
    return ans;
}
int main()
{
    int arr[]={5,9,4,1,3,7,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<longestConsecutiveSubSequence(arr,size)<<endl<<longestConsSeq(arr,size);
}