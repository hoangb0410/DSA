#include <iostream>
using namespace std;
int main()
{
    int A[100],n;
    cout<<"Nhap so phan tu: ";
    cin>>n;
    cout<<"Nhap danh sach cac so nguyen: ";
    for (int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for (int i = n-1; i >=0 ; i--)
        for (int j = 0; j < i; j++)
        {
            if (A[j]>A[j+1])
            {
                int tam=A[j];
                A[j]=A[j+1];
                A[j+1]=tam;
            }
        }
    cout<<"Day tang dan: ";
    for (int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}