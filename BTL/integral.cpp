#include <cstdio>
#include <ctime>
#include <iostream>
using namespace std;
float RandReal( float min, float max )
{
    float scale = float(rand()) / RAND_MAX;
    return min + scale * ( max - min );      
}
float f(float x)
{
    return x*x+2*x+1;
}
float integral(float a, float b)
{
    float sum=0;
    int a1= (int)a;
    int b1= (int)b;
    int n=(rand()%b1)+a1;
    for (int i = 0 ; i < n ; i++)
    {
        float x = RandReal(a, b);
        sum = sum+f(x);
    }
    return (b-a) * (sum / n);
}
int main()
{
    srand(time(NULL));
    float a = integral(10,50);
    cout<<a<<endl;
    return 0;
}