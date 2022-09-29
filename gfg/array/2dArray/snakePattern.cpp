#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    for(int i=0;i<4;i++)
    {
        // int j=0;
        // for(;j<4;j++)
        // {
        //     cout<<arr[i][j]<<" ";
        // }
        // j--;i++;
        // cout<<endl;
        // for(;j>=0;j--)
        // {
        //     cout<<arr[i][j]<<" ";
        // }
        // cout<<endl;
        if(i%2==0)
        {
            for(int j=0;j<4;j++)
            {
                cout<<arr[i][j]<<" ";
            }
        }
        else
        {
            for(int j=3;j>=0;j--)
            {
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}