#include<bits/stdc++.h>
using namespace std;

bool ansOfQues(vector<int> arr,int n,int m,int mid)
{
    bool a=true;
    int check=1;
    int sum=0;
    for(int i:arr)
    {
        if((sum+i)<=mid)
        {
            sum+=i;
        }
        else
        {
            check++;
            if(check>m)
            {
            a= false;
            }
            sum=i;
        }
    }
    return a;
}


int allocateBooks(vector<int> arr, int n, int m) 
{

    int sum=0,ma=0,ans=-1;
    for(int i:arr)
    {
        sum+=i;
        ma=max(ma,i);
    }
    int s=ma,e=sum;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(ansOfQues(arr,n,m,mid))
        {
            ans=mid;
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
    vector <int> arr={5,10,100,15};
    int ans=allocateBooks(arr,4,4);
    cout<<ans;
    // cout<<ansOfQues(arr,4,2,60);

}