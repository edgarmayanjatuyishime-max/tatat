// BIT8122 - Data Structures & Algorithms
// Task 3: Queue from scratch (enqueue, dequeue, peek)
// Compile: g++ -std=c++17 3_queue.cpp -o 3_queue && ./3_queue

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Queue implemented from scratch using an array (no built-in queue class)
class Queue {
private:
    int data[MAX_SIZE];
    int frontIndex; // index of the first item
    int rearIndex;  // index of the last item

public:
    Queue() { frontIndex = 0; rearIndex = -1; }

    bool isEmpty() { return rearIndex < frontIndex; }   // O(1)
    bool isFull()  { return rearIndex == MAX_SIZE - 1; } // O(1)
    int  size()    { return rearIndex - frontIndex + 1; } // O(1)

    // enqueue: add an item at the rear -- Time complexity: O(1)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow: cannot enqueue " << value << endl;
            return;
        }
        data[++rearIndex] = value;
    }

    // dequeue: remove and return the item at the front -- Time complexity: O(1)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow: nothing to dequeue" << endl;
            return -1;
        }
        return data[frontIndex++];
    }

    // peek: look at the front item without removing it -- Time complexity: O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty: nothing to peek" << endl;
            return -1;
        }
        return data[frontIndex];
    }

    // print current state -- Time complexity: O(n)
    void print() {
        cout << "Queue (front -> rear): [ ";
        for (int i = frontIndex; i <= rearIndex; i++) cout << data[i] << " ";
        cout << "]" << endl;
    }
};

int main() {
    cout << "=== TASK 3: QUEUE ===\n" << endl;

    Queue q;

    cout << "enqueue(10)" << endl;  q.enqueue(10);  q.print();
    cout << "enqueue(20)" << endl;  q.enqueue(20);  q.print();
    cout << "enqueue(30)" << endl;  q.enqueue(30);  q.print();
    cout << "enqueue(40)" << endl;  q.enqueue(40);  q.print();

    cout << "\npeek()    -> " << q.peek() << endl;
    q.print();

    cout << "\ndequeue() -> " << q.dequeue() << endl;  q.print();
    cout << "dequeue() -> " << q.dequeue() << endl;    q.print();

    cout << "\nenqueue(50)" << endl;  q.enqueue(50);  q.print();

    cout << "\npeek()    -> " << q.peek() << endl;
    cout << "Current size: " << q.size() << endl;

    cout << "\ndequeue() -> " << q.dequeue() << endl;  q.print();
    cout << "dequeue() -> " << q.dequeue() << endl;    q.print();
    cout << "dequeue() -> " << q.dequeue() << endl;    q.print();
    cout << "dequeue() on empty queue:" << endl;       q.dequeue();

    return 0;
}
