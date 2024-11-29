#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert an element x in the list
    void insert(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            head->next = head;  // Circular link to itself
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;  // Complete the circular link
        }
        cout << "Element " << x << " inserted." << endl;
    }

    // Remove an element x from the list
    void remove(int x) {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;

        // Special case if head is the element to be removed
        if (head->data == x) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                // Find the last node
                while (current->next != head) {
                    current = current->next;
                }
                current->next = head->next;
                delete head;
                head = current->next;
            }
            cout << "Element " << x << " removed." << endl;
            return;
        }

        // Traverse the list to find the element
        do {
            prev = current;
            current = current->next;
            if (current->data == x) {
                prev->next = current->next;
                delete current;
                cout << "Element " << x << " removed." << endl;
                return;
            }
        } while (current != head);

        cout << "Element " << x << " not found!" << endl;
    }

    // Search for an element x in the list and return its pointer
    Node* search(int x) {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return nullptr;
        }
        Node* current = head;
        do {
            if (current->data == x) {
                cout << "Element " << x << " found." << endl;
                return current;
            }
            current = current->next;
        } while (current != head);

        cout << "Element " << x << " not found!" << endl;
        return nullptr;
    }

    // Print the list (for testing purposes)
    void printList() {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.printList();  // Should print: 10 20 30

    cll.remove(20);
    cll.printList();  // Should print: 10 30

    cll.search(10);   // Should print: Element 10 found.
    cll.search(20);   // Should print: Element 20 not found.

    return 0;
}
