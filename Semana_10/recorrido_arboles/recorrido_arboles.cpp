#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int valor;
    Node* nodes[2];
    Node(int v) {
        valor = v;
        nodes[0] = nodes[1] = nullptr;
    }
};

// Recorrido inorden utilizando un stack
void inorder(Node* root) {
    stack<Node*> s;
    Node* current = root;
    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->nodes[0];
        }
        current = s.top();
        s.pop();
        cout << current->valor << " ";
        current = current->nodes[1];
    }
}

// Recorrido preorden utilizando un stack
void preorder(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->valor << " ";
        if (current->nodes[1]) s.push(current->nodes[1]);
        if (current->nodes[0]) s.push(current->nodes[0]);
    }
}

// Recorrido postorden utilizando un stack
void postorder(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);
        if (current->nodes[0]) s1.push(current->nodes[0]);
        if (current->nodes[1]) s1.push(current->nodes[1]);
    }
    while (!s2.empty()) {
        Node* current = s2.top();
        s2.pop();
        cout << current->valor << " ";
    }
}

int main() {
    Node* root = new Node(1);
    root->nodes[0] = new Node(2);
    root->nodes[1] = new Node(3);
    root->nodes[0]->nodes[0] = new Node(4);
    root->nodes[0]->nodes[1] = new Node(5);
    root->nodes[1]->nodes[0] = new Node(6);
    root->nodes[1]->nodes[1] = new Node(7);

    cout << "Inorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;

    return 0;
}