#include<bits/stdc++.h>
using namespace std;

// int bookAllocation(int n, int m, vector<int> arr) 
// {	
// 	int sum=0,s=0,mid,ans;
//     for(int i=0;i<n;i++)
//     {
//         sum+=arr[i];
//         s=max(s,arr[i]);

//     }
//     while(s<=n)
//     {
//         mid=(s+n)/2;
        


//     }


//     return ans;
// }

bool isSolution(int n, int m, vector<int> time,int mid)
{
    int count=1;
    int sum=0;
    for(int i=0;i<m;i++)
    {
        if(sum+time[i]<=mid)
        {
            sum+=time[i];
        }
        else
        {
            count++;
            sum=0;
            sum+=time[i];
            if(time[i]>mid||count>n){
            return false;
            }
        }

    }
return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
    int sum=0,ans=-1,ma=-1;
    for(int i=0;i<time.size();i++)
    {
        sum+=time[i];
        ma=max(ma,time[i]);
    }
    int s=ma,e=sum,mid;
    
    while(s<=e)
    {
        mid=(s+e)/2;
        cout<<"s"<<s<<"\nmid"<<mid<<"\ne"<<e<<endl;\
        cout<<"function"<<isSolution(n,m,time,mid)<<endl;
        if(isSolution(n,m,time,mid))
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
    vector<int> arr={10,20,30,40};
    cout<<ayushGivesNinjatest(2,arr.size(),arr);
    // cout<<isSolution(2,4,arr,60);

}






