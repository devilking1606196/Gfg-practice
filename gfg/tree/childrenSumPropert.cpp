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
    // bool ans=true;
    bool childrenSum(tree *root)
    {
        if(root==NULL||!root->left&&!root->right)
        return true;
        int sum=0;
        if(root->left)
        sum+=root->left->data;
        if(root->right)
        sum+=root->right->data;
        // if((root->left||root->right)&&sum!=root->data)
        // return false;
        // ans&=childrenSum(root->left);
        // ans&=childrenSum(root->right);
        // return ans;
        return(sum==root->data&&childrenSum(root->left)&&childrenSum(root->right));
    }
};
int main()
{
    tree *root=new tree(3);
    root->left=new tree(1);
    root->right=new tree(2);
    root->left->left=new tree(1);
    root->left->right=new tree(0);
    root->right->left=new tree(1);
    root->right->right=new tree(1);
    cout<<root->childrenSum(root);
}