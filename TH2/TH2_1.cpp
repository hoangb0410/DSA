#include <iostream>
using namespace std;
int main()
{
    int n,count=0;
    int a[n];
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (a[i]==a[j])
                count++;
    cout<<count<<endl;
    return 0;
}