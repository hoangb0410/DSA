#include <iostream>
using namespace std;
bool Majority(int A[], int n)
{
    int i=rand()%(n-1);
    int x=A[i];
    int k=0;
    for (int j=0;j<n;j++)
        if (A[j]==x)
            k++;
    if (k>n/2)
        return true;
    else 
        return false;
}
int main()
{
    int A[10]={1,7,1,1,1,1,1,2,4,5};
    cout<<Majority(A,10);
    return 0;
}