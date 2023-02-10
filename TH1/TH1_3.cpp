#include <iostream>
using namespace std;
int UCLN(int a, int b)
{
    if ((a==0) || (b==0))
        return a+b;
    else
    {
        while (a != b)
            {
                if (a > b)
                    a=a-b;
                else
                    b=b-a;
            }
        return a;
    }

}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"UCLN= "<<UCLN(a,b)<<endl;
    return 0;
}