#include <iostream>
using namespace std;

struct queue
{
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct queue *p)
{
    if (p->f == p->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct queue *p)
{
    if (p->r == p->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *p, int val)
{
    if (isFull(p))
    {
        cout << "The queue is overflow" << endl;
    }
    else
    {
        p->r++;
        p->arr[p->r] = val;
    }
}
int dequeue(struct queue *p)
{
    int a = -1;
    if (isEmpty(p))
    {
        cout << "The queue is Empty" << endl;
    }
    else
    {
        p->f++;
        a = p->arr[p->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = -1;
    q.r = -1;
    q.arr = new int(q.size);
    enqueue(&q, 12);
    enqueue(&q, 5);
    enqueue(&q, 5);
    enqueue(&q, 5);

    cout << "The dequeue value is " << dequeue(&q) << endl;
    cout << "The dequeue value is " << dequeue(&q) << endl;

    if (isEmpty(&q))
    {
        cout << "The queue is empty";
    }
    if (isFull(&q))
    {
        cout << "The queue is Full";
    }
}
