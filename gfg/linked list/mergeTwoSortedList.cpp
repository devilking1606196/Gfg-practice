#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int s)
    {
        data=s;
        next=NULL;
    }
};
void insertData(node **head,int data)
{
    if(*head==NULL)
    {
        *head=new node(data);
        return;
    }
    node *temp=*head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=new node(data);
}
void printList(node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node * mergeTwoList(node *h1,node *h2)
{
    node *t1=h1,*t2=h2,*h=NULL,*head=NULL;
    while(t1&&t2)
    {
        if(t1->data<t2->data)
        {
            if(h==NULL)
            {
                h=t1;
                head=h;
            }
            else
            {
                h->next=t1;
                h=h->next;
            }
            t1=t1->next;
        }
        else
        {
            if(h==NULL)
            {
                h=t2;
                head=h;
            }
            else
            {
                h->next=t2;
                h=h->next;
            }
            t2=t2->next;
        }
    }
    while(t1)
    {
        if(h==NULL)
        {
            h=t1;
            head=h;
        }
        else
        {
            h->next=t1;
            h=h->next;
        }
        t1=t1->next;
    }
    while(t2)
    {
        if(h==NULL)
        {
            h=t2;
            head=h;
        }
        else
        {
            h->next=t2;
            h=h->next;
        }
        t2=t2->next;
    }
    return head;
}
int main()
{
    node *head1=NULL,*head2=NULL;
    insertData(&head1,10);
    insertData(&head1,20);
    insertData(&head1,30);
    insertData(&head1,45);
    insertData(&head1,55);
    insertData(&head2,5);
    insertData(&head2,25);
    printList(head1);
    printList(head2);
    node * S=mergeTwoList(head1,head2);
    printList(S);
}