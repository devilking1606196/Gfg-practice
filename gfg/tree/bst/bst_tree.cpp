#include<bits/stdc++.h>
using namespace std;
struct tree 
{
    int data;
    tree *left, *right;
    tree(int x)
    {
        data=x;
        left=right=NULL;
    }
};
tree * insert(int a,tree * root)
{
    if(root==NULL)
    {
        root=new tree(a);
        return root;
    }
    if(a<root->data)
    {
        root->left=insert(a,root->left);
    }
    else
    {
        root->right=insert(a,root->right);
    }
    return root;
}
void print(tree * root)
{
    if(root==NULL)
    return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main()
{
    tree *root=NULL;
    int arr[]={5,3,6,23,54,64,1,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    root=insert(arr[i],root);
    print(root);
}