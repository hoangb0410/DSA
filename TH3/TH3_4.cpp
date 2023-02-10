#include <iostream>
#include <map>
#include <string>
using namespace std;
class student
{
    private:
        int ID;
        string Name;
        string Class;
    public:
        student(int I, string N, string C):
                        ID(I), Name(N), Class(C)
                        {
                        }
        int getID()
        {
            return ID;
        }
        string getName()
        {
            return Name;
        }
        string getClass()
        {
            return Class;
        }
        bool operator<(const student& userObj) const
    {
        if (userObj.ID < this->ID)
            return true;
    }
};
map <int,student> list_student;
void Insert(int ID, string Name, string Class)
{
    list_student.insert(pair<int,student>(ID,student(ID,Name,Class)));
}
void Delete(int ID)
{
    list_student.erase(ID);
}
string Infor(int ID)
        {
            auto it = list_student.find(ID);
            if ( it == list_student.end() )
            {  
            cout<<"NA,NA"<<endl;  
            }   
            else
            {
                cout << it->second.getName() <<","<< it->second.getClass() << endl;
            }
        }
int main()
{
    int n;    
    Insert(1,"Tuan","K61CS");
    Insert(2,"Vinh","K43C");
    Infor(3);
    Infor(2);
    Delete(2);
    Infor(2);
    /*map<int,student>::iterator it;
     
    for (it=list_student.begin(); it != list_student.end(); it++)
    {
        cout << it->first << " :: " << it->second.getName() << endl;
    }*/
    
    return 0;
}