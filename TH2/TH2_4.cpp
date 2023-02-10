#include <iostream>
using namespace std;
#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;
bool isempty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}
void enqueue(int x)
{    
    if (rear == SIZE-1)
        cout<<"Queue is full \n";
    else
    {
        if( front == -1)
        front = 0;
        rear++;
        A[rear] = x;
    }
}
void dequeue()
{
    if( isempty() )
        cout<<"Queue is empty\n";
    else
        if( front == rear )
        front = rear = -1;
        else
    front++;
}
void displayQueue()
{
    if(isempty())
        cout<<"Queue is empty\n";
    else
    {
        for( int i=front ; i<= rear ; i++)
            cout<<A[i]<<" ";
            cout<<"\n";
    }
}
int main()
{
    int n,x;
    string method;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>method;
        if (method=="enqueue")
        {   cin>>x;
            enqueue(x);
        }
        else
            dequeue();
    }
    displayQueue();
    return 0;
}