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
class BinaryTree
{
    node *root;

public:
    BinaryTree()
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
    BinaryTree b;
    node *p4 = b.create_link(NULL, NULL, 5);
    node *p3 = b.create_link(NULL, NULL, 2);
    node *p2 = b.create_link(NULL, NULL, 7);
    node *p1 = b.create_link(p3, p4, 4);
    node *p = b.create_link(p1, p2, 6);
    b.InOrder(p);
    cout<<endl<<b.BST(p);

    // Finally The tree looks like this:
    //      6
    //     / \
    //    4   7
    //   / \
    //  2   5
}