#include<bits/stdc++.h>
using namespace std;
int sqauareRoot(int n){
    int s=0,e=n,mid,ans;
    long int sq;
    while(s<=e)
    {
        mid=(s+e)/2;
        sq=mid*mid;
        if(sq==n)
        return mid;
        else if(sq>n)
        {
            e=mid-1;
        }
        else
        {
            ans=mid;
            s=mid+1;
        }

    }
    return ans;
}
double morePrecision(int n,int precision,int temp){
    
    double ans=temp;
    double factor=1;
    for(int i=0;i<precision;i++)
    {
        factor= factor/10;
       double x=ans;
        while(x*x<n){
            ans=x;
            x=x+factor;
        }
    }
    return ans;
}




// double morePrecision(int n, int precision, int tempSol) {
//     double factor = 1;
//     double ans = tempSol;

//     for(int i=0; i<precision; i++) {
//         factor = factor/10;

//         for(double j=ans; j*j<n; j= j+factor ){
//             ans = j;
//         }
//     }
//     return ans;
// }

int main(){
    int x=230;
    cout<<morePrecision(x,3,sqauareRoot(x));
    
}