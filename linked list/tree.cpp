#include<bits/stdc++.h>
using namespace std;

struct tree{
    int data;
    tree *left;
    tree *right;
    tree()
    {

    }
    tree(int k)
    {
        data=k;
        left=right=NULL;
    }
}; 
tree*node=NULL;

void insert(int data,tree *t)
{
    if(t==NULL)
    {
        t=new tree;
        node=t;
        t->data=data;
        t->left=t->right=NULL;
    }
    else 
    {
        if(t->data>data)
        {
            if(t->left==NULL)
            {
                tree * temp=new tree;
                t->left=temp;
                temp->data=data;
                temp->left=temp->right=NULL;
            }
            else
            {
                insert(data,t->left);
            }
        }
        else
        {
            if(t->right==NULL)
            {
                tree * temp=new tree;
                t->right=temp;
                temp->data=data;
                temp->right=temp->left=NULL;
            }
            else
            {
                insert(data,t->right);
            }
        }
    }
}


void inOrder(tree * t)
{
    if(t)
    {inOrder(t->left);
    cout<<t->data<<"\t";
    inOrder(t->right);
    }
    else
    return;
}

void preorder(tree *t)
{
    if(t)
    {
        cout<<t->data<<"\t";
        preorder(t->left);
        preorder(t->right);
    }
    else
    return;
}

void postorder(tree *t)
{
    if(t)
    {
        postorder(t->left);
        postorder(t->right);
        cout<<t->data<<"\t";
    }
    else
    return;
}
int heightOfTree(tree * root)
{
    if(root==NULL)
    return 0;
    int l=heightOfTree(root->left);
    int r=heightOfTree(root->right);
    int h=max(l,r);
    return h+1;
}

void printKthLevel(tree *root,int k,int n=0)
{
    
    if(!root)
    {
        return;
    }
    // cout<<"root "<<root->data<<" N "<<n<<endl;
    if(k==n)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k,n+1);
    printKthLevel(root->right,k,n+1);

}

void breadthFirstTravesal(tree * root)
{
    queue <tree *> q;
    if(!root)
    return;
    q.push(root);
    while(q.empty()==false)
    {
        tree * t=q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left)
        {
            q.push(t->left);
        }
        if(t->right)
        {
            q.push(t->right);
        }
    }
    
}

int main()
{
    int arr[]={99,121,32,433,1,2,43,45,12};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        insert(arr[i],node);
    }
    inOrder(node);
    cout<<endl;
    preorder(node);
    cout<<endl;
    postorder(node);
    cout<<endl;
    breadthFirstTravesal(node);
    // int h=heightOfTree(node);        //
    // for(int i=0;i<h;i++)             //
    // {                                // BREADTH
    //     printKthLevel(node,i,0);     // FIRST 
    //     cout<<endl;                  // SEARCH
    // }                                //
    // tree *root=new tree(7);
    // root->left=new tree(54);
    // cout<<heightOfTree(root);
}