#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};


//Traversal of linked list

void traversal(node*ptr){
    cout<<"Elements of linked list are "<<endl<<"[";
    while (ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
    cout<<"NULL ]";
    
}

int main(){
    node*head=new(node);
    node*second=new(node);
    node*third=new(node);
    node*fourth=new(node);

    head->data=7;
    head->next=second;

    second->data=9;
    second->next=third;

    third->data=15;
    third->next=fourth;

    fourth->data=19;
    fourth->next=NULL;

    traversal(head);
}