#include <iostream>
#include <math.h>
using namespace std;
class Point 
{
    private: 
        double x;
        double y;
    public:
        Point()
        {
            x=0; y=0;
        }
        void nhap()
        {
            cin>>x>>y;
        }
        double getX()
        {
            return x;
        }
        double getY()
        {
            return y;
        }
};
class Line
{
private:
    Point A,B;
public:
    double geta()
    {
        return B.getY()-A.getY();
    }
    double getb()
    { 
        return A.getX()-B.getX();
    }
    double getc() 
    {
        return geta()*(A.getX()) + getb()*(A.getY());
    } 
};
int main()
{
    Point A,B,C,D;
    A.nhap();
    B.nhap();
    C.nhap();
    D.nhap();
    Line AB,CD;
    double a1=AB.geta();
    double b1=AB.getb();
    double c1=AB.getc();
    double a2=CD.geta();
    double b2=CD.getb();
    double c2=CD.getc();
    double det = a1*b2 - a2*b1;
    cout<<AB.geta()<<endl;
    return 0;
}