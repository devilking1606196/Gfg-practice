#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string s,int n)
{
    stack<char> stack1;
    stack<char> stack2;
    for(auto i:s)
    {
        if(i=='{'||i=='}'||i=='['||i==']'||i=='('||i==')')
        {
            stack1.push(i);
        }
    }
    
    while(!stack1.empty())
    {
        if(stack1.top()==')'||stack1.top()==']'||stack1.top()=='}')
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        else
        {
            if(stack2.empty())
            {
                return false;
            }
            if(stack2.top()==')'&&stack1.top()=='(')
            {
                stack1.pop();
                stack2.pop();
            }
            else if(stack2.top()=='}'&&stack1.top()=='{')
            {
                stack1.pop();
                stack2.pop();
            }
            else if(stack2.top()==']'&&stack1.top()=='[')
            {
                stack1.pop();
                stack2.pop();
            }
            else
            return false;
        }
    }
return true;
}



int main()
{
    string s="{[()]{}[]}";
    cout<<isBalanced(s,s.length());

}