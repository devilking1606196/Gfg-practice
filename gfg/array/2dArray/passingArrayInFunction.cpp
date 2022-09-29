#include<bits/stdc++.h>
using namespace std;
int main()
{
    int **a;
    a=new int *[3];
    for(int i=0;i<3;i++)
    {
        a[i]=new int [4];
        for(int j=0;j<4;j++)
        a[i][j]=i+j+5;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    
    int **b;
    b=new int*;
    *b=new int(20);
    cout<<b<<"\n"<<*b<<"\n"<<**b;
}