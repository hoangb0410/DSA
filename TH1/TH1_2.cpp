#include <iostream>
#include <math.h>
using namespace std;
class Point 
{
    private:
        double x,y;
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
    void input()
    {
        A.nhap();
        B.nhap();
    }
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
    Line AB,CD;
    AB.input();
    CD.input();
    double a1=AB.geta();
    double b1=AB.getb();
    double c1=AB.getc();
    double a2=CD.geta();
    double b2=CD.getb();
    double c2=CD.getc();
    double det = a1*b2 - a2*b1;
    if (det == 0)
    {
       cout<<"NO"<<endl;
    }
    else 
    {
        double x = (b2*c1 - b1*c2)/det;
        double y = (a1*c2 - a2*c1)/det;
        x=round(x*100)/100;
        y=round(y*100)/100;
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}