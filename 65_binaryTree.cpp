#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int val) : data(val) , left(nullptr),right(nullptr){}
};
class BinaryTree{
    node*root;
    public:
    BinaryTree(){
        root = nullptr;
    }
    node * create_link(node *left,node*right,int data){
        node *n = new node(data);
        n->data =data;
        n->left =left;
        n->right=right;
        return n;
    }
     void preOrder(node* root){
        if (root!=NULL)
        {
           cout<<root->data<<" ";
           preOrder(root->left);
           preOrder(root->right);
        }
        
     }
     void postOrder(node* root){
        if (root!=NULL)
        {
           postOrder(root->left);
           postOrder(root->right);
           cout<<root->data<<" ";
        }
        
     }
};
int main(){
    BinaryTree b;
    node* p4 = b.create_link(NULL,NULL,2);
    node* p3 = b.create_link(NULL,NULL,5);
    node* p2 = b.create_link(NULL,NULL,6);
    node* p1 = b.create_link(p3,p4,1);
    node* p = b.create_link(p1,p2,4);
    b.preOrder(p);
    cout<<endl;
    b.postOrder(p);

    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  
}