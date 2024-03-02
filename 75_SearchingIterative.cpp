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

    node* Searching_Iterative(node*root,int key){
     while (root!=NULL)
     {
        if (root->data==key)
        {
            return root;
        }
        else if(key < root->data){
        root =root->left;
        }
        else{
            root = root->right;
        }
     }
     return NULL;
     
    }
    int BST(node *root)
    {
        static node *prev = NULL;
        if (root != NULL)
        {
            {
                if (!BST(root->left))
                {
                    return 0;
                }
                if (prev != NULL && root->data <= prev->data)
                {
                    return 0;
                }
                prev = root;
                return (BST(root->right));
            }
        }

        else
        {
            return 1;
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
    cout<<endl<<b.BST(p)<<endl;
    node*n=b.Searching_Iterative(p,3);
    if (n!=NULL)
    {
    cout<<"Element Found: "<<n->data; 
    }else{
    cout<<"Element not found";
    }

    return 0;
}
