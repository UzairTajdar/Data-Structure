#include <iostream>
using namespace std;

const int size = 100;

class CircularQueue {
private:
    int arr[size];
    int front, rear;

public:
    CircularQueue() : front(0), rear(0) {}

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << data << endl;
            return;
        }

        arr[rear] = data;
        rear = (rear + 1) % size;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int data = arr[front];
        front = (front + 1) % size;
        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        int index = front;
        cout << "Circular Queue elements: ";
        while (index != rear) {
            cout << arr[index] << " ";
            index = (index + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);

    cq.display();


    cq.dequeue();

    cq.enqueue(4);
    cq.enqueue(5);
    
    cq.display();

    return 0;
}
