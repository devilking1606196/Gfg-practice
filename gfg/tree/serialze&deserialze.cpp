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
void print(tree *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
void serialize(tree *root,vector<int> &arr)
{
    if(!root)
    {
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->data);
    serialize(root->left,arr);
    serialize(root->right,arr);
}
int ind=0;
tree* deserialize(vector<int> &arr)
{
    if(ind==arr.size())    
    return NULL;
    if(arr[ind]==-1)
    {
        ind++;
        return NULL;
    }
    tree *root=new tree(arr[ind++]);
    root->left=deserialize(arr);
    root->right=deserialize(arr);
    return root;
}
int main()
{
    tree *root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->left->left=new tree(40);
    root->left->right=new tree(50);
    root->right->right=new tree(60);
    vector<int> arr;
    serialize(root,arr);
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    tree *root1=deserialize(arr);
    print(root);
    cout<<endl;
    print(root1);
}