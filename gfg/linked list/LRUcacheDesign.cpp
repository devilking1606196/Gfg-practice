#include<bits/stdc++.h>
using namespace std;
struct cache{
    int data;
    cache *next;
    cache *prev;
    cache(int n)
    {
        data=n;
        next=prev=NULL;
    }
};
cache *head=NULL,*tail=NULL;
void insertBegin(int data)
{
    if(head==NULL)
    {
        head=new cache(data);
        tail=head;
        return;
    }
    else
    {
        head->prev=new cache(data);
        head->prev->next=head;
        head=head->prev;
        return;
    }
}
void removeAndAppendToStart(cache *t)
{
    if(t->next==NULL)
    {
        t->prev->next=NULL;
        tail=t->prev;
    }
    else
    {
        t->prev->next=t->next;
        t->next->prev=t->prev;
    }
    head->prev=t;
    t->next=head;
    head=t;
    head->prev=NULL;
}
void deleteEntry(cache * t)
{
    if(t->next==NULL)
    {
        t->prev->next=NULL;
        tail=t->prev;
    }
    else
    {
        t->prev->next=t->next;
        t->next->prev=t->prev;
    }
    delete(t);
}
void printLRU()
{
    cache*temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
void LRUcacheDesign(int arr[],int size)
{
    unordered_map <int,cache*> m;
    for(int i=0;i<size;i++)
    {
        if(head&&arr[i]==head->data)
        {
            printLRU();
            continue;
        }
        if(m.size()<4 )
        {
            if(m.find(arr[i])==m.end())
            {
                insertBegin(arr[i]);
                m[arr[i]]=head;
            }
            else
            {
                removeAndAppendToStart(m[arr[i]]);
                // OR below
                // deleteEntry(m[arr[i]]);
                // insertBegin(arr[i]);
                // m[arr[i]]=head;
            }
        }
        else
        {
            if(m.find(arr[i])==m.end())
            {
                m.erase(tail->data);
                deleteEntry(tail);
                insertBegin(arr[i]);
                m[arr[i]]=head;
            }
            else
            {
                removeAndAppendToStart(m[arr[i]]);
                // OR below
                // deleteEntry(m[arr[i]]);
                // insertBegin(arr[i]);
                // m[arr[i]]=head;
            }
        }
        printLRU();
    }
}
int main()
{
    int arr[]={10,20,10,10,30,40,50,40,60,30};
    int size=sizeof(arr)/sizeof(arr[0]);
    LRUcacheDesign(arr,size);
    // printLRU();
}