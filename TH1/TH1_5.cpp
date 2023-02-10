#include <iostream>
using namespace std;
double max(int n, int a[])
{
    int max=a[0];
    for (int i=1;i<n;i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
double min(int n, int a[])
{
    int min=a[0];
    for (int i=1;i<n;i++)
        if (a[i] < min)
            min = a[i];
    return min;
}
int main()
{
    int A[5];
    for (int i=0;i<5;i++)
        cin>>A[i];
    cout<<min(5,A)+max(5,A)<<endl;
    return 0;
}