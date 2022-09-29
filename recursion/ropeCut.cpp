#include<bits/stdc++.h>
using namespace std;

int maxx(int a,int b,int c)
{
    int ans;
    ans=max(a,b);
    ans=max(ans,c);
    return ans;
}
int cutRope(int rope,int one ,int two ,int three)
{
    int a=-1,b=-1,c=-1;
    int ans=-1;
    if(rope==0)
    {
        return 0;
    }
    if(rope<0)
    {
    return -1;
    }

     a=cutRope(rope-one,one,two,three);
     b=cutRope(rope-two,one,two,three);
     c=cutRope(rope-three,one,two,three);
     ans=maxx(a,b,c);
     if(ans==-1)
     return -1;
     else
     return ans+1;

}
int main()
{
    int rope=5,a=3,b=5,c=2;
    cout<<cutRope(rope,a,b,c)<<endl; 
}