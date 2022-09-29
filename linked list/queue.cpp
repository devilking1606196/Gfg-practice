#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * link;
};
node *front=NULL,*rear=NULL;

void insertData(int data)
{
    if(front==NULL)
    {
        front=new node;
        node *temp=new node;
        front->link=temp;
        temp->data=data;
        temp->link=front;
        rear=temp;
    }
    else
    {
        node*t=front;
        while(t!=rear)
        {
            t=t->link;
        }
        node * temp=new node;
        t->link=temp;
        rear=temp;
        temp->data=data;
        temp->link=front;
    }
}

void print()
{
    node * t=front;

    while(t!=rear)
    {
        t=t->link;
        cout<<t->data<<"\t";
    }
    cout<<endl;
}


int main()
{
    insertData(12);
    insertData(32);
    insertData(23);
    print();
}