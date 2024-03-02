#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
//Traversal of linked list

void traversal(node*ptr){
    cout<<"Elements of linked list are "<<endl;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }  
}
// Case 1:Delete first node from linked list
struct node*deleteHead(struct node * head){
    struct node * ptr =head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2:Delete node at give index from linked list
struct node*deleteAtIndex(struct node * head , int index){
    struct node * ptr =head;
    struct node * q =ptr->next;

    for (int i = 0; i < index-1; i++)
    {
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=q->next;
    free(q);
    return head;
}

// Case 3:Delete node at last from linked list
struct node*deleteAtLast(struct node * head){
    struct node * ptr =head;
    struct node * q =ptr->next;

    while(q->next!=NULL)
    {
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    free(q);
    return head;
}
// Case 4:Delete node at last from linked list
struct node*deleteAtValue(struct node * head , int value){
    struct node * ptr =head;
    struct node * q =ptr->next;

    while(q->data!=value && q->next!=NULL)
    {
        ptr=ptr->next;
        q=q->next;
    }
    if (q->data==value)
    {
    ptr->next=q->next;
    free(q);
    }
    
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
    sixth->next=NULL;

    traversal(head);
    cout<<"After deletion"<<endl;
    // head = deleteHead(head);
    head = deleteAtIndex(head,5);
    // head = deleteAtLast(head);
    // head = deleteAtValue(head,28);
    traversal(head);
}