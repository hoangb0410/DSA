#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
float RandReal( float min, float max )
{
    float scale = float(rand()) / RAND_MAX;
    return min + scale * ( max - min );      
}
int main()
{
    int k=0, n=100000, r=1;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        float x = RandReal(-r,r);
        float y = RandReal(-r,r);
        // Kiem tra diem (x,y) co nam trong hinh tron khong
        if (x*x+y*y<=r)  // distance_center=sqrt(x^2+y^2)
            k++;
    }
    float pi= float (4*k)/n;
    cout<<pi<<endl;
    return 0;
}