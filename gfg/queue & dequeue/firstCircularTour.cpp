#include<bits/stdc++.h>
using namespace std;
int firstCircularTour(int petrol[],int distance[],int size)
{
    for(int i=0;i<size;i++)
    {
        int p=0,j=i;
        bool flag=true;
        do
        {
            p=p+petrol[j]-distance[j];
            if(p<0)
            {
                flag=false;
                break;
                i=j+1;
            }
            j=(j+1)%size;
        } while (j!=i);
        if(flag)
        {
            return i;
        }
    }
    return -1;
}
// int firstCirTour(int petrol[],int distance[],int size) // can't find the exit solution
// {
//     int p=0,start=0;
//     deque <int> dq;
//     bool flag=true;
//     while(true)
//     {
//         dq.push_back(start);
//         if(dq.front()==size-1)
//         {
//             flag=false;
//         }
//         p+=(petrol[start]-distance[start]);
//         while(p<0)
//         {
//             int i=dq.front();
//             dq.pop_front();
//             p-=(petrol[i]-distance[i]);
//         }
//         if(!dq.empty()&&(dq.back()+1)%size==dq.front())
//         {
//             return (dq.front());
//         }
//         if(!flag)
//         {
//             if(dq.front()!=size-1)
//             return -1;
//         }
//         start=(start+1)%size;
//     }
// }
int firstCircuTour(int petrol[],int distance[],int size)
{
    int curr_petrol=0,prev_petrol=0;
    int ans=0;
    for(int i=0;i<size;i++)
    {
        curr_petrol+=(petrol[i]-distance[i]);
        if(curr_petrol<0)
        {
            ans=i+1;
            prev_petrol+=curr_petrol;
            curr_petrol=0;
        }
    }
    return ((curr_petrol+prev_petrol)<0?-1:ans);
}
int main()
{
    int petrol[]={5,1,7,10},distance[]={6,2,1,10};
    int size=sizeof(petrol)/sizeof(petrol[0]);
    cout<<firstCircularTour(petrol,distance,size)<<endl;
    cout<<firstCircuTour(petrol,distance,size)<<endl;
    vector<int>v;
    pair<int,int> p;
    p.second
}