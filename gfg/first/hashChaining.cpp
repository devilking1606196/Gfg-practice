                //    MY METHOD FOR HASHING 




#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node *link;
};
node *hashh[7];
void insert(int data)
{
    if(!hashh[data%7])
    {
        node *temp=new node;
        temp->key=data;
        temp->link=NULL;
        hashh[data%7]=temp;
        return;
    }
    node *t=hashh[data%7];
    while(t->link)
    {
        t=t->link;
    }
    node *temp=new node;
    temp->key=data;
    temp->link=NULL;
    t->link=temp;
    return;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int s=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<s;i++)
    {
        insert(arr[i]);
    }
    for(int i=0;i<7;i++)
    {
        while(hashh[i]!=NULL)
        {
            cout<<hashh[i]->key<<" "; 
            hashh[i]=hashh[i]->link;
        }cout<<endl;
    }
}





// // GEEKS WAY USING LIST STL DATA STRUCTURE
// #include<bits/stdc++.h>
// using namespace std;
// struct node{
//     int BUCKET;
//     list <int> *data;
//     node()
//     {
//         BUCKET=7;
//         data=new list<int>[7];
//     }
//     void insert(int value)
//     {
//         int i=value%BUCKET;
//         data[i].push_back(value);
//     }
//     bool search(int value)
//     {
//         int x=value%BUCKET;
//         for(auto i:data[x])
//         {
//             if(i==value)
//             return true;
//         }
//         return false;
//     }
//     void deletee(int value)
//     {
//         int i=value%BUCKET;
//         data[i].remove(value);
//     }
//     void print()
//     {
//         for(int i=0;i<7;i++)
//         {
//             for(auto x: data[i])
//             cout<<x<<" ";
//             cout<<endl;
//         }
//     }
// };
// int main()
// {
//     // int n;
//     // cout<<"size \n";
//     // cin>>n;
//     node hashh;
//     int arr[]={1,2,3,4,5,6,7,8,9,10};
//     int s=sizeof(arr)/sizeof(arr[0]);
//     for(int i=0;i<s;i++)
//     {
//         hashh.insert(arr[i]);
//     }
//     cout<<hashh.search(790)<<endl;
//     hashh.print();
//     hashh.deletee(3);
//     cout<<endl;
//     hashh.print();
// }