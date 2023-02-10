#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int SIZE=11;
    srand(time(NULL));
    for (int i=1;i<=10;i++)
    {
        int randomX = ((2*rand())+1)%(SIZE-1); 
        cout<< randomX<<" ";	
    }        
    return 0;
}