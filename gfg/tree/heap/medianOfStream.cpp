#include<bits/stdc++.h>
using namespace std;
struct tree
{
    float data;
    tree *left,*right;
    int lcount;
    tree(int d)
    {
        data=d;
        left=right=NULL;
        lcount=0;
    }
};
tree * insertData(tree *root,int x)
{
    if(root==NULL)
    {
        root=new tree(x);
        return root;
    }
    if(x<root->data)
    {
        root->lcount++;
        root->left=insertData(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=insertData(root->right,x);
    }
    return root;
}
tree * KthSmallest(tree *root,int k)
{
    if(!root)
    return NULL;
    if(root->lcount+1==k)
    {
        return root;
    }
    else if(root->lcount+1<k)
    {
        return KthSmallest(root->right,k-1-root->lcount);
    }
    else
    return KthSmallest(root->left,k);
}
vector<float> medianOfStream(int arr[],int size)
{
    vector<float>res;
    priority_queue<int> pqmax;
    priority_queue<int,vector<int>,greater<int>>pqmin;
    pqmax.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<size;i++)    
    {
        if(i%2==1)
        {
            if(pqmax.top()>arr[i])
            {
                int x=pqmax.top();
                pqmax.pop();
                pqmax.push(arr[i]);
                pqmin.push(x);
            }
            else
            {
                pqmin.push(arr[i]);
            }
        }
        else
        {
            

            if(arr[i]>pqmin.top())
            {
                int x=pqmin.top();
                pqmin.pop();
                pqmin.push(arr[i]);
                pqmax.push(x);
            }
            else
            {
                pqmax.push(arr[i]);
            }
        }
        if(i%2==0)
        {
            res.push_back(pqmax.top());
        }
        else
        {
            float t=(pqmax.top()+pqmin.top());
            t/=2;
            res.push_back(t);
        }
    }
    return res;
}

void medianSortedArray(int arr[],int n)
{
    int temp[n];
    int size=0;
    for(int i=0;i<n;i++)
    {
        temp[i]=arr[i];
        size++;
        int j=i;
        while(j>0&&temp[j]<temp[j-1])
        {
            swap(temp[j],temp[j-1]);
            j--;
        }
        if(size%2==0)
        cout<<(float)(temp[size/2]+temp[size/2-1])/2<<" ";
        else
        cout<<temp[size/2]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={25,7,10,15,20,34,12};
    int size=sizeof(arr)/sizeof(arr[0]);
    vector<float>ans;
    ans=medianOfStream(arr,size);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    medianSortedArray(arr,size);
    tree *root=NULL;  //using Tree Structure
    for(int i=0;i<size;i++)
    {
        root=insertData(root,arr[i]);
        int s=i+1;
        if(s%2==1)
        {
            cout<<KthSmallest(root,(s/2)+1)->data<<" ";
        }
        else
        {
            double an=KthSmallest(root,(s/2)+1)->data+KthSmallest(root,(s/2))->data;
            an/=2;
            cout<<an<<" ";
        }
    }
}