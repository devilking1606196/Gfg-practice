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
};
int countNodes(tree * root)
{
    if(root==NULL)
    {
        return 0;
    }
    // int l=countNodes(root->left);
    // int r=countNodes(root->right);
    // return l+r+1;
    return countNodes(root->left)+countNodes(root->right)+1;
}
int nodes(tree *root) // O (log(N)*log(N))
{
    tree * curr=root;
    int l=0,r=0;
    if(!root)
    return 0;
    while(curr)
    {
        curr=curr->left;
        l++;
    }
    curr=root;
    while(curr)
    {
        curr=curr->right;
        r++;
    }
    if(l==r)
        return pow(2,l)-1;
    else
        return nodes(root->left)+nodes(root->right)+1;
}
int main()
{
    tree *root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->left->left=new tree(40);
    root->left->right=new tree(50);
    root->right->left=new tree(60);
    // root->right->right=new tree(70);
    cout<<countNodes(root)<<endl;
    cout<<nodes(root)<<endl;
}