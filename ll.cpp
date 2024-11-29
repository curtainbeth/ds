#include <iostream>
using namespace std;

// Definition of Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {} // Constructor to initialize node
};

// Singly Linked List as an ADT
class SinglyLinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    // Constructor
    SinglyLinkedList() : head(nullptr) {}

    // Insert an element at the beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // Insert an element at the ith position
    void insertAtPosition(int x, int pos) {
        if (pos < 0) {
            cout << "Position cannot be negative!" << endl;
            return;
        }

        Node* newNode = new Node(x);

        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; i < pos - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Position out of bounds!" << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Remove an element from the beginning
    void removeFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Remove an element from the ith position
    void removeFromPosition(int pos) {
        if (pos < 0) {
            cout << "Position cannot be negative!" << endl;
            return;
        }

        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos == 0) {
            removeFromBeginning();
            return;
        }

        Node* current = head;
        for (int i = 0; i < pos - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Search for an element and return its pointer
    Node* search(int x) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == x) {
                return current; // Return pointer to the node
            }
            current = current->next;
        }
        return nullptr; // Element not found
    }

    // Print the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    // Insert at the beginning
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);

    // Insert at position
    list.insertAtPosition(30, 1);
    list.insertAtPosition(40, 0);
    list.insertAtPosition(50, 4);

    // Print the list
    cout << "List after insertions: ";
    list.printList();

    // Remove from the beginning
    list.removeFromBeginning();
    cout << "List after removing from beginning: ";
    list.printList();

    // Remove from position
    list.removeFromPosition(2);
    cout << "List after removing from position 2: ";
    list.printList();

    // Search for an element
    int x = 30;
    Node* result = list.search(x);
    if (result != nullptr) {
        cout << "Element " << x << " found at address: " << result << endl;
    } else {
        cout << "Element " << x << " not found!" << endl;
    }

    return 0;
}
