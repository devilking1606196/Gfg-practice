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
void verticalTR(tree*root,map<int,vector<int>> &m,int i=0)
{
    if(!root)
    return;
    queue<pair<tree*,int>>q;
    q.push({root,i});
    while(!q.empty())
    {
        pair<tree*,int>p=q.front();
        q.pop();
        m[p.second].push_back(p.first->data);
        if(p.first->left)
        q.push({p.first->left,p.second-1});
        if(p.first->right)
        q.push({p.first->right,p.second+1});
    }
}
void verticalTraversal(tree *root)
{
    map<int,vector<int>>m;
    verticalTR(root,m);
    for(auto i:m)
    {
        for(auto j:i.second)
        cout<<j<<" ";
        cout<<endl;
    }
}
int main()
{
    tree *root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->right->left=new tree(5);
    root->left->left=new tree(40);
    root->left->right=new tree(50);
    verticalTraversal(root);
}