#include<bits/stdc++.h>
using namespace std;
void printDigitsAfterDecimal(const string &num)
{
    int posOfDecimal=num.find('.');
    if(posOfDecimal==string::npos)
    {
        cout<<" ";
    }
    else
    {
        cout<<num.substr(posOfDecimal+1);
    }
    cout<<endl;
}
int main()
{
    string num="12.3321";
    printDigitsAfterDecimal(num);
}