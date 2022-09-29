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
void genrerateArray(tree *root,vector<int> &v)
{
    if(!root)
    return ;
    genrerateArray(root->left,v);
    v.push_back(root->data);
    genrerateArray(root->right,v);
}
bool pairWithGivenSUM(tree *root,int sum)
{
    vector<int>v;
    genrerateArray(root,v);
    int s=0,e=v.size()-1;
    while(s<e)
    {
        int n=v[s]+v[e];
        if(n==sum)
        return true;
        else if(n>sum)
        e--;
        else
        s++;
    }
    return false;
}
bool pairSum(tree *root,int sum,unordered_set <int> &s)
{
    bool ans=false;
    if(!root)
    return ans;
    ans|=pairSum(root->left,sum,s);
    int n=sum-root->data;
    if(!s.empty()&&s.find(n)!=s.end())
    return true;
    if(n>0)
    s.insert(root->data);
    ans|=pairSum(root->right,sum,s);
    return ans;
}
int main()
{
    tree *root=new tree(10);
    root->left=new tree(8);
    root->right=new tree(20);
    // root->left->left=new tree(4);
    // root->left->right=new tree(9);
    root->right->left=new tree(11);
    // root->right->right=new tree(30);
    // root->right->right->left=new tree(25);
    int sum=22;
    unordered_set<int>s;
    cout<<boolalpha<<pairWithGivenSUM(root,sum)<<endl<<pairSum(root,sum,s)<<endl;
}