// AVL.cpp
#include <stack>
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

struct nodo {
    int altura;
    int val;
    nodo* nodes[2] = { nullptr, nullptr };
    nodo(int v, int h = 1) : val(v), altura(h) {}
};

struct arbol {
    nodo* root = nullptr;
    bool random = false;

    bool find(int v, nodo**& p, stack<nodo**>& stack) {
        p = &root;
        while ((*p) && (*p)->val != v) {
            stack.push(p);
            p = &((*p)->nodes[v > (*p)->val]);
        }
        return *p && (*p)->val == v;
    }

    void rotateLeft(nodo**& q) {
        nodo* temp = (*q);
        (*q) = temp->nodes[1];
        temp->nodes[1] = (*q)->nodes[0];
        (*q)->nodes[0] = temp;
        temp->altura = max(getAltura(temp->nodes[0]), getAltura(temp->nodes[1])) + 1;
        (*q)->altura = max(getAltura((*q)->nodes[0]), getAltura((*q)->nodes[1])) + 1;
    }

    void rotateRight(nodo**& q) {
        nodo* temp = (*q);
        (*q) = temp->nodes[0];
        temp->nodes[0] = (*q)->nodes[1];
        (*q)->nodes[1] = temp;
        temp->altura = max(getAltura(temp->nodes[0]), getAltura(temp->nodes[1])) + 1;
        (*q)->altura = max(getAltura((*q)->nodes[0]), getAltura((*q)->nodes[1])) + 1;
    }

    int getAltura(nodo* n) {
        return n ? n->altura : 0;
    }

    void balanced(stack<nodo**>& pila) {
        while (!pila.empty()) {
            nodo** q = pila.top();
            pila.pop();

            int leftHeight = getAltura((*q)->nodes[0]);
            int rightHeight = getAltura((*q)->nodes[1]);
            (*q)->altura = max(leftHeight, rightHeight) + 1;

            int balance = rightHeight - leftHeight;

            if (balance == 2) {
                if (getAltura((*q)->nodes[1]->nodes[1]) >= getAltura((*q)->nodes[1]->nodes[0])) {
                    rotateLeft(q);
                }
                else {
                    nodo** temp = &((*q)->nodes[1]);
                    rotateRight(temp);
                    rotateLeft(q);
                }
            }
            else if (balance == -2) {
                if (getAltura((*q)->nodes[0]->nodes[0]) >= getAltura((*q)->nodes[0]->nodes[1])) {
                    rotateRight(q);
                }
                else {
                    nodo** temp = &((*q)->nodes[0]);
                    rotateLeft(temp);
                    rotateRight(q);
                }
            }
        }
    }

    void push(int v) {
        stack<nodo**> pila;
        nodo** p;
        if (find(v, p, pila)) return;
        (*p) = new nodo(v);
        balanced(pila);
    }

    nodo** major(int v, nodo** q) {
        random = !random;
        q = &((*q)->nodes[!random]);
        while ((*q)->nodes[random])
            q = &((*q)->nodes[random]);
        return q;
    }

    void remove(int v) {
        stack<nodo**> stack;
        nodo** p;
        if (!find(v, p, stack)) return;
        if ((*p)->nodes[0] && (*p)->nodes[1]) {
            nodo** q = major(v, p);
            (*p)->val = (*q)->val;
            p = q;
        }
        nodo* tmp = (*p);
        (*p) = (*p)->nodes[(*p)->nodes[0] == nullptr];
        delete tmp;
        balanced(stack);
    }

    void InOrder(nodo* n) {
        if (!n) return;
        InOrder(n->nodes[0]);
        cout << n->val << " (" << n->altura << ") ";
        InOrder(n->nodes[1]);
    }

    void Print() {
        InOrder(root);
        cout << endl;
    }
};

int main() {
    arbol t;
    t.push(50);
    t.push(30);
    t.push(20);
    t.push(80);
    t.push(55);
    t.push(11);
    t.push(35);
    t.push(5);
    t.push(14);
    t.push(60);

    t.Print();

    t.remove(20);
    t.Print();
}