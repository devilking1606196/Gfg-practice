#include<bits/stdc++.h>
using namespace std;
void printBoundary(int **arr,int r,int c)
{
    if(r==1)
    {
        for(int i=0;i<c;i++)
        cout<<arr[0][i]<<" ";
        return;
    }
    else if(c==1)
    {
        for(int i=0;i<r;i++)
        cout<<arr[i][0]<<" ";
        return;
    }
    int i=0,j=0;                   //instead use 4 for loops
    for(i;i<r;i++)
    {
        for(j;j<c-1;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<arr[i][j]<<" ";
    }
    i=r-1;j--;
    for(;i>0;i--)
    {
        for(;j>0;j--)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<arr[i][j]<<" ";
    }
}
void transposeOfMatrix(int **arr,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=i;j<c;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}
void print(int **arr,int r,int c)
{
     for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void rotateMatrix(int **arr,int r,int c) // other way is transpose and then reverse the column elements
{
    int temp[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            temp[c-1-j][i]=arr[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        arr[i][j]=temp[i][j];
    }
    return;
}
void matrixRotateO1(int **arr,int r,int c)
{
    transposeOfMatrix(arr,r,c);
    r--;
    for(int i=0;i<r/2;i++)
    {
        for(int j=0;j<c;j++)
        {
            swap(arr[i][j],arr[r-i][j]);
        }
    }
    return;
}
void printSpiral(int ** arr, int r,int c)// using 4 variables
{
    int top=0,right=c-1,bottom=r-1,left=0;
    while(top<=bottom&&left<=right)
    {
        for(int i=left;i<=right;i++)
        {
            cout<<arr[top][i]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            cout<<arr[i][right]<<" ";
        }
        right--;
        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
    }
return;    
}
int main()
{
    int r=5,c=5;
    int count=1;
    int **arr;
    arr =new int *[r];
    for(int i=0;i<r;i++)
    {
        arr[i]=new int[c];
        for(int j=0;j<c;j++)
        {
            arr[i][j]=count;
            count++;
        }
    }
    print(arr,r,c);
    printSpiral(arr,r,c);
    // matrixRotateO1(arr,4,4);
    // transposeOfMatrix(arr,4,4);
    // print(arr,4,4);
    // printBoundary(arr,4,4);
}