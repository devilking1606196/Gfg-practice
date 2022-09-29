#include<bits/stdc++.h>
using namespace std;
// int one=0,zero=0,count=0;
    // if(arr[0]==1)
    // one++;
    // else
    // zero++;
    // for(int i=1;i<size;i++)
    // {
    //     if(arr[i-1]==1&&arr[i]==0)
    //     zero++;
    //     else if(arr[i-1]==0&&arr[i]==1)
    //     one++;
    // }
void minimumFlips(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        if(arr[i-1]!=arr[i])
        {
            cout<<"From "<<i<<" to ";   
            int j=i;
            while(j)
            {
                if(arr[j]!=arr[j+1])
                {
                    cout<<j<<endl;
                    i=j+1;
                    break;
                }
                j++;
            }
        }     
    }
}
int main()
{
    int arr[]={1,1,0,0,0,0,1,0,1,1,0,1,0,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    minimumFlips(arr,size);
}