#include<iostream>
using namespace std;

struct queue{
    int size;
    int r;
    int f;
    int * arr;
};
int isEmpty(struct queue * p){
    if (p->f==p->r)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int isFull(struct queue * p){
    if (p->r==p->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue * p,int val){
    if (isFull(p))
    {
       cout<<"The queue is overflow"<<endl;
    }
    else{
         p->r++;
         p->arr[p->r]=val;
    }
}
int dequeue(struct queue * p){
    int a= -1;
    if (isEmpty(p))
    {
       cout<<"The queue is Empty"<<endl;
    }
    else{
         p->f++;
         a= p->arr[p->f];
    }
    return a;
    
}
int main(){
    struct queue q;
    q.size=100;
    q.f=-1;
    q.r=-1;
    q.arr = new int(q.size);    

    int node;
    int i = 5;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    cout<<i<<" ";
    visited[i] = 1;
    enqueue(&q,i);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                enqueue(&q,j);
            }
            
        }
        
    }
    delete []q.arr;
    

}
