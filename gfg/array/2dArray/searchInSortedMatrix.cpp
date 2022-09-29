#include<bits/stdc++.h>
using namespace std;
const int r=4,c=4;
int arr[r][c]={{10,20,30,40},
              {15,25,35,45},
              {27,29,37,48},
              {32,33,39,54}};
// int arr[2][2]={{10,12},
//               {20,30}};
void search(int n)
{
    int i=0,j=0;
    while(i<r&&j<c)
    {
        if(arr[i][j]>n)
        {
            cout<<"Not found";
            return ;
        }
        else if(arr[i][j]==n)
        {
            cout<<"found at"<<i<<j;
            return;
        }
        else 
        {
            bool check=false;
            if((j+1)<c && arr[i][j+1]<=n)
            {
                j++;
                check=true;
            }
            if((i+1)<r && arr[i+1][j]<=n)
            {
                i++;
                check=true;
            }
            if(!check)
            {
                cout<<"Not found";
                return ;
            }
        }
    }
return;
}
int main()
{
    search(15);
}