#include <iostream>
using namespace std;

int arr[] = {2, 3, 4, 6, 8, 9};
int size = sizeof(arr) / sizeof(arr[0]);

int getLength() {
    return size;
}

void display() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert(int element, int index) {
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;
    size += 1;
}

void dlt(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = 0; // Set the last element to 0 (optional)
        size -= 1;
    }
}

int main() {
    display();
    insert(9, 0);   //insert at the first
    insert(0, size);   //insert at the end
    display();
    cout << "Length: " << getLength()<<endl;
    dlt(0);        //delete at the first
    dlt(size-1);     //insert at the end
    display();
    cout << "Length: " << getLength();

    return 0;
}
