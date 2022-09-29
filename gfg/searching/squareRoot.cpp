#include<bits/stdc++.h>
using namespace std;
int squareRoot(int n)
{
    int s=0,e=n,ans;
    while(s<=e)
    {
        int mid=e+(s-e)/2;
        if(mid*mid==n)
        return mid;
        else if(mid*mid<n)
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
return ans;
}
int main()
{
    cout<<squareRoot(44);
}