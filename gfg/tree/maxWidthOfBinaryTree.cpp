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
    int maxWidthOfTree(tree*root)
    {
        int ans=0;
        queue<tree*> q;
        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            ans=max(ans,count);
            for(int i=0;i<count;i++)
            {
                tree*curr=q.front();
                q.pop();
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
        }
        return ans;
    }
};
int main()
{
    tree *root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);
    root->left->left=new tree(40);
    root->left->right=new tree(45);
    root->right->left=new tree(50);
    root->right->right=new tree(60);
    root->left->left->left=new tree(70);
    cout<<root->maxWidthOfTree(root);
}