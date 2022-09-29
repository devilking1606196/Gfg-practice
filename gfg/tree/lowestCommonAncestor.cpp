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
bool findPath(tree*root,vector<tree*> &v,int x)
{
    if(root==NULL)
    return false;
    v.push_back(root);
    if(root->data==x)
    return true;
    if(findPath(root->left,v,x)||findPath(root->right,v,x))
    return true;
    v.pop_back();
    return false;
}
tree* lca(tree*root,int x,int y)
{
    if(root==NULL)
    return NULL;
    vector<tree*>path1,path2;
    if(!findPath(root,path1,x)||!findPath(root,path2,y))
    {
        return NULL;
    }
    int i;
    for(i=0;i<path1.size()&&i<path2.size();i++)
    {
        if(path1[i]!=path2[i])
        break;
    }
    return path1[i-1];
    return NULL;
}
tree* lcaTreversal(tree* root,int x,int y) //when both x and y present 
{
    if(root==NULL)
    return NULL;
    if(root->data==x||root->data==y)
    {
        return root;
    }
    tree *curr1=lcaTreversal(root->left,x,y);
    tree *curr2=lcaTreversal(root->right,x,y);
    if(curr1!=NULL && curr2!=NULL)
    return root;
    if(curr1)
    return curr1;
    else
    return curr2;
}
int main()
{
    tree*root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->right->left=new tree(40);
    root->right->right=new tree(50);
    root->right->left->left=new tree(60);
    root->right->right->left=new tree(70);
    root->right->right->right=new tree(80);
    cout<<lca(root,60,80)->data<<endl;
    cout<<lcaTreversal(root,60,80)->data;
}