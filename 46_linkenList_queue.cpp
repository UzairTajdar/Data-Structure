#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node(int val) : data(val) , next(nullptr){};
};

class Queue{
    private:
    Node * f;
    Node * r;
    public:
    Queue () : f(nullptr) , r(nullptr){};

    void linkedlist(){
        if (f==nullptr)
        {
            cout<<"The Queue is Empty "<<endl;
        }
        else{
            while (f!=nullptr)
            {
                cout<<"The Element is "<<f->data<<endl;
                f=f->next;
            }
            
        }
        
    }
    void Enqueue(int val){
        Node * n = new Node(val);
        if (n==nullptr)
        {
            cout<<"The Queue is Overflow "<<endl;
        }
        else{
            n->next = nullptr;
            cout<<"The Value "<<val<<" is enqueue "<<endl;
            if (f==nullptr)
            {
                f=r=n;
            }
            else{
                r->next = n;
                r=n;
            }
            
        }
        
    }
    int Dequeue(){
        int val = -1;
        Node * n = f;
        if (f==nullptr)
        {
           cout<<"The Queue is Empty . So can't dequeue"<<endl;
        }else{
            val = n->data;
            f = f->next;      
            delete n;
        }
        return val;    
    }
};

int main(){
    Queue q;
    // q.linkedlist();
    q.Dequeue();

    q.Enqueue(5);
    q.Enqueue(99);
    q.Enqueue(89);
    q.Enqueue(6);
    q.Enqueue(4);
    q.Enqueue(12);
    q.Enqueue(8);
    q.Enqueue(56);
    q.Enqueue(44);
     
    cout<<endl;
    cout<<"The dequeue value is "<<q.Dequeue()<<endl;
    cout<<"The dequeue value is "<<q.Dequeue()<<endl;
    cout<<"The dequeue value is "<<q.Dequeue()<<endl;
    cout<<"The dequeue value is "<<q.Dequeue()<<endl;
    cout<<endl;



    q.linkedlist();
}