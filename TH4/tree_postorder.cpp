#include<iostream>
using namespace std;
struct node 
{
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) 
{
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}
void postorder(struct node *root) 
{
   if (root != NULL) 
   {
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
   }
}
struct node* insertNode(struct node* node, int val) 
{
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}
int main() 
{
   struct node *root = NULL;
   int M,N,u,v;
   cin>>M,N;
   for (int i=1;i<=M;i++)
   {
    cin>>u>>v;
   }
   root = insertNode(root, 2);
   insertNode(root, 3);
   insertNode(root, 4);
   insertNode(root, 5);
   postorder(root);
   return 0;
}