#include<bits/stdc++.h>
using namespace std;
//reverse
// int main()
// {
//     vector <int> v={5,7,3,4,8};
//     reverse(v.begin(),v.end());
//     for( int i:v)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     int arr[]={1,2,3,4,5,6};
//     reverse(arr+2,arr+6);
//     for(int i: arr)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     cout<<size(arr);
// }



// Merge sorted array


int main()
{
    vector <int> a={1,3,5,7,9},b={2,4,6,8};
    vector <int> ans;
    int a1=a.size(),b1=b.size();
    int s= a1+b1;
    int j=0,k=0;
    for(int i=0;i<s;i++)
    {
        if(a[j]<b[k])
        {
            ans[i]=a[j];
            j++;
        }
        else if(a[j]>b[k])
        {
            ans[i]=b[k];
            k++;
        }
        else{
            ans[i++]=a[j];
            ans[i]=b[k];
            j++;k++;
        }
        if(j>a1||k>b1)
        return 0;
    }
    while(j<a1)
    {
        ans.push_back(a[j]);
        j++;
    }
    while(k<b1)
    {
        ans.push_back(a[k]);
        k++;
    }
    for(int i:ans)
    {
        cout<<i<<" ";
    }
}