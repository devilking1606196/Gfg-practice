#include<bits/stdc++.h>
using namespace std;

 int reverse(int x) {
     int sign=x<0?-1:1;
        int count=-1;
        int ans=0;
        vector<int>t;
        x=abs(x);
        while(x>0){
            t.push_back(x%10);
            x=x/10;
            count++;
        }
        for(int i=0;i<t.size();i++){
            ans+=pow(10,count)*t[i];
            count--;
        }
        if(ans>INT_MIN&&ans<INT_MAX)
            return ans*sign;
        else 
            return -1;
    }


int main(){
    int x=-123;
    int y=reverse(x);
    cout<<y<<" ";

}