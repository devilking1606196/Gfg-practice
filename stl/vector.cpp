#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v={1,2,3,4,5};
    // cout<<v.capacity()<<endl;
    // cout<<v.size()<<endl;
    v.push_back(21);
    // cout<<v.capacity()<<endl;
    // cout<<v.size();
    set <int,greater<int>> s={1,3,2,4,3,25,7};
    for(auto i:s)
    {
        cout<<i<<" ";
    }
}