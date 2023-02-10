#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack <char> S;
    S.push('A');
    S.push('B');
    S.push('C');
    S.push('D');
    S.push('E');
    S.pop();
    while (!S.empty()) 
    {
        cout << S.top()<<" ";
        S.pop();
    }
    return 0;
}