#include <bits/stdc++.h>
using namespace std;

// Class implementing Queue using Arrays
class ArrayQueue {
private:
    int* arr;       // Array to store queue elements
    int start, end; // Indices for start and end of the queue
    int currSize, maxSize; // Current size and max size of the queue

public:
    // Constructor with default size of 10
    ArrayQueue(int size = 10) {
        maxSize = size;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    // Destructor to free memory
    ~ArrayQueue() {
        delete[] arr;
    }

    // Method to push an element into the queue
    void push(int x) {
        // Check if the queue is full
        if (currSize == maxSize) {
            cout << "Queue is full\n";
            return;
        }
        
        // If the queue is empty, initialize start and end
        if (end == -1) {
            start = 0;
            end = 0;
        } 
        else {
            // Circular increment of end
            end = (end + 1) % maxSize;
        }
            
        arr[end] = x;
        currSize++;
    }

    // Method to pop an element from the queue
    int pop() {
        // Check if the queue is empty
        if (start == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        int popped = arr[start];
        
        // If the queue has only one element, reset start and end
        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            // Circular increment of start
            start = (start + 1) % maxSize;
        }
        
        currSize--;
        return popped;
    }

    // Method to get the front element of the queue
    int peek() {
        // Check if the queue is empty
        if (start == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[start];
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return (currSize == 0);
    }
};

int main() {
    ArrayQueue queue; // Create a queue with default size 10

    // Simple operations to test the queue
    queue.push(5); // Add 5 to the queue
    queue.push(10); // Add 10 to the queue
    queue.push(15); // Add 15 to the queue

    // Peek the front element
    cout << "Front element: " << queue.peek() << endl;

    // Pop and display the front element
    cout << "Popped element: " << queue.pop() << endl;

    // Check if the queue is empty
    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    // Pop remaining elements
    cout << "Popped element: " << queue.pop() << endl;
    cout << "Popped element: " << queue.pop() << endl;

    // Check again if the queue is empty
    cout << "Is the queue empty now? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
