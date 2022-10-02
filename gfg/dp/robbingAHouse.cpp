#include<bits/stdc++.h>//houses are arranged in a circle and no two adjacent houses can be robbed(last & first)
using namespace std;
int maxVal(vector<int> &v,int indx)
{
    int n=v.size();
    int prev=v[0];
    int prev2=0;
    for(int i=1;i<n;i++)
    {
        int take=v[i];
        if(i>1)
        take+=prev2;
        int notTake=prev;
        int curr=max(take,notTake);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
int maxValueRobbed(vector<int> &house)
{
    int n=house.size();
    if(n==1)
    return house[0];
    vector<int>t1,t2;
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        t1.push_back(house[i]);
        if(i!=n-1)
        t2.push_back(house[i]);
    }
    return max(maxVal(t1,n-2),maxVal(t2,n-2));
}
int main()
{
    vector<int> house={2,4,5,9,7};
    cout<<maxValueRobbed(house);
}