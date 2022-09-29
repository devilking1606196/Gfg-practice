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
int height(tree *root)
{
    if(!root)
    return 0;
    int l=height(root->left)+1;
    int r=height(root->right)+1;
    return max(l,r);
}
int ans=0;
int timeForTreeBurn(tree*root,int x) //using height
{
    if(root==NULL)
    return 0;
    if(root->data==x)
    return 1;
     int l=timeForTreeBurn(root->left,x);
     int r=timeForTreeBurn(root->right,x);
     if(l!=0)
     {
         if(root->right)
         {
             int h=height(root->right);
             ans=max(h+l,ans);
         }
         ans=max(ans,l);
         l++;
     }
     if(r!=0)
     {
         if(root->left)
         {
             int h=height(root->left);
             ans=max(h+r,ans);
         }
         ans=max(ans,r);
         r++;
     }
     return max(l,r);
}
int ans1=0;
int burnTree(tree *root,int x,int &dis)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==x)
    {
        dis=0;
        return 1;
    }
    int ldis=-1;
    int rdis=-1;
    int l=burnTree(root->right,x,ldis);
    int r=burnTree(root->left,x,rdis);
    if(ldis!=-1)
    {
        ldis++;
        ans1=max(ans1,ldis+r);
        dis=ldis;
    }
    if(rdis!=-1)
    {
        rdis++;
        ans1=max(ans1,rdis+l);
        dis=rdis;
    }
    return max(l,r)+1;
}
int main()
{
    tree *root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->right->left=new tree(3);
    root->left->left=new tree(40);
    root->left->left->left=new tree(90);
    root->left->left->left->left=new tree(47);
    root->left->left->left->left->right=new tree(4);
    root->left->right=new tree(50);
    root->left->right->left=new tree(55);
    root->right->right=new tree(60);
    root->right->right->right=new tree(6);
    root->right->right->right->right=new tree(440);
    timeForTreeBurn(root,4);
    cout<<ans<<endl;
    int dis=-1;
    burnTree(root,4,dis);
    cout<<ans1<<endl;
}