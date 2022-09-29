#include<bits/stdc++.h>
using namespace std;
void printFrequencies(int arr[],int size)
{
    int count=1;
    for(int i=0;i<size;i=i+count)
    {
        count=1;
        int temp=arr[i];
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]==arr[i])\
            count++;
        }
        cout<<count<<" ";     
    }

}
int main()
{
    int arr[]={10,10,10,25,25,30,30,40};
    int size=sizeof(arr)/sizeof(arr[0]);
    printFrequencies(arr,size);
}