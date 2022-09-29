#include<bits/stdc++.h>
using namespace std;
void printFrequency(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int count=0;
        int temp=arr[i];
        for(int j=0;j<size;j++)
        {
            if(arr[j]!=-1 && arr[j]==temp)
            {
                arr[j]=-1;
                count++;
            }
        }
        if(temp!=-1)
        cout<<temp<<" "<<count<<endl;
    }
}
int main()
{
    int arr[]={4,2,5,1,4,4,2,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    printFrequency(arr,size);
}