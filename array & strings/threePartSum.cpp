//wrong answer
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> arr,int n,int mid)
{
    int count=1,sum=0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]<=mid)
        {
            sum+=arr[i];
        }
        else
        {
            count++;
            if(count>3)
            {
                return false;
            }
            sum=arr[i];
        }
    }
    return true;
}
bool threePartSum(vector<int> arr,int n)//wrong
{
    bool ans=false;
    int sum=0;
    for(int i:arr)
    {
        sum+=i;
    }
    cout<<sum<<endl;
    int s=0,e=sum,mid;
    while(s<e)
    {
        mid=s+(e-s)/2;
        if(isPossible(arr,n,mid))
        {
            ans=true;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        

    }
    return ans;

}
int main()
{
    vector <int> arr={1,6,6,7,1,1,4,4};
    // cout<<threePartSum(arr,arr.size());
}