#include<bits/stdc++.h>
using namespace std;
struct palindrome
{
    char ch;
    palindrome *next;
    palindrome(char c)
    {
        ch=c;
        next=NULL;
    }
};
void insertChar(palindrome**head,char c)
{
    if(*head==NULL)
    {
        *head=new palindrome(c);
        return;
    }
    palindrome *t=*head;
    while(t->next)
    {
        t=t->next;
    }
    t->next=new palindrome(c);
}
void printPalindrome(palindrome*head)
{
    while(head)
    {
        cout<<head->ch<<" ";
        head=head->next;
    }
    cout<<endl;
}
void reverseList(palindrome *head)
{
    palindrome *prev=NULL,*curr=head->next,*ncurr=NULL;
    while(curr)
    {
        ncurr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ncurr;
    }
    head->next=prev;
}
bool palindromeCheck(palindrome *head)
{
    palindrome *slow=head,*fast=head;
    while(fast->next&&fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    reverseList(slow);
    // printPalindrome(head);
    fast=head;
    slow=slow->next;
    while(slow)
    {
        if(slow->ch!=fast->ch)
        return false;
        slow=slow->next;
        fast=fast->next;
    }
    return true;
}
int main()
{
    palindrome *head=NULL;
    insertChar(&head,'m');
    insertChar(&head,'e');
    insertChar(&head,'d');
    insertChar(&head,'e');
    insertChar(&head,'m');
    printPalindrome(head);
    cout<<palindromeCheck(head);
}