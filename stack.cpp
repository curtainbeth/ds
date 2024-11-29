#include <iostream>
#include <string>
#include <cmath> // For pow()
#include <stdexcept> // For runtime_error
using namespace std;

class Stack {
private:
    int* arr;      // Array to store stack elements
    int top;       // Index of the top element
    int capacity;  // Maximum capacity of the stack

public:
    // Constructor to initialize stack
    Stack(int size) {
        arr = new int[size];
        top = -1;
        capacity = size;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int x) {
        if (top == capacity - 1) {
            throw runtime_error("Stack overflow");
        }
        arr[++top] = x;
    }

    // Pop an element from the stack
    int pop() {
        if (top == -1) {
            throw runtime_error("Stack underflow");
        }
        return arr[top--];
    }

    // Peek the top element of the stack
    int peek() const {
        if (top == -1) {
            throw runtime_error("Stack is empty");
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }
};

int evaluatePostfix(const string& expr) {
    Stack stack(100); // Create a stack with size 100

    for (char c : expr) {
        if (isdigit(c)) {
            stack.push(c - '0'); // Convert char to int and push
        } else {
            int val2 = stack.pop();
            int val1 = stack.pop();

            switch (c) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
                case '^': stack.push(pow(val1, val2)); break;
                default: throw runtime_error("Invalid operator");
            }
        }
    }
    return stack.pop();
}
int evaluatePrefix(const string& expr) {
    Stack stack(100); // Create a stack with size 100

    for (int i = expr.length() - 1; i >= 0; i--) {
        char c = expr[i];

        if (isdigit(c)) {
            stack.push(c - '0'); // Convert char to int and push
        } else {
            int val1 = stack.pop();
            int val2 = stack.pop();

            switch (c) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
                case '^': stack.push(pow(val1, val2)); break;
                default: throw runtime_error("Invalid operator");
            }
        }
    }
    return stack.pop();
}
int main() {
    string postfix = "23*54*+9-"; // Example postfix expression
    string prefix = "-+*23*549";  // Example prefix expression

    try {
        cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;
        cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
