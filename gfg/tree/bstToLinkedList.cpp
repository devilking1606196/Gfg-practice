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
    tree * conevrtToLinkedList(tree *root)
    {
        if(root==NULL)
        return root;
        static tree *prev=NULL;
        tree* head=conevrtToLinkedList(root->left);
        if(prev==NULL)
        head=root;
        else
        {
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        tree *h=conevrtToLinkedList(root->right);
        return head;
    }
    void printList(tree *head)
    {
        while (head!=NULL)
            {
                cout<<head->data<<" ";
                head=head->right;
            }
    }
};

int main()
{
    tree *root=new tree(10);
    root->left=new tree(5);
    root->right=new tree(20);
    root->right->left=new tree(30);
    root->right->right=new tree(35);
    tree *head=root->conevrtToLinkedList(root);
    head->printList(head);
}