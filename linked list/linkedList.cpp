#include<bits/stdc++.h>
using namespace std;

struct List{
    int data;
    List * link;
};
List * head=NULL;

void insertData(int data)
{
    if(head==NULL)
    {
        head=new List;
        head->data=data;
        head->link=NULL;
    }
    else
    {
        List*temp=new List;
        temp->data=data;
        temp->link=NULL;
        List *t=head;
        while(t->link)
        {
            t=t->link;
        }
        t->link=temp;   
    }
}
 
void print()
{
    List * t=head;
    while(t)
    {
        cout<<t->data<<"\t";
        t=t->link;
    }
    cout<<endl;
}

void beginingInsert(int data)
{
    List*n=new List;
    n->data=data;
    n->link=head;
    head=n;
}

void afterInsert(int data,int pos)
{
    List*t=head;
    while(t->data!=pos)
    {
        t=t->link;
    }
    List * temp=new List;
    temp->data=data;
    temp->link=t->link;
    t->link=temp;
}
void deleteData(int data)
{
    List*t=head;
    while(t->link->data!=data)
    t=t->link;
    t->link=t->link->link;
}

void endDelete(){
    List*t=head;
    while(t->link->link)
    t=t->link;
    t->link=NULL;
}

void startDelete()
{
    head=head->link;

}

void recPrint(List* t)
{
    if(t==NULL)
    return;
    cout<<t->data<<"\t";
    recPrint(t->link);
}
 
List * reverse()
{
    List * prev=NULL,*curr=head,*next=NULL;
    while(curr)
    {
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

List * recReverse(List * h)
{
    if(h==NULL||h->link==NULL)
    return h;
    List * head=recReverse(h->link);
    List * temp=h->link;
    temp->link=h;
    h->link=NULL; 
    return head;
}

void removeDuplicate(List * head)
{
    if(!head)
    return;
    while(head->link)
    {
        if(head->data==head->link->data)
        {
            List * t=head->link;
            head->link=head->link->link;
            delete (t);
        }
        else{
            head=head->link;
        }
    }
}

int main(){
    insertData(1);
    insertData(1);
    insertData(3);
    insertData(5);
    insertData(5);
    insertData(5);
    insertData(7);
    // print();
    // beginingInsert(11);
    // print();
    // beginingInsert(99);
    // print();
    // afterInsert(333,1);
    // print();
    // deleteData(1);
    cout<<"before"<<endl;
    print();
    // endDelete();
    // print();
    // startDelete();
    // print();
    // head=recReverse(head);
    removeDuplicate(head);
    cout<<"after"<<endl;    
    recPrint(head);
}