//Only for postive numbers
#include<bits/stdc++.h>
using namespace std;
bool givenArrayPossible(int arr[],int size,int sum)
{
    int currSum=0;
    int s=0,e=0;
    while(e<size)
    {
        if(currSum<sum)
        {
            currSum+=arr[e];
            e++;
        }
        if(currSum>sum)
        {
            currSum-=arr[s];
            s++;
        }
        if(currSum==sum)
        return true;
    }
    return false;
}
int main()
{
    int arr[]={1,4,20,3,10,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<boolalpha<<givenArrayPossible(arr,size,11);
}