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
void printInorder(tree *root)
{
    if(root==NULL)
    return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
pair<tree*,tree*>ans={NULL,NULL};
tree* prevv=NULL;
void fixBST(tree *root)
{
    if(!root)
    return;
    fixBST(root->left);
    if(prevv!=NULL && prevv->data>root->data)
    {
        if(ans.first==NULL)
            ans.first=prevv;
        ans.second=root;
    }
    prevv=root;
    fixBST(root->right);
}
int main()
{
    tree*root=new tree(60);
    root->left=new tree(4);
    root->right=new tree(80);
    root->left->left=new tree(8);
    root->left->right=new tree(10);
    root->right->left=new tree(70);
    root->right->right=new tree(100);
    printInorder(root);
    cout<<endl;
    fixBST(root);
    swap(ans.first->data,ans.second->data);
    // cout<<(ans.first==NULL)<<" "<<(ans.second==NULL);
    printInorder(root);
    deque<int>q;
    q.p
}