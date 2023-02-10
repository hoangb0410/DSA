#include <bits/stdc++.h>  
using namespace std;  
// structure of node of doubly linked list
struct Node {
    int data;
    struct Node* next, *prev;
};  
int count_triplets(struct Node* head)
{
    struct Node* ptr1, *ptr2, *ptr3;
    int count = 0;
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)
                if ((ptr1->data + ptr2->data + ptr3->data) == 0)
                    count++;
    return count;
}
void insert(struct Node** head, int data)
{
    // allocate node
    struct Node* temp = new Node();
  
    // put in the data
    temp->data = data;
    temp->next = temp->prev = NULL;
  
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
void printList(struct Node* head)
{
    while (head != NULL) {
        cout<< head->data<<" ";
        head = head->next;
    }
    cout << endl;
} 
// Driver program to test above
int main()
{
    struct Node* head = NULL;
    int n,a[n];
    cin>>n;
    for (int i=0;i<n;i++)
        {
            cin>>a[i];
            insert(&head, a[i]);
        }
    //printList(head);
    cout<< count_triplets(head);
    return 0;
}