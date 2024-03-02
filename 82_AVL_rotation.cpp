#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
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
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    node *create_link(int data)
    {
        node *n = new node(data);
        n->data = data;
        n->left = NULL;
        n->right = NULL;
        n->height = 1;
        return n;
    }

    void preOrder(node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    int Balanced_factor(node *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        return getHeight(n->left) - getHeight(n->right);
    }

    node *insert(node *root, int key)
    {
        if (root == nullptr)
        {
            return create_link(key);
        }

        if (key < root->data)
        {
            root->left = insert(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = insert(root->right, key);
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = Balanced_factor(root);

        // Left Left Case
        if (bf > 1 && key < root->left->data)
        {
            return rightRotate(root);
        }
        // Right Right Case
        if (bf < -1 && key > root->right->data)
        {
            return leftRotate(root);
        }
        // Left Right Case
        if (bf > 1 && key > root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // Right Left Case
        if (bf < -1 && key < root->right->data)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    int getHeight(node *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        return n->height;
    }

    node *rightRotate(node *y)
    {
        node *x = y->left;
        node *t2 = x->right;

        x->right = y;
        y->left = t2;

        x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
        y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
        return x;
    }
    node *leftRotate(node *x)
    {
        node *y = x->right;
        node *t2 = y->left;

        x->right = t2;
        y->left = x;

        x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
        y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
        return y;
    }
};
int main()
{
    BinarySearching b;
    node *root = nullptr;

    root = b.insert(root, 3);
    root = b.insert(root, 5);
    root = b.insert(root, 12);
    root = b.insert(root, 15);
    root = b.insert(root, 6);
    root = b.insert(root, 4);

    b.preOrder(root);

    return 0;
}
