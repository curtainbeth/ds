#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

// DoublyLinkedList class for managing the list
class DoublyLinkedList {
private:
    Node* head;  // Pointer to the head of the list

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert an element at the beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {  // If the list is empty
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert an element at the end
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {  // If the list is empty
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Remove an element from the beginning
    void removeFromBeginning() {
        if (head == nullptr) {  // If the list is empty
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (head->next != nullptr) {
            head = head->next;
            head->prev = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    // Remove an element from the end
    void removeFromEnd() {
        if (head == nullptr) {  // If the list is empty
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (head->next == nullptr) {  // Only one element
            head = nullptr;
        } else {
            while (temp->next != nullptr) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;
        }
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to test the doubly linked list
int main() {
    DoublyLinkedList list;

    // Inserting elements at the beginning
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    cout << "List after inserting at beginning: ";
    list.display();

    // Inserting elements at the end
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "List after inserting at end: ";
    list.display();

    // Removing elements from the beginning
    list.removeFromBeginning();
    cout << "List after removing from beginning: ";
    list.display();

    // Removing elements from the end
    list.removeFromEnd();
    cout << "List after removing from end: ";
    list.display();

    return 0;
}
