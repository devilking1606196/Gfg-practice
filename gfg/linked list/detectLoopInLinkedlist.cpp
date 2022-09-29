#include<bits/stdc++.h>
using namespace std;
class List
{
    public:
    int data;
    List *node;    // can be done by modifying the class by adding a field visited
    List(int d)    // we can create a dummy list can destory the original list to find the loop
    {
        data=d;
        node=NULL;  
    }
};
List * insertData(List*head,int n)
{
    List *t=new List(n);
    if(head==NULL)
    {
        return t;
    }
    List *temp=head;
    while(head->node!=NULL)
    {
        head=head->node;
    }
    head->node=t;
    return temp;
}
void printList(List*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->node;
    }
}
bool findLoops(List *head) //O(N^2)
{
    List* travel=head;
    while(travel!=NULL)
    {
        List* start=head,*next=travel->node;
        while(start!=travel)
        {
            if(start==next)
            {
                return true;
            }
            start=start->node;
        }
        travel=travel->node;
    }
    return false;
}
bool findLoopInList(List*head)//O(N)
{
    unordered_set<List*> s;
    while(head!=NULL)
    {
        if(s.find(head)!=s.end())
        {
            return true;
        }
        s.insert(head);
        head=head->node;
    }
    return false;
}
bool usingDummyFindLoop(List *head)
{
    List * dummy;
    while(head)
    {
        List *t=head;
        head=head->node;
        t->node=dummy;
        if(head==dummy)
        return true;
    }
    return false;
}

// Floys cycle also used in repeattative element
bool findLoopUsingFloydsCycle(List* head)
{
    List*slow=head,*fast=head;
    while(fast!=NULL&&fast->node!=NULL)
    {
        slow=slow->node;
        fast=fast->node->node;
        if(slow==fast)
        return true;
    }
    return false;
}
void detectAndRemoveLoopInList(List* head)
{
    List *slow=head,*fast=head;
    while(fast!=NULL&&fast->node!=NULL)
    {
        slow=slow->node;
        fast=fast->node->node;
        if(slow==fast)
        break;
    }
    if(slow!=fast)
    return;
    fast=head;
    while(fast->node!=slow->node)
    {
        fast=fast->node;
        slow=slow->node;
    }
    slow->node=NULL;
}
void deleteANodeWithPointerGiven(List * p)//pointer will never be the last node in the list
{
    List* temp=p->node;
    p->data=p->node->data;
    p->node=p->node->node;
    delete(temp);
}
List * deleteNode(List **head,List*p)
{
    List *tem=p->node;
    if(*head==p)
    {
        *head=(*head)->node;
        delete p;
        return tem;
    }
    List *temp=*head;
    while(temp->node!=p)
    {
        temp=temp->node;
    }
    temp->node=temp->node->node;
    delete(p);
    return tem;
}
List * segeregateEvenAndOdd(List *head) //O(N^2)
{
    List * last=head,*temp=head,*prev=NULL;
    while(last->node!=NULL)
    {
        last=last->node;
    }
    while(temp!=last)
    {
        if(temp->data%2==1)
        {
            head=insertData(head,temp->data);
            temp=deleteNode(&head,temp);
        }
        else
        temp=temp->node;
    }
    if(temp->data%2==1)
        {
            head=insertData(head,temp->data);
            temp=deleteNode(&head,temp);
        }
    return head;    
}
List * segereagteList(List* head)
{
    List*oS=NULL,*oE=NULL,*eS=NULL,*eE=NULL;
    for(List*temp=head;temp!=NULL;temp=temp->node)
    {
        int n=temp->data;
        if(n%2)
        {
            if(oS==NULL)
            {
                oS=temp;
                oE=temp;
            }
            else
            {
                oE->node=temp;
                oE=oE->node;
            }
        }
        else
        {
            if(eS==NULL)
            {
                eS=temp;
                eE=temp;
            }
            else
            {
                eE->node=temp;
                eE=eE->node;
            }
        }
    }
    if(oS==NULL||eS==NULL)
    return head;
    eE->node=oS;
    oE->node=NULL;
    return eS;
}
int main()
{
    List* head=NULL;
    for(int i=1;i<9;i++)
    {
        head=insertData(head,i);
    }
    List*temp=head,*Next=NULL;
    int count=0;
    while(temp->node!=NULL)
    {
        count++;
        if(count==3)
        Next=temp;
        temp=temp->node;
    }
    temp->node=Next;
    
    cout<<boolalpha<<findLoopInList(head)<<endl<<findLoops(head)<<endl<<findLoopUsingFloydsCycle(head)<<endl;
    detectAndRemoveLoopInList(head);
    deleteANodeWithPointerGiven(Next);
    printList(head);
    head=segeregateEvenAndOdd(head);
    cout<<endl;
    printList(head);
    head=segereagteList(head);
    cout<<endl;
    printList(head);
}