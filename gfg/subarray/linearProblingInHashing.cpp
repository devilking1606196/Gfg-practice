// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        int size=0;
        
        vector <int>ans(hashSize,-1);
        int key,index;
        for(int i=0;i<sizeOfArray;i++)
        {
            if(size==hashSize)
            {
                break;
            }
            key=arr[i]%hashSize;
            index=key;
            while(ans[index]!=-1&&ans[index]!=arr[i])
            {
                index=(index+1)%hashSize;
            }
            if(ans[index]==-1)
            {
                ans[index]=arr[i];
                size++;
            }
        } 
        
        return ans;
    }

};

// { Driver Code Starts.
int main() {
	
	    int hashSize;
        cout<<"hash size ";
	    cin>>hashSize;
	    
	    int  sizeOfArray;
        cout<<"size";
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    {
            cout<<" value "<<i;
            cin>>arr[i];
        }
	    
	    vector<int> hash;
	    Solution obj;
        cout<<"before"<<endl;
	    hash = obj.linearProbing( hashSize, arr, sizeOfArray);
	    cout<<"after"<<endl;
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	return 0;
}

  // } Driver Code Ends
