#include <iostream>
using namespace std;
#define SIZE 5
int A[SIZE];
int top = -1;
bool isempty()
{
    if (top==-1)
        return true;
    else
        return false;
}
void push(int x)
{
    if(top==SIZE-1)
    {    
        cout<<"Stack is full!\n";
    }
    else
    {
        top++;
        A[top]=x;
    }
}
void pop()
{
    if  (isempty())
        cout<<"Stack is empty!\n";
    else
        top--;
}
void displayStack()
{
    if  (isempty())
    {
        cout<<"Stack is empty!\n";
    }
    else
    {
        for(int i=0 ; i<=top; i++)
            cout<<A[i]<<" ";
        cout<<"\n";
    }

}
int main()
{
    int n,x;
    cin>>n;
    string method;
    for (int i=1;i<=n;i++)
    {
        cin>>method;
        if (method=="push")
        {   
            cin>>x;
            push(x);
        }
        else 
            pop();
    }
    displayStack();
    return 0;
}