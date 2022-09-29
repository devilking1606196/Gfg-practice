#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> binary;
    int count=0,t=0;
    int n=7;
    while(n>0)
    {
        if((n&1)==1)
        {
            binary.insert(binary.begin(),1);
            t++;
        }
        else{
            binary.insert(binary.begin(),0);
            count=max(count,t);
            t=0;
        }
        n=n>>1;
        if(n==0)
        {
            count=max(count,t);
        }
    }
    cout<<count<<endl;
    // reverse(binary.begin(),binary.end());
    for(int i:binary)
    {
        cout<<i<<" ";
    }


}