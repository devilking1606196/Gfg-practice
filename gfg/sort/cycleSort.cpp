#include<bits/stdc++.h>
using namespace std;
void cycleSort(int arr[],int size) //minimum number of writes
{   //solution for all distinct numbers
    for(int start=0;start<size-1;start++)    
    {
        int pos=start;
        int item=arr[start];
        for(int j=start+1;j<size;j++)
        {
            if(arr[j]<item)
            {
                pos++;
            }
        }
       
        swap(arr[pos],item);
        while(pos!=start)
        {
            pos=start;
            for(int j=start+1;j<size;j++)
            {
                if(arr[j]<item)
                {
                    pos++;
                }
            }
        
            swap(arr[pos],item);
        }
    }
}

void RepeatedcycleSort(int arr[],int size) //minimum number of writes
{   //solution for repeated numbers
    for(int start=0;start<size-1;start++)    
    {
        int pos=start;
        int item=arr[start];
        for(int j=start+1;j<size;j++)
        {
            if(arr[j]<item)
            {
                pos++;
            }
        }
        if(pos==start)// important
        continue;
        while(arr[pos]==item)
        {
            pos++;
        }       
        swap(arr[pos],item);
        while(pos!=start)
        {
            pos=start;
            for(int j=start+1;j<size;j++)
            {
                if(arr[j]<item)
                {
                    pos++;
                }
            }
            while(arr[pos]==item)
            {
                pos++;
            }
            swap(arr[pos],item);
        }
    }
}
int main()
{
    int arr[]={5,4,6,3,2,1,4,3,4,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    RepeatedcycleSort(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}