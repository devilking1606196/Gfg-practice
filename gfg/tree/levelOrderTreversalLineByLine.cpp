#include<bits/stdc++.h>
using namespace std;
struct tree
{
    int data;
    tree *left,*right;
    tree(int d)
    {
        data=d;
        left=right=NULL;
    }
    void printLevelOrder(tree *root)
    {
        queue<tree*>q;
        q.push(root);
        while(!q.empty())
        {
            tree* curr=q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
        cout<<endl;
    }
    void printLevelOrderLineByLine(tree *root)
    {
        if(root==NULL)
        return;
        queue<tree*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1)
        {
            tree *curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                cout<<endl;
                q.push(NULL);
            }
            else
            {
                cout<<curr->data<<" ";
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
        }
        cout<<endl;
    }
    void printLineByLine(tree* root)//without using NULL
    {
        if(!root)
        return;
        queue<tree*>q;
        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                tree *curr=q.front();
                q.pop();
                cout<<curr->data<<" ";
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            cout<<"\n";
        }
    }
};
int main()
{
    tree *root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->left->left=new tree(40);
    root->left->right=new tree(50);
    root->right->right=new tree(60);
    root->right->right->left=new tree(70);
    root->right->right->right=new tree(80);
    root->printLevelOrder(root);
    root->printLevelOrderLineByLine(root);
    root->printLineByLine(root);
}