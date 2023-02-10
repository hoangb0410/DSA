#include<bits/stdc++.h>
using namespace std; 
class Hash
{
    private:
        int BUCKET;
        // Trỏ đến một mảng chứa gồm các buckets
        list<int> *table;
    public:
        Hash(int V);  // Constructor    
        void insertItem(int x); // inserts a key into hash table
        void deleteItem(int key);// deletes a key from hash table    
        // hash function to map values to key
        int hashFunction(int x) 
        {
            return (2*x+5)%11;
        }
        void displayHash();
}; 
Hash::Hash(int b)
{
    BUCKET = b;
    table = new list<int>[BUCKET];
} 
void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}
void Hash::deleteItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key); 
    // find the key in (index)th list
    list <int> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) 
    {
        if (*i == key)
        break;
    }
    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}
// function to display hash table
void Hash::displayHash() 
{
    for (int i = 0; i < BUCKET; i++) 
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
int main()
{
    // array that contains keys to be mapped
    int a[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    int n = sizeof(a)/sizeof(a[0]);
    // insert the keys into the hash table
    Hash h(11);   // 11 is count of buckets in hash table
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);
    // display the Hash table
    h.displayHash();
    return 0;
} 