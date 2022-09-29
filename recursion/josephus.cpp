#include<bits/stdc++.h>
using namespace std;
int josephus(int boysNumber,int kill)
{
    if(boysNumber==1)
    {
        return 0;
    }
    int small=josephus(boysNumber-1,kill);
    int currAns=(small+kill)%boysNumber;
    return currAns;
}
int main()
{
    cout<<josephus(14,2)<<endl;    
}