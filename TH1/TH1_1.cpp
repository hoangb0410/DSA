#include <iostream>
#include <string>
using namespace std;
int length(string s)
{
    int i=0;
    while (s[i] != NULL)
    ++i;
    return i-1;
    
}
int main()
{
    string s;
    cout<<"Nhap vao chuoi ky tu: ";
    getline(cin,s);
    cout<<"Chuoi dao nguoc: ";
    for (int i=length(s);i>=0;i--)
        cout<<s[i];
    return 0;
}