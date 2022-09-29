// #include<bits/stdc++.h>
// using namespace std;
// void print(int x)
// {
//     int n=2*x-1;
//     for(int i=0;i<n;i++)
//     {
//         int p=x;
//         int c=0;
//         for(int j=0;j<n;j++)
//         {
//             cout<<p<<" ";
//             if(c<i)
//             p--;
//             if(c>=n-i-1)
//             p++;

//             c++;
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
//     int x=4;
//     print(x);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int minimized(int a[],int b[],int n,int k)
// {
// 	int ans=INT_MIN;
// 	int ab[n-1];
// 	pair<int,int> p;
// 	deque<pair<int,int>> q;
// 	for(int i=0;i<n-1;i++)
// 	{
// 		int x=a[i]-a[i+1];
//         if(q.empty())
//         q.push_back({x,i});
//         else
//         {
//             if(x>=q.back().first)
//             q.push_back({x,i});
//             else
//             q.push_front({x,i});
//         }
// 	}
//     ans=q.back().first;
//     while(k>0)
//     {
//         p=q.back();
//         q.pop_back();
//         int x=p.first;
//         int i=p.second;
//         int aaa=abs(a[i]-b[i+1]);
//         aaa=max(aaa,a[i+1]-b[i]);
//         if(aaa<x)
//         ans=max(ans,aaa);
//         else
//         ans=max(ans,x);
//         k--;
//     }
// 	return ans;
// }

// int main() 
// {
// 	int t,k,n;
// 	cin>>t;
// 	while(t)
// 	{
// 		cin>>n>>k;
// 		int a[n],b[n];
// 		for(int i=0;i<n;i++)
// 		{
// 			cin>>a[i];
// 		}
// 		for(int i=0;i<n;i++)
// 		{
// 			cin>>b[i];
// 		}
// 		cout<<minimized(a,b,n,k)<<endl;
// 		t--;
// 	}
// }


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string commonString(string s,string t){
        if(s.find(t)!=string::npos)
        return s;
        map<int,string>m;
        int n=s.length(),i=0,n1=t.length();
        string start="",end="";
        while(i<n1)
        {
            start+=t[i];
            end=t[n1-1-i]+end;
            if(s.find(start)!=string::npos)
            {
                if(s.find(start)+start.length()==n)
                {
                    m[s.find(start)]=start;
                }
            }
            if(s.find(end)!=string::npos)
            {
                if(s.find(end)==0)
                {
                    m[s.find(end)]=end;
                }
            }
            i++;
        }
		cout<<boolalpha<<m.empty()<<endl;
		string ans;
		if(s<t)
        ans=s+t;
        else
        ans=t+s;
        for(auto in:m)
        {
			cout<<in.first<<" "<<in.second<<endl;
            if(in.first==0)
            {
                int l=in.second.length();
                start="";
                for(int j=0;j<n1-l;j++)
                {
                    start+=t[j];
                }
                start+=s;  
            }
            else
            {
                int l=in.second.length();
                start="";
                for(int j=l;j<n1;j++)
                {
                    start+=t[j];
                }
                start=s+start;
                
            }
            if(start.length()<ans.length())
			ans=start;
        }
		return ans;
    }
};

{ Driver Code Starts.

int main(){
    
        string s,t;
        cin>>s>>t;
        Solution ob;
        cout<<ob.commonString(s,t)<<endl;
    
    return 0;
}  // } Driver Code Ends



// int main()
// {
// 	int arr1[]={1,23,4,45,6},arr2[]={4,5,6,1,55,67};
// 	int n1=sizeof(arr1)/sizeof(arr1[0]);
// 	int n2=sizeof(arr2)/sizeof(arr2[0]);
// 	unordered_set<int>s;
// 	for(int i=0;i<n1;i++)
// 	{
// 		s.insert(arr1[i]);
// 	}
// 	for(int i=0;i<n2;i++)
// 	{
// 		s.insert(arr2[i]);
// 	}
// 	vector<int>ans;
// 	for(auto i:s)
// 	ans.push_back(i);
// }