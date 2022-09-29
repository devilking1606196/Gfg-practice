#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insertData(node **head,int data)
{
    node *temp=new node(data);
    if(*head==NULL)
    {
        *head=temp;
        return;
    }
    node *t=*head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=temp;
}
void printList(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node * startPoint(node * head,int n)
{
    while(n>0)
    {
        head=head->next;
        n--;
    }
    return head;
}
int intersectOfTwoList(node* h1,node *h2)
{
    int c1=0,c2=0;
    node *curr1=h1,*curr2=h2;
    while(curr1!=NULL)
    {
        curr1=curr1->next;
        c1++;
    }
    while(curr2!=NULL)
    {
        curr2=curr2->next;
        c2++;
    }
    curr1=h1;
    curr2=h2;
    int t=abs(c2-c1);
    if(c1>c2)
    {
        curr1=startPoint(curr1,t);
    }
    else
    {
        curr2=startPoint(curr2,t);
    }
    while(curr1&&curr2)
    {
        if(curr1==curr2)
        {
            return curr1->data;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}
void pairWiseSwap(node * head)//swaping data
{
    while(head&&head->next)
    {
        swap(head->data,head->next->data);
        head=head->next->next;
    }
}
node* swapPairWise(node* head)
{
    if(head!=NULL&&head->next!=NULL)
    {
        node*curr=head->next->next;
        node*prev=head;
        head=head->next;
        head->next=prev;
        while(curr&&curr->next)
        {
            prev->next=curr->next;
            node*currNext=curr->next->next;
            curr->next->next=curr;
            prev=curr;
            curr=currNext;
        }
        prev->next=curr;
    }
    return head;
}
int main()
{
    node *head1=NULL,*head2=NULL;
    for(int i=0;i<10;i++)
    {
        insertData(&head1,i+1);
    }
    node *intersect=head1,*t=NULL;
    int c=0;
    while(c<6)
    {
        intersect=intersect->next;
        c++;
    }
    for(int i=0;i<3;i++)
    {
        insertData(&head2,i+21);
    }
    t=head2;
    while(t->next)
    {
        t=t->next;
    }
    t->next=intersect;
    printList(head1);
    // printList(head2);
    // cout<<intersectOfTwoList(head1,head2);
    pairWiseSwap(head1);
    printList(head1);
    head1=swapPairWise(head1);
    printList(head1);
}