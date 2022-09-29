#include<bits/stdc++.h>
using namespace std;
void movesZeros(int arr[],int size)
{
    int c=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[c]);
            c++;
        }
    }
}
int main()
{
    int arr[]={1,4,0,0,7,5,0,5,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    movesZeros(arr,size);
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    
}