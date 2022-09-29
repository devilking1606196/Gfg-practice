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
void printBottomView(tree *root)
{
    queue<pair<tree*,int>>q;
    q.push({root,0});
    map<int,int>m;
    while(!q.empty())
    {
        pair<tree*,int>p=q.front();
        q.pop();
        tree*curr=p.first;
        int hd=p.second;
        m[hd]=curr->data;
        if(curr->left)
        q.push({curr->left,hd-1});
        if(curr->right)
        q.push({curr->right,hd+1});
    }
    for(auto i:m)
    cout<<i.second<<" ";
}
int main()
{
    tree*root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->left->left=new tree(40);
    root->left->right=new tree(50);
    // root->left->right->right=new tree(5);
    root->right->left=new tree(60);
    root->right->right=new tree(70);
    printBottomView(root);
}