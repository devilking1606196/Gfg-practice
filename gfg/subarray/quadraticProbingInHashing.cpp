#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector <int> quadraticProbing(int hashSize,int arr[],int sizeOfArray)
    {
        vector<int> ans(hashSize,-1);
        int size=0;
        for(int i=0;i<sizeOfArray;i++)
        {
            if(size==hashSize)
            break;
            int key=arr[i]%hashSize;
            int count=1;
            int index=key;
            while(ans[index]!=-1&&ans[index]!=arr[i])
            {
                index= (key+(int)pow(count,2))%hashSize;
                count++;
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
int main()
{
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
	    hash = obj.quadraticProbing( hashSize, arr, sizeOfArray);
	    cout<<"after"<<endl;
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	return 0;

}