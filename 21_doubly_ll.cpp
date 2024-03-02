#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*next;
    struct node*prev;

};

void doublytraversal(node * ptr,struct node * p){
      cout<<"Element in forward order are "<<endl;
       while (ptr!=NULL)
      {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
      }

      cout<<"Element in backword order are "<<endl;
      while (p!=NULL)
      {
        cout<<p->data<<endl;
        p=p->prev;
      }

      cout<<endl<<endl<<endl;

      
};


struct node * insertAtFirst(struct node * head ,int data){
    struct node * ptr =new (node);
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;
    head->prev=ptr;
    return ptr;
}

struct node * insertAtLast(struct node * head ,int data){
    struct node * ptr =new (node);
    struct node * p =head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
p->next=ptr;
ptr->prev=p;
ptr->data=data;
ptr->next=NULL;
 
 return ptr;
    
}

struct node* insert_At_Index(struct node*head,int data,int index)
{
    struct node*r= head->next;
    struct node*p=new(node);
    struct node*q= head;
    p->data=data;
    int i=1;
    while(i!=index-1)
    {
        q=q->next;
        r=r->next;
        i++;
    }
    p->next=r;
    r->prev=p;
    q->next=p;
    p->prev=q;
    return head;
};

struct node* delete_At_Begain(struct node*head)
{
    struct node*q=head;
    head = head->next;
    free(q);
    return head;
};
struct node*delete_At_Index(struct node*head,int index)
{
    struct node*p=head;
    struct node*q=head->next;

    int i=1;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
};

struct node*delete_At_End(struct node *head)
{
    struct node*p=head;
    struct node*q=head->next;
    while(q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
    return head;
};
int main(){
    node*head=new(node);
    node*second=new(node);
    node*third=new(node);
    node*fourth=new(node);
    node*last=new(node);

    head->prev=NULL;
    head->data=5;
    head->next=second;

    second->prev=head;
    second->data=7;
    second->next=third;

    third->prev=second;
    third->data=11;
    third->next=fourth;

    fourth->prev=third;
    fourth->data=16;
    fourth->next=last;

    last->prev=fourth;
    last->data=20;
    last->next=NULL;
    // doublytraversal(head,last);

    // head=insertAtFirst(head,3);
    // doublytraversal(head,last);

    // last=insertAtLast(head,30);

    // head=insert_At_Index(head,9,3);
    head=delete_At_Index(head,3);
    doublytraversal(head,last);
}