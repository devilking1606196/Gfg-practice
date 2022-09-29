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
void printTopView(tree*root)
{
    queue<pair<int,tree*>>q;
    q.push({0,root});
    map<int,int>m;
    while(!q.empty())
    {
        pair<int,tree*>p=q.front();
        q.pop();
        tree*curr=p.second;
        int hd=p.first;
        if(m.find(hd)==m.end())
        m[hd]=curr->data;
        if(curr->left)
        q.push({hd-1,curr->left});
        if(curr->right)
        q.push({hd+1,curr->right});
    }
    for(auto i:m)
    cout<<i.second<<" ";
}
int main()
{
    tree*root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(50);
    // root->left->left=new tree(30);
    root->left->right=new tree(40);
    root->left->right->right=new tree(5);
    root->right->left=new tree(60);
    root->right->right=new tree(70);
    printTopView(root);
}