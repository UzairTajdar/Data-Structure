#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BinarySearching
{
    node *root;

public:
    BinarySearching()
    {
        root = nullptr;
    }
    node *create_link(node *left, node *right, int data)
    {
        node *n = new node(data);
        n->data = data;
        n->left = left;
        n->right = right;
        return n;
    }
    void InOrder(node *root)
    {
        if (root != NULL)
        {
            InOrder(root->left);
            cout << root->data << " ";
            InOrder(root->right);
        }
    }

    node* Searching(node*root,int key){
        if (root==NULL)
        {
           return NULL;
        }
        
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return Searching(root->left,key);
    }
    else
    {
        return Searching(root->right,key);
    }
    }
};
int main()
{
   BinarySearching b;
    node *p4 = b.create_link(NULL, NULL, 5);
    node *p3 = b.create_link(NULL, NULL, 2);
    node *p2 = b.create_link(NULL, NULL, 7);
    node *p1 = b.create_link(p3, p4, 4);
    node *p = b.create_link(p1, p2, 6);
    // b.InOrder(p);
    node*n=b.Searching(p,8);
    if (n!=NULL)
    {
    cout<<"Element Found: "<<n->data; 
    }else{
    cout<<"Element not found";
    }

    return 0;
}
