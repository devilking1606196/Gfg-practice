#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * link;
};
node * top=NULL;


void push(int data)
{
    if(top==NULL)
    {
        top=new node;
        top->data=data;
        top->link=NULL;
    }
    else
    {
        node * temp=new node;
        temp->data=data;
        temp->link=top;
        top=temp;
    }

}

void print()
{
    node * temp=top;
    while(temp)
    {
        cout<<temp->data<<"\t";
        temp=temp->link;
    }
    cout<<endl;
}
void pop()
{
    node *t=top;
    top=top->link;
    delete t;
}

int main()
{
    push(12);
    push(2);
    push(33);
    push(54);
    print();
    // node * t=top;
    pop();
    // cout<<"\n"<<t->data<<" \n";
    print();
}