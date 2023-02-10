#include <iostream>
#include <map>
#include <string>
using namespace std;
class User
{
    string m_id;
    string m_name;
public:
    User(string name, string id) :
            m_id(id), m_name(name)
    {
    }
    const string& getId() const
    {
        return m_id;
    }
    const string& getName() const
    {
        return m_name;
    }
    bool operator<(const User& userObj) const
    {
        if (userObj.m_id < this->m_id)
            return true;
    }
};
void example_1()
{
    map<User, int> m_UserInfoMap;
    m_UserInfoMap.insert(make_pair<User, int>(User("Mr.X", "3"), 100));
    m_UserInfoMap.insert(make_pair<User, int>(User("Mr.X", "1"), 120));
    m_UserInfoMap.insert(make_pair<User, int>(User("Mr.Z", "2"), 300));
    map<User, int>::iterator it = m_UserInfoMap.begin();
    for (; it != m_UserInfoMap.end(); it++)
    {
        cout << it->first.getName() << " :: " << it->second << endl;
    }
}
struct UserNameComparator
{
    bool operator()(const User &left, const User &right) const
    {
        return (left.getName() > right.getName());
    }
};
void example_2()
{
    map<User, int, UserNameComparator> m_UserInfoMap;
    m_UserInfoMap.insert(make_pair<User, int>(User("Mr.X", "3"), 100));
    m_UserInfoMap.insert(make_pair<User, int>(User("Mr.X", "1"), 120));
    m_UserInfoMap.insert(make_pair<User, int>(User("Mr.Z", "2"), 300));
    map<User, int, UserNameComparator>::iterator it =
            m_UserInfoMap.begin();
    for (; it != m_UserInfoMap.end(); it++)
    {
        cout << it->first.getName() << " :: " << it->second << endl;
    }
}
int main()
{
    cout << "EXAMPLE 1 :: Comparing by ID" << endl;
    example_1();
    cout << "EXAMPLE 1 :: Comparing by NAME" << endl;
    example_2();
    return 0;
}