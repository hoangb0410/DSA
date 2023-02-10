#include <iostream>
#include <stack>
using namespace std;
int const MAX=100;
struct tree
{
    char Node[MAX];
    int A[MAX];
    int size;
};
void preorder()
{
    tree cay1;
    stack<char> S;
    cay1.size=7;
    int A[cay1.size]={-1,0,0,1,1,1,2};
    for (int i=0;i<cay1.size;i++)
    {
        cay1.A[i]=A[i];
    }
    char node[cay1.size-1]={'A','B','C','D','E','F','G'};
    for (int i=0;i<cay1.size;i++)
    {
        cay1.Node[i]=node[i];
    }
    /*for (int i=0;i<cay1.size;i++)
    {
        cout<<cay1.Node[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<cay1.size;i++)
    {
        cout<<cay1.A[i]<<" ";
    }*/
    static int AC[MAX]; // Khoi tao mang AC co cac phan tu bang 0
    for (int i=cay1.size-1;i>0;i--)
    {
            if (AC[i]==0)
            {
                S.push(cay1.Node[i]);
                AC[i]=1;
            }
            if ((cay1.A[i]!=cay1.A[i-1]))
            {
                S.push(cay1.Node[A[i]]);
                AC[A[i]]=1;
            }
        }
    while (!S.empty()) 
    {
        cout << S.top()<<" ";
        S.pop();
    }

}
void postorder()
{

}
int main()
{
    int N,M,u,v,i;
    preorder();  
    postorder();  
    return 0;
}