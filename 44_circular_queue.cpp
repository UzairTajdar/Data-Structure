#include<iostream>
using namespace std;

struct circular{
   int size;
   int f;
   int r;
   int *arr;
};

int isEmpty(struct circular * p){
   if (p->r==p->f)
   {
    return 1;
   }
   else{
    return 0;
   }
   
}

int isFull(struct circular * p){
   if ((p->r+1)%p->size == p->f)
   {
    return 1;
   }
   else{
    return 0;
   }
}

void enqueue(struct circular * p ,int val){
    if (isFull(p))
    {
        cout<<"Circular Queue Is Full "<<endl;
    }
    else{
        p->r=(p->r+1)%p->size;
        p->arr[p->r] = val;
    }    
}
int dequeue(struct circular * p){
    int a = -1;
    if (isEmpty(p))
    {
        cout<<"Circular Queue Is Empty "<<endl;
    }
    else{
        p->f=(p->f+1)%p->size;
        a = p->arr[p->f];
    }   
    return a; 
}

void display(struct circular *p){
    if (isEmpty(p))
    {
        cout<<"Circular queue is Empty .Can't Display "<<endl;
    }
    int index = p->f + 1 ;
        cout << "Circular Queue elements: ";
        while (index != p->r + 1) {
            cout << p->arr[index] << " ";
            index = (index + 1) % p->size ;
        }
        cout << endl;
}
int main(){
    struct circular q;
    q.f = 0;
    q.r = 0;
    q.size = 8;
    q.arr = new int (q.size);
    
    enqueue(&q , 8 );
    enqueue(&q , 5 );
    enqueue(&q , 3 );
    enqueue(&q , 1 );
    

    cout<<"The dequeue value is "<<dequeue(&q)<<endl;
    cout<<"The dequeue value is "<<dequeue(&q)<<endl;
    cout<<"The dequeue value is "<<dequeue(&q)<<endl;

    enqueue(&q , 12 );
    enqueue(&q , 24 );
    enqueue(&q , 50 );
    enqueue(&q , 40 );
    enqueue(&q , 30 );

    display(&q);

}