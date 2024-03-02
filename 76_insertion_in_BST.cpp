#include <iostream>
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
    void insertion(node *root, int key)
    {
        node *prev = NULL;
        while (root != NULL)
        {
            prev =root;
            if (root->data == key)
            {
                cout << "Cannot Insert.Number Already Exist ";
            }
            else if (key < root->data)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        node * ptr = create_link(NULL,NULL,key);
        if (key < prev->data)
        {
            prev->left = ptr;
        }else{
            prev->right = ptr;
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
    b.InOrder(p);
    cout<<endl;
    b.insertion(p, 8);
    b.InOrder(p);

    return 0;
}
