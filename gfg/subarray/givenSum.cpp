#include<bits/stdc++.h>
using namespace std;
bool givenSum(int arr[],int n,int sum)
{
    unordered_set <int> s;
    int preSum=0;
    for(int i=0;i<n;i++)
    {
        preSum+=arr[i];
        if(preSum==sum)
        {
        return true;
        }
        if(s.find(preSum-sum)!=s.end())   // IF VALUE NOT FOUND RETURN THE END ITERATOR ELSE THE ITERATOR TO THE
        {                                //VALUE
            return true; 
        }           
        s.insert(preSum);
    }
return false;
}
int main()
{
    int arr[]={5,8,-4,-4,9,-3,-3};
    int sum=0,n=sizeof(arr)/sizeof(arr[0]);
    cout<<boolalpha<<givenSum(arr,n,sum)<<"\n";
    // unordered_set <int> s;
    // for(int i=0;i<n;i++)
    // {
    //     s.insert(arr[i]);
    // }
    // cout<<boolalpha<<(s.find(122)==s.end());

}