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

void verticalCount(tree *root,int i,map <int,int> &m)
{
    if(!root)
    return;
    verticalCount(root->left,i-1,m);
    m[i]+=root->data;
    verticalCount(root->right,i+1,m);
}
void vSum(tree*root)
{
    map<int,int>m;
    verticalCount(root,0,m);
    for(auto sum:m)
    cout<<sum.second<<" ";
}
int main()
{
    tree*root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->left->left=new tree(5);
    root->left->right=new tree(15);
    vSum(root);
}