#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;
};
node * top=NULL;


void insert(int data)
{
    if(top==NULL)
    {
        top=new node;
        top->data=data;
        top->link=NULL;
    }
    else
    {
        node * temp =new node;
        temp->data=data;
        temp->link=top;
        top=temp;
    }
}

void print(node * t)
{
    if(t)
    {
        cout<<t->data<<"\t";
        print(t->link);
    }
    else
    return;

}


int main()
{
    int arr[]={1,34,23,54,12,43,77,98};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        insert(arr[i]);
    }
    print(top);
}