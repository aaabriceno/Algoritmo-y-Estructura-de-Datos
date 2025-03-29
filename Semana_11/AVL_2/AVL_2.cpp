#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <iterator> // For std::prev
#include <math.h>

using namespace std;

//Node

struct Node {
    int value;
    int height;
    Node* nodes[2];

    Node(int);
};

//*********************************************************************************************

//AVLTree

class AVLTree {
private:
    Node* root;

    int getBalance(Node*);
    int updateHeight(Node*);
    void balanceTree(Node**);   // Only when getBalance() is 2 or -2
    Node** getSuccessor(Node**, stack<Node**>&);
    void preorder(Node*);
    void bfs(list<Node*>*&);    // Breadth First Search
public:
    AVLTree();
    bool search(int, Node**&, stack<Node**>&);
    bool insert(int);
    bool remove(int);
    void print();
    void printPreorder();
};

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

int main() {
    cout << "************ test1 ************" << endl;
    cout << "Insert:" << endl;
    AVLTree test1;
    for (int i = 0; i < 20; i += 3) {
        test1.insert(i);
        test1.print();
    }

    //test1.print();

    //test1.printPreorder();

    cout << "Remove: " << 9 << endl;
    test1.remove(9);
    test1.print();
    cout << "Remove: " << 12 << endl;
    test1.remove(12);
    test1.print();
    cout << "Remove: " << 15 << endl;
    test1.remove(15);
    test1.print();
    cout << "Remove: " << 3 << endl;
    test1.remove(3);
    test1.print();
    cout << "Remove: " << 6 << endl;
    test1.remove(6);
    test1.print();
    cout << "Remove: " << 18 << endl;
    test1.remove(18);
    test1.print();
    cout << "Remove: " << 0 << endl;
    test1.remove(0);
    test1.print();

}

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

//Node

Node::Node(int v) {
    value = v;
    height = 1;
    nodes[0] = nodes[1] = nullptr;
}

//*********************************************************************************************

//AVLTree

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::getBalance(Node* parent) {
    int right = (parent->nodes[1] == nullptr ? 0 : parent->nodes[1]->height);
    int left = (parent->nodes[0] == nullptr ? 0 : parent->nodes[0]->height);
    return right - left;
}

int AVLTree::updateHeight(Node* parent) {
    int right = (parent->nodes[1] == nullptr ? 0 : parent->nodes[1]->height);
    int left = (parent->nodes[0] == nullptr ? 0 : parent->nodes[0]->height);
    return parent->height = (right > left ? right : left) + 1;
}

void AVLTree::balanceTree(Node** parent) {
    bool isRoot = 0;
    if (*parent == root)
        isRoot = 1;

    bool side1 = getBalance(*parent) > 0 ? 1 : 0;   // 1 if balance is positive (right), 2 if negative (left)
    Node** son = &(*parent)->nodes[side1];
    bool side2 = getBalance(*son) > 0 ? 1 : 0;
    if (side1 == side2) {
        Node* tmp1 = *parent;
        Node* tmp2 = (*son)->nodes[!side1]; // to save son's subtree
        *parent = *son;
        *son = tmp2;
        (*parent)->nodes[!side1] = tmp1;
    }
    else {
        Node* tmp1 = *parent;
        *parent = (*son)->nodes[side2];
        Node* tmp2 = (*parent)->nodes[side2];
        (*parent)->nodes[side2] = tmp1;
        Node* tmp3 = tmp1->nodes[side1];
        tmp1->nodes[side1] = tmp2;
        tmp1 = (*parent)->nodes[side1];
        (*parent)->nodes[side1] = tmp3;
        tmp3->nodes[side2] = tmp1;
    }
    updateHeight((*parent)->nodes[0]);
    updateHeight((*parent)->nodes[1]);
    updateHeight(*parent);
    if (isRoot)
        root = *parent;
}

Node** AVLTree::getSuccessor(Node** successor, stack<Node**>& path) {
    if ((*successor)->nodes[1] == nullptr)
        return nullptr; //&(*successor)->nodes[0]

    successor = &(*successor)->nodes[1];
    path.push(successor);
    while ((*successor)->nodes[0]) {
        successor = &(*successor)->nodes[0];
        path.push(successor);
    }
    return successor;
}

void AVLTree::preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->value << " ";
    preorder(root->nodes[0]);
    preorder(root->nodes[1]);
}

void AVLTree::bfs(list<Node*>*& lvlNodes) {
    list<Node*>* newList = new list<Node*>;

    for (Node* current; !lvlNodes->empty(); lvlNodes->pop_front()) {
        current = lvlNodes->front();

        if (current) {
            newList->push_back(current->nodes[0]);
            newList->push_back(current->nodes[1]);
        }
        else {
            newList->push_back(nullptr);
            newList->push_back(nullptr);
        }

    }
    delete lvlNodes;
    lvlNodes = newList;

}

bool AVLTree::search(int value, Node**& current, stack<Node**>& path) {
    for (current = &root;
        *current && (*current)->value != value;
        path.push(current), current = &(*current)->nodes[value > (*current)->value]);
    return *current;
}

bool AVLTree::insert(int value) {
    if (root == nullptr) {
        root = new Node(value);
        return 1;
    }

    Node** current = nullptr;
    stack<Node**> path;
    if (search(value, current, path))
        return 0;

    *current = new Node(value);

    for (; !path.empty(); path.pop()) {
        updateHeight(*path.top());

        if (getBalance(*path.top()) == 2 || getBalance(*path.top()) == -2)
            balanceTree(path.top());
    }

    return 1;
}

bool AVLTree::remove(int value) {
    if (!root) {
        return 0;
    }
    if (root->nodes[0] == nullptr && root->nodes[1] == nullptr) {
        delete root;
        root = nullptr;
        return 1;
    }
    Node** current = nullptr;
    stack<Node**> path;
    if (!search(value, current, path)) {
        return 0;
    }
    Node** tmp = getSuccessor(current, path);

    if (!tmp) {
        Node* tmp1 = *current;
        if (root == *current) {
            root = root->nodes[0];
        }
        else
            *current = (*current)->nodes[0];
        delete tmp1;
    }

    else if (!*tmp) {
        Node* tmp1 = *current;
        *current = (*current)->nodes[0];
        delete tmp1;
        path.pop();
    }
    else {
        (*current)->value = (*tmp)->value;
        Node* tmp1 = *tmp;
        *tmp = (*tmp)->nodes[1];
        delete tmp1;
        path.pop();
    }

    for (; !path.empty(); path.pop()) {
        if (getBalance(*path.top()) == 2 || getBalance(*path.top()) == -2)
            balanceTree(path.top());
        else
            updateHeight(*path.top());
    }

    if (getBalance(*current) == 2 || getBalance(*current) == -2)
        balanceTree(current);
    else
        updateHeight(*current);

    return 1;
}

void AVLTree::print() {
    if (root == nullptr) {
        cout << "Empty Tree" << endl;
        return;
    }

    list<Node*>* lvlNodes = new list<Node*>;
    lvlNodes->push_back(root);
    cout << "-print()-" << endl;
    int digits = 3;

    for (int height = lvlNodes->front()->height, margin, space; height > 0; height--) {

        margin = (pow(2, height - 1) - 1) * digits;
        for (int i = 0; i < margin; i++) {
            cout << " ";
        }

        space = (pow(2, height) - 1) * 3;
        for (list<Node*>::iterator place = lvlNodes->begin();

            place != lvlNodes->end();
            place++) {
            string currentSpace = to_string(*place ? (*place)->value : 0);
            int offSpace = digits - currentSpace.length();
            for (; offSpace > 0; cout << " ", offSpace--);

            if (*place)
                cout << (*place)->value;
            else
                cout << "N";

            if (place != prev(lvlNodes->end())) {   // To avoid unnecessary spaces
                for (int j = 0; j < space; j++) {
                    cout << " ";
                }
            }
        }

        cout << endl;

        if (height != 1)
            bfs(lvlNodes);  // updates node queue

    }

    cout << endl;
}

void AVLTree::printPreorder() {
    cout << "-printPreoder()-" << endl;
    preorder(root);
    cout << endl;
}