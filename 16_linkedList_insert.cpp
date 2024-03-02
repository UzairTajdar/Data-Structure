#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

//Insertion at start
struct node* insertAtFirst(struct node *head,int data)
{
    struct node * ptr=new(node);
    ptr->data=data;
    ptr->next=head;
    return ptr; 
};

//Insertion in between
struct node* insertAtIndex(struct node *head,int data,int index)
{
    struct node * ptr=new(node);
    struct node* p = head;
    int i=0;

    while (i!=index-1)
    {
       p=p->next;
       i++;
    }

    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

    return head;
    
};

//Insertion at End
struct node* insertAtEnd(struct node *head,int data)
{
    struct node * ptr=new(node);
    struct node * p =head;
    ptr->data=data;
    
    while (p->next!=NULL)
    {
      p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    
    return head; 
};

//Insertion After Node
struct node* insertAfterNode(struct node *head,struct node *prevNode,int data)
{
    struct node * ptr=new(node);
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head; 
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

int main(){
    node*head=new(node);
    head->data=5;
    head->next=NULL;
    // node*second=new(node);
    // node*third=new(node);
    // node*fourth=new(node);

    // head->data=7;
    // head->next=second;

    // second->data=9;
    // second->next=third;

    // third->data=15;
    // third->next=fourth;

    // third->data=19;
    // third->next=NULL;

    // traversal(head);

    // head=insertAtFirst(head,78);
    // traversal(head);

    // head=insertAtIndex(head,68,2);
    // traversal(head);

    head=insertAtEnd(head,90);
    head=insertAtEnd(head,91);
    head=insertAtEnd(head,92);
    head=insertAtEnd(head,93);
    head=insertAtEnd(head,94);
    traversal(head);

    // head=insertAfterNode(head,second,50);
    // traversal(head);

}