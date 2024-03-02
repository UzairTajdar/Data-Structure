#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* f;
    Node* r;

public:
    Queue() : f(nullptr), r(nullptr) {}

    void linkedListTraversal() {
        cout << "Printing the elements of this Deque" << endl;
        Node* current = f;
        while (current != nullptr) {
            cout << "Element: " << current->data << endl;
            current = current->next;
        }
    }

    void enqueueFront(int val) {
        Node* newNode = new Node(val);
        if (newNode == nullptr) {
            cout << "Deque is Full" << endl;
        } else {
            newNode->next = f;
            if (f == nullptr) {
                f = r = newNode;
            } else {
                f = newNode;
            }
        }
    }

    void enqueueRear(int val) {
        Node* newNode = new Node(val);
        if (newNode == nullptr) {
            cout << "Deque is Full" << endl;
        } else {
            newNode->next = nullptr;
            if (f == nullptr) {
                f = r = newNode;
            } else {
                r->next = newNode;
                r = newNode;
            }
        }
    }

    int dequeueFront() {
        int val = -1;
        Node* ptr = f;
        if (f == nullptr) {
            cout << "Deque is Empty" << endl;
        } else {
            f = f->next;
            val = ptr->data;
            delete ptr;
        }
        return val;
    }

    int dequeueRear() {
        int val = -1;
        if (f == nullptr) {
            cout << "Deque is Empty" << endl;
        } else {
            if (f == r) {
                val = f->data;
                delete f;
                f = r = nullptr;
            } else {
                Node* ptr = f;
                while (ptr->next != r) {
                    ptr = ptr->next;
                }
                val = r->data;
                delete r;
                r = ptr;
                r->next = nullptr;
            }
        }
        return val;
    }
};

int main() {
    Queue q;
    q.linkedListTraversal();

    cout << "Enqueuing at the front: 10" << endl;
    q.enqueueFront(10);
    q.linkedListTraversal();

    cout << "Enqueuing at the rear: 20" << endl;
    q.enqueueRear(20);
    q.linkedListTraversal();

    cout << "Dequeuing from the front: " << q.dequeueFront() << endl;
    q.linkedListTraversal();

    cout << "Dequeuing from the rear: " << q.dequeueRear() << endl;
    q.linkedListTraversal();

    return 0;
}
