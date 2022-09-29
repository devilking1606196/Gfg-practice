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
    void levelOrderPrint(tree *root)
    {
        queue<tree*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                tree *curr=q.front();
                q.pop();
                cout<<curr->data<<" ";
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            cout<<endl;
        }
    }
    void printPreorder(tree*root)
    {
        if(!root)
        return;
        cout<<root->data<<" ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
};
int preIndex=0;
tree * createTree(int in[],int pre[],int s,int e)
{
    if(s>e)
    return NULL;
    tree *root=new tree(pre[preIndex++]);
    // preIndex++;
    int i=s;
    for(;i<=e;i++)
    {
        if(root->data==in[i])
        break;
    }
    root->left=createTree(in,pre,s,i-1);
    root->right=createTree(in,pre,i+1,e);
    return root;
}
int main()
{
    int pre[]={10,20,40,50,30,70,80,90};
    int in[]={40,20,50,10,30,80,70,90};
    int size=sizeof(in)/sizeof(in[0]);
    tree *root=NULL;
    root=createTree(in,pre,0,size-1);
    // root->levelOrderPrint(root);
    root->printPreorder(root);
}
