#include<bits/stdc++.h>
using namespace std;
struct List
{
    int data;
    List* node;
};
List* insertData(List*head,int d)
{
    List * temp=new List,*t=head;
    temp->data=d;
    if(head==NULL)
    {
        return temp;
    }
    while(t->node!=NULL)
    {
        t=t->node;
    }
    t->node=temp;
    return head;
}
void printList(List *head)
{
    List * t=head;
    while(head)
    {
        cout<<head->data<<" ";
        head=head->node;
    }
}
List * groupReverse(List *head,int k)
{
    if(head==NULL)
    return head;
    List *prev=NULL,*curr=head,*next=NULL;
    int count =0;
    while(curr!=NULL&&count<k)
    {
        next=curr->node;
        curr->node=prev;
        prev=curr;
        curr=next;
        count++;
    }
    List * t=groupReverse(curr,k);
    head->node=t;
    return prev;
}
List* iterativeGroupReverse(List* head,int k)
{
    List*curr=head,*next=NULL,*prevFirst=NULL;
    bool firstIteration=true;
    while(curr!=NULL)
    {
        List* first=curr,*prev=NULL;
        int count=0;
        while(curr!=NULL&&count<k)
        {
            next=curr->node;
            curr->node=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(firstIteration)
        {
            head=prev;
            firstIteration=false;
        }
        else
        {
            prevFirst->node=prev;
        }
        prevFirst=first;
    }
    return head;
}
int main()
{
    List *head=NULL;
    for(int i=0;i<8;i++)
    {
        head=insertData(head,i+1);
    }
    printList(head);
    head=groupReverse(head,3);
    cout<<endl;
    printList(head);
    head=iterativeGroupReverse(head,3);
    cout<<endl;
    printList(head);
}