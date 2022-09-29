#include<bits/stdc++.h>
using namespace std;
int longestBinary(bool arr[],int n)
{
    unordered_map <int,int> m;
    int preSum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i])
        preSum++;
        else
        preSum--;
        if(m.find(preSum)==m.end())
        {
            m.insert({preSum,i});
        }
        if(m.find(preSum)!=m.end())
        {
            ans=max(ans,i-m[preSum]);
        }
    }
    return ans;
}
int main()
{
    bool arr[]={1,0,1,1,0,0};
    int n=sizeof(arr)/sizeof(arr[0]),ans=0;
    
    cout<<longestBinary(arr,n);

}



// for(int i=0;i<n;i++)
//     {
//         int c0=0,c1=0;
//         for(int j=i;j<n;j++)
//         {
//             if(arr[j])
//             c1++;
//             else
//             c0++;
//             if(c1==c0)
//             {
//                 ans=max(c1+c0,ans);
//             }
//         }
//     }