#include<bits/stdc++.h>
using namespace std;

// int largestRectangleWithALLOnes()
// {
//     int arr[][4]={{0,0,0,0},
//                    {0,0,1,0},
//                    {0,0,0,0},
//                    {0,1,0,0}};
//     int ans=0;
//     for(int i=0;i<4;i++)
//     {
//         for(int j=0;j<4;j++)
//         {
//             if(arr[i][j]==1)
//             {
//                 for(int a=i+1;a<=4;a++)
//                 {
//                     for(int b=j+1;b<=4;b++)
//                     {
//                         bool flag=true;
//                         int c=0;
//                         for(int x=i;x<a;x++)
//                         {
//                             for(int y=j;y<b;y++)
//                             {
//                                 c++;
//                                 if(arr[x][y]==0)
//                                 flag=false;
//                             }
//                         }
//                         if(flag)
//                         ans=max(ans,c);
//                     }
//                 }
//             }
//         }
//     }
//     return ans;
// }
int largestAreaOfHistogram(int arr[],int size)
{
    int ans=0;
    stack <int>s;
    for(int i=0;i<size;i++)
    {
        while(!s.empty()&&arr[s.top()]>=arr[i])
        {
            int tp=s.top();s.pop();
            int curr=arr[tp]*(s.empty()?i:i-s.top()-1);
            ans=max(ans,curr);
        }
        s.push(i);
    }
    while(!s.empty())
    {
        int tp=s.top();s.pop();
        int curr=arr[tp]*(s.empty()?size:size-s.top()-1);
        ans=max(ans,curr);
    }
    return ans;
}
int largestRectangle(int **arr,int size)
{
    int ans=largestAreaOfHistogram(arr[0],size);
    for(int i=1;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(arr[i][j]==1)
            arr[i][j]+=arr[i-1][j];
        }
        ans=max(ans,largestAreaOfHistogram(arr[i],size));
    }
    return ans;
}
int main()
{
    int **arr;
    int size=4;
    arr=new int *[size];
    for(int i=0;i<size;i++)      
    {
        arr[i]=new int [size];
        for(int j=0;j<size;j++)
        {
            arr[i][j]=1;
        }
    }
    arr[0][2]=0;arr[3][3]=0;arr[3][2]=0;arr[1][1]=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<largestRectangle(arr,size)<<endl;
}
