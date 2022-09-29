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
    void printLeftView(tree *root)
    {
        if(root==NULL)
        return;
        queue<tree*>q;
        q.push(root);
        while(!q.empty())
        {
            cout<<q.front()->data<<" ";
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                tree *curr=q.front();
                q.pop();
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
        }
        cout<<endl;
    }
    int maxLevel=0;
    void printRecursive(tree*root,int level)//using preorder traversal
    {
        if(root==NULL)
        return;
        if(maxLevel<level)
        {
            cout<<root->data<<" ";
            maxLevel=level;
        }
        printRecursive(root->left,level+1);
        printRecursive(root->right,level+1);
    }
};
int main()
{
    tree* root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->left->left=new tree(40);
    root->left->right=new tree(50);
    root->right->left=new tree(60);
    root->right->left->right=new tree(80);
    root->left->right->left=new tree(100);
    root->printLeftView(root);
    root->printRecursive(root,1);
    root->printRecursive(root,1);
}