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

    node* inOrderPredecessor(node *root){
        root=root->left;
        while (root->right!=NULL)
        {
            root = root->right;
        }
        return root;
        
    };
    
    node * deletion(node * root,int key){
        node * iPre;
        if (root==NULL)
        {
            return NULL;
        }if (root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //searching for the node to be deleted
        if (key < root->data)
        {
            root->left = deletion(root->left,key);
        }
        else if (key > root->data)
        {
            root->right = deletion(root->right,key);
        }
        else{
            iPre = inOrderPredecessor(root);
            root->data = iPre->data;
            root->left =deletion(root->left,iPre->data);
        }
        return root;
        
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
    b.deletion(p, 9);
    cout<<"p->data :"<<p->data<<endl;
    b.InOrder(p);

    return 0;
}
