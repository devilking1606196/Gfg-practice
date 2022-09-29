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
// unordered_map<tree*,int>m;
int height(tree * root)
{
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    l=max(l,r);
    // m.insert({root,l+1});
    return l+1;
}
int diameter(tree *root)
{
    if(!root)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    int curr=l+r+1;
    int ansl=diameter(root->left);
    int ansr=diameter(root->right);
    curr=max(curr,ansl);
    curr=max(curr,ansr);
    return curr;
}
// int mapDiameter(tree*root)
// {
//     if(root==NULL)
//     return 0;
//     if(!root->left&&!root->right)
//     return 1;
//     int curr=1+m[root->left]+m[root->right];
//     int ansl=mapDiameter(root->left);
//     int ansr=mapDiameter(root->right);
//     return max(curr,max(ansl,ansr));
// }
int ans=0;
int diameterOfTree(tree* root)
{
    if(!root)
    return 0;
    int l=diameterOfTree(root->left);
    int r=diameterOfTree(root->right);
    int t=l+r+1;
    l=max(l,r);
    ans=max(ans,t);
    return l+1;
}
int main()
{
    tree*root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(70);
    root->left->left=new tree(30);
    root->left->left->left=new tree(40);
    root->left->left->left->left=new tree(60);
    root->left->left->right=new tree(50);
    root->left->right=new tree(80);
    root->left->right->right=new tree(90);
    root->left->right->right->right=new tree(890);
    root->left->right->right->right->left=new tree(890);
    root->left->right->right->right->left->right=new tree(890);
    root->right->left=new tree(1);
    root->right->left->right=new tree(1);
    root->right->right=new tree(1);
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;
    diameterOfTree(root);
    cout<<ans<<endl;
    // cout<<mapDiameter(root);
}