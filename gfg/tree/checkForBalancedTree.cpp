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
    int heightOfTree(tree *root)
    {
        if(root==NULL)
        return -1;
        int lh=heightOfTree(root->left)+1;
        int rh=heightOfTree(root->right)+1;
        return (max(lh,rh));
    }
    bool isBalancedTree(tree *root)
    {
        if(root==NULL)
        return true;
        int lh=heightOfTree(root->left);
        int rh=heightOfTree(root->right);
        return ((abs(lh-rh)<=1)&&isBalancedTree(root->left)&&isBalancedTree(root->right));
    }
    int isBalanced(tree* root)
    {
        if(root==NULL)
        return 0;
        int lh=isBalanced(root->left)+1;
        if(lh==-1)return -1;
        int rh=isBalanced(root->right)+1;
        if(rh==-1)return -1;
        if(abs(lh-rh)>1)
        {
            return -1;
        }
        else
        {
            return max(lh,rh);
        }
    }
};
int main()
{
    tree *root=new tree(18);
    root->left=new tree(4);
    root->right=new tree(20);
    root->right->left=new tree(13);
    root->right->right=new tree(70);
    root->right->right->left=new tree(35);
    root->left->left=new tree(1);
    root->left->right=new tree(9);
    root->left->right->left=new tree(91);    
    root->left->right->right=new tree(19);
    cout<<root->isBalancedTree(root)<<endl;
    cout<<(root->isBalanced(root)!=-1);
}