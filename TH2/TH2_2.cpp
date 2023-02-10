#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
int size=0;
// Tao va tra ve mot node
Node* getNode(int data)
{
    // khoi tao
    Node* newNode = new Node();
    // insert du lieu
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head_ref, int new_data) 
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    // Move head to new node
    (*head_ref) = new_node;
}
void Insert(Node** current, int p, int x)
{
    if (p<0 || p>size+1)
        cout<<"Vi tri sai."<<endl;
    else
        if (p==0)
        {
            insertAtBeginning(current, x);
        }
        else
        {
            while (p>0) 
            {  
                p--;
                current = &(*current)->next;                          
            }
            Node* temp = getNode(x); 
            temp->next = *current;
            *current = temp;
        }
        size++;
}
void Delete(Node** head_ref, int p)
{
    // Neu linked list rỗng
    if (*head_ref == NULL)
        return; 
    Node* temp = *head_ref;
    if (p == 0) 
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i<p-1; i++)
        temp = temp->next;
    // Neu p lon hon size
    if (temp == NULL || temp->next == NULL)
        return; 

    Node* next = temp->next->next;
    free(temp->next); // Giai phong bo nho
    temp->next = next;
}
void printList(struct Node* head)
{
    while (head != NULL) {
        cout<< head->data<<" ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    int n,p,x;
    string method;
    Node* head = NULL;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>method;
        if (method =="insert")
        {
            cin>>p>>x;
            Insert(&head,p,x);
        }
        else
        {
            cin>>p;
            Delete(&head,p);
        }
    }
    printList(head);
    return 0;
}