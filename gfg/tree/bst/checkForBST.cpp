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
bool bstCheckUsingMaxElelment(tree *root)
{
    if(root==NULL)
    return true;
    tree *curr=root->left;
    int l=INT_MIN,r=INT_MAX;
    if(curr)
    l=curr->data;
    curr=root->right;
    while(curr&&curr->left)
    {
        curr=curr->left;
    }
    if(curr)
    r=curr->data;
    if(l>root->data || r<root->data)
    return false;
    return bstCheckUsingMaxElelment(root->left) & bstCheckUsingMaxElelment(root->right);
}
bool checkBstInorder(tree *root,tree *prev=NULL) //O(N)
{
    bool ans=true;
    if(root==NULL)
    return true;
    ans&=checkBstInorder(root->left,prev);
    if(prev&&prev->data>root->data)
    return false;
    prev=root;
    ans&=checkBstInorder(root->right,prev);
    return ans;
}
bool rangeBstCheck(tree * root,int min=INT_MIN,int max=INT_MAX)
{
    if(root==NULL)
    return true;
    if(root->data<min||root->data>max)
    return false;
    return (rangeBstCheck(root->left,min,root->data) & rangeBstCheck(root->right,root->data,max));
}
int main()
{
    tree *root=new tree(20);
    root->left=new tree(8);
    root->right=new tree(30);
    root->right->left=new tree(22);
    root->right->right=new tree(35);
    cout<<boolalpha<<checkBstInorder(root)<<endl;;
    cout<<boolalpha<<bstCheckUsingMaxElelment(root)<<endl;
    cout<<boolalpha<<rangeBstCheck(root)<<endl;
}