#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node *root;

    Node *getMinValueNode(Node *node) {
        Node *current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    Node *insert(Node *node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    Node *deleteNode(Node *node, int key) {
        if (!node) return nullptr;

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        }
        else {
            if (!node->left) {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = getMinValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void bfs(Node *node) {
        if (!node) return;
        queue<Node *> q;
        q.push(node);
        while (!q.empty()) {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

public:
    BST() { root = nullptr; }
    
    void insert(int key) {
        root = insert(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void bfs() {
        if (!root) {
            cout << "Tree is empty!" << endl;
            return;
        }
        bfs(root);
        cout << endl;
    }

    bool search(int key) {
        Node *current = root;
        while (current) {
            if (current->data == key) return true;
            if (current->data > key) current = current->left;
            else current = current->right;
        }
        return false;
    }

    int findMin() {
        if (!root) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        Node *current = root;
        while (current->left) {
            current = current->left;
        }
        return current->data;
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n1. Insert node\n"
             << "2. Delete node\n"
             << "3. Find minimum\n"
             << "4. Search value\n"
             << "5. Display BFS\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteNode(value);
                break;
            case 3:
                value = tree.findMin();
                if (value != -1)
                    cout << "Minimum value: " << value << endl;
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << "Value found!" << endl;
                else
                    cout << "Value not found!" << endl;
                break;
            case 5:
                cout << "BFS traversal: ";
                tree.bfs();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}

// {
//     1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 1
// Enter value to insert: 34

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 5
// BFS traversal: 34 

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 1
// Enter value to insert: 23

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 1
// Enter value to insert: 34

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 1
// Enter value to insert: 56

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 1
// Enter value to insert: 76

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 1
// Enter value to insert: 45

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 1
// Enter value to insert: 65

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 1
// Enter value to insert: 87

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 1
// Enter value to insert: 99

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 5
// BFS traversal: 34 23 34 56 45 76 65 87 99 

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 3
// Minimum value: 23

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 2
// Enter value to delete: 23

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 3
// Minimum value: 34

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 4
// Enter value to search: 34
// Value found!

// 1. Insert node
// 2. Delete node
// 3. Find minimum
// 4. Search value
// 5. Display BFS
// 6. Exit
// Enter your choice: 6
// Exiting...
// }