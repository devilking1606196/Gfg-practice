#include<bits/stdc++.h>
using namespace std;
struct tree
{
    int data;
    tree *left,*right;
    int lcount;
    tree(int d)
    {
        lcount=0;
        data=d;
        left=right=NULL;
    }
};
void printKthSmallest(tree *root,int k,int &count) //inorder trevesrsal
{
    if(root==NULL)
    return;
    printKthSmallest(root->left,k,count);
    count++;
    if(count==k)
    {
        cout<<root->data;
        return;
    }
    printKthSmallest(root->right,k,count);
}
tree * insertBst(tree *root,int d)
{
    if(root==NULL)
    {
        root=new tree(d);
        return root;
    }
    if(d<root->data)
    {
        root->lcount++;
        root->left=insertBst(root->left,d);
    }
    else
    root->right=insertBst(root->right,d);
    return root;
}
tree * Kthsmallest(tree*root,int k)
{
    if(root==NULL)
    return NULL;
    int n=root->lcount+1;
    if(n==k)
    return root;
    else if(k<n)
    {
        return Kthsmallest(root->left,k);
    }
    else
    {
        return Kthsmallest(root->right,k-n);
    }
}
int main()
{
    int arr[]={50,20,100,10,40,70,120,60,80};
    int size=sizeof(arr)/sizeof(arr[0]);
    // tree *root=new tree(50);
    // root->left=new tree(20);
    // root->right=new tree(100);
    // root->left->left=new tree(10);
    // root->left->right=new tree(40);
    // root->right->left=new tree(70);
    // root->right->right=new tree(120);
    // root->right->left->left=new tree(60);
    tree *root=NULL;
    for(int i=0;i<size;i++)
    {
        root=insertBst(root,arr[i]);
    }
    int c=0;
    int k=4;
    printKthSmallest(root,k,c);
    cout<<endl;
    if(Kthsmallest(root,k))
    cout<<Kthsmallest(root,k)->data;
}