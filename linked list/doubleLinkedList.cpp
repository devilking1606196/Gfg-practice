#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * prev,*next;
};
node * head=new node,*tail;

void insert(int data)
{
    node * t=new node;
    t->data=data;
    node*temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    tail=t;
    temp->next=t;
    t->prev=temp;
    t->next=NULL;
}

void print(node* s)
{
    while(s)
    {
        cout<<s->data<<"\t";
        s=s->next;
    }
    cout<<endl;
}
void rPrint(node *s)
{
    while(s)
    {
        cout<<s->data<<"\t";
        s=s->prev;
    }
    cout<<endl;
}
int main()
{
    head->data=12;
    head->prev=NULL;
    head->next=NULL;
    insert(4);
    insert(9);
    insert(12);
    insert(45);
    insert(33);
    print(head);
    rPrint(tail);
    
}