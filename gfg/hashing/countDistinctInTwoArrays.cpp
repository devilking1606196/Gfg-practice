#include<bits/stdc++.h>
using namespace std;
int distincttCount(vector<int> a,vector<int> b)
{
    unordered_set s(a.begin(),a.end());
    for(int i=0;i<b.size();i++)
    {
        s.insert(b[i]);
    }
    return s.size();
}
int main()
{
    vector <int> a={15,20,15,5,1,2};
    vector <int> b={15,15,20,10};
    cout<<distincttCount(a,b);
}