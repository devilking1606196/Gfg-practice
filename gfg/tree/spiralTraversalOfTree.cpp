#include<bits/stdc++.h>
using namespace std;
struct tree
{
    int data;
    tree*left,*right;
    tree(int d)
    {
        data=d;
        left=right=NULL;
    }
};
void printSpiralQueueStack(tree * root)
{
    if(!root)
    return;
    bool reverse=false;
    queue <tree*> q;
    stack<int> s;
    q.push(root);
    while(!q.empty())
    {
        int count =q.size();
        for(int i=0;i<count;i++)
        {
            tree*curr=q.front();
            q.pop();
            if(reverse)
            {
                s.push(curr->data);
            }
            else
            {
                cout<<curr->data<<" ";
            }
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
        if(reverse)
        {
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse=!reverse;
    }
    cout<<endl;
}
void spiralDeque(tree * root)
{
    if(!root)
    return;
    deque <tree*> dq;
    bool rev=false;
    dq.push_back(root);
    while(!dq.empty())
    {
        int count=dq.size();
        for(int i=0;i<count;i++)
        {
            if(rev)
            {
                tree*curr=dq.back();
                dq.pop_back();
                cout<<curr->data<<" ";
                if(curr->right)
                dq.push_front(curr->right);
                if(curr->left)
                dq.push_front(curr->left);
            }
            else
            {
                tree* curr=dq.front();
                dq.pop_front();
                cout<<curr->data<<" ";
                if(curr->left)
                dq.push_back(curr->left);
                if(curr->right)
                dq.push_back(curr->right);
            }
        }
        rev=!rev;
    }
    cout<<endl;
}
void spriralStackStack(tree* root)
{
    if(!root)
    return;
    stack <tree*> s1,s2;
    s1.push(root);
    while(!s1.empty()||!s2.empty())
    {
        while(!s1.empty())
        {
            tree *curr=s1.top();
            s1.pop();
            cout<<curr->data<<" ";
            if(curr->left)
            s2.push(curr->left);
            if(curr->right)
            s2.push(curr->right);
        }
        while(!s2.empty())
        {
            tree*curr=s2.top();
            s2.pop();
            cout<<curr->data<<" ";
            if(curr->right)
            s1.push(curr->right);
            if(curr->left)
            s1.push(curr->left);
        }
    }
    cout<<endl;
}
int main()
{
    tree*root=new tree(1);
    root->left=new tree(2);
    root->right=new tree(3);
    root->right->left=new tree(4);
    root->right->right=new tree(5);
    root->right->left->left=new tree(6);
    root->right->left->right=new tree(7);
    root->right->right->right=new tree(8);
    root->right->left->left->left=new tree(9);
    root->right->left->left->right=new tree(10);
    root->right->right->right->left=new tree(11);
    root->right->right->right->right=new tree(12);
    // root=NULL;
    printSpiralQueueStack(root);
    spiralDeque(root);
    spriralStackStack(root);
}