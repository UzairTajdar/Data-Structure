#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

void traversal(struct node * head){
    struct node * ptr =head;
    do
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    } while (ptr!=head);
    
}

struct node * insertAtFirst(struct node * head , int data){
    struct node * ptr = new (node);
    struct node * p = head->next;
    ptr->data=data;
    while (p->next!=head)
    {
       p=p->next;
    }
    p->next = ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

int main(){
    node*head=new(node);
    node*second=new(node);
    node*third=new(node);
    node*fourth=new(node);
    node*fifth=new(node);
    node*sixth=new(node);

    head->data=7;
    head->next=second;

    second->data=9;
    second->next=third;

    third->data=15;
    third->next=fourth;

    fourth->data=19;
    fourth->next=fifth;

    fifth->data=23;
    fifth->next=sixth;

    sixth->data=28;
    sixth->next=head;
    traversal(head);
    cout<<"Elements after insertion at first"<<endl;
    head = insertAtFirst(head,6);
    traversal(head);
}