#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    // Insert an element x into the BST
    Node* insert(Node* node, int x) {
        if (node == nullptr) {
            return new Node(x);
        }
        if (x < node->value) {
            node->left = insert(node->left, x);
        } else {
            node->right = insert(node->right, x);
        }
        return node;
    }

    void insert_element(int x) {
        root = insert(root, x);
    }

    // Search for an element x in the BST
    bool search(Node* node, int x) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == x) {
            return true;
        }
        if (x < node->value) {
            return search(node->left, x);
        }
        return search(node->right, x);
    }

    bool search_element(int x) {
        return search(root, x);
    }

    // Delete an element x from the BST
    Node* delete_node(Node* root, int x) {
        if (root == nullptr) {
            return root;
        }
        if (x < root->value) {
            root->left = delete_node(root->left, x);
        } else if (x > root->value) {
            root->right = delete_node(root->right, x);
        } else {
            // Node to be deleted found

            // Case 1: Node has no child (leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // Case 2: Node has one child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has two children
            Node* temp = find_minimum(root->right);
            root->value = temp->value;
            root->right = delete_node(root->right, temp->value);
        }
        return root;
    }

    void delete_element(int x) {
        root = delete_node(root, x);
    }

    // Find the node with the minimum value
    Node* find_minimum(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Preorder Traversal
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void preorder_traversal() {
        preorder(root);
        cout << endl;
    }

    // Inorder Traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    void inorder_traversal() {
        inorder(root);
        cout << endl;
    }

    // Postorder Traversal
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }

    void postorder_traversal() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the BST
    bst.insert_element(50);
    bst.insert_element(30);
    bst.insert_element(20);
    bst.insert_element(40);
    bst.insert_element(70);
    bst.insert_element(60);
    bst.insert_element(80);

    // Search for an element
    int searchValue = 40;
    if (bst.search_element(searchValue)) {
        cout << "Element " << searchValue << " found in the BST.\n";
    } else {
        cout << "Element " << searchValue << " not found in the BST.\n";
    }

    // Preorder Traversal
    cout << "Preorder Traversal: ";
    bst.preorder_traversal();

    // Inorder Traversal
    cout << "Inorder Traversal: ";
    bst.inorder_traversal();

    // Postorder Traversal
    cout << "Postorder Traversal: ";
    bst.postorder_traversal();

    // Delete an element
    bst.delete_element(20);
    cout << "After deleting 20, Inorder Traversal: ";
    bst.inorder_traversal();

    return 0;
}
