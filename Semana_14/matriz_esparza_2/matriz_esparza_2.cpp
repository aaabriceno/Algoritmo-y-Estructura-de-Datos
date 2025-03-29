#include <iostream>
using namespace std;

// Node

struct Node {
    int x, y, value;
    Node* next[2];  // [x, y]

    Node(int, int, int, Node*, Node*);
    bool findX(int, int, Node**&);
    bool findY(int, int, Node**&);
};

//*********************************************************************************************

// Sparse Matrix

class SparseMatrix {
    Node** xContainer, ** yContainer;
    int sizeX, sizeY;

public:
    SparseMatrix(int, int);
    bool findX(int, int, Node**&);
    bool findY(int, int, Node**&);
    void insert(int, int, int);
    void remove(int, int);
    void print();
};

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

int main()
{
    SparseMatrix M1(3, 3);
    M1.insert(5, 1, 1);
    M1.print();
    M1.insert(10, 2, 2);
    M1.print();
    M1.insert(15, 0, 0);
    M1.print();
}

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

// Node

Node::Node(int v, int xi, int yi, Node* next_x = nullptr, Node* next_y = nullptr) {
    value = v;
    x = xi;
    y = yi;
    next[0] = next_x;
    next[1] = next_y;
}

//*********************************************************************************************

// Sparse Matrix

SparseMatrix::SparseMatrix(int xSize, int ySize) {
    xContainer = new Node * [xSize];
    yContainer = new Node * [ySize];
    sizeX = xSize;
    sizeY = ySize;

    for (int i = 0; i < xSize; i++) {
        xContainer[i] = nullptr;
    }
    for (int i = 0; i < ySize; i++) {
        yContainer[i] = nullptr;
    }
}

bool SparseMatrix::findX(int x, int y, Node**& current) {
    for (current = &xContainer[x];
        *current != nullptr && (*current)->y < y;
        current = &(*current)->next[1]);

    if (*current == nullptr || (*current)->y != y)
        return 0;

    return 1;

}

bool SparseMatrix::findY(int x, int y, Node**& current) {
    for (current = &yContainer[y];
        *current != nullptr && (*current)->x < x;
        current = &(*current)->next[0]);

    if (*current == nullptr || (*current)->x != x)
        return 0;

    return 1;
}

void SparseMatrix::insert(int value, int x, int y) {
    Node** currentX, ** currentY;

    if (findX(x, y, currentX))
        return;

    findY(x, y, currentY);

    *currentX = *currentY = new Node(value, x, y, *currentY, *currentX);

    return;
}


void SparseMatrix::remove(int x, int y) {
    Node** currentX, ** currentY, * tmp;

    if (!findX(x, y, currentX))
        return;

    findY(x, y, currentY);

    tmp = *currentX;
    *currentX = (*currentX)->next[1];
    *currentY = (*currentY)->next[0];
    delete tmp;

    return;
}

void SparseMatrix::print() {
    cout << "Sparse Matrix" << endl;
    Node** currentY = yContainer, * current;

    for (int i = 0; i < sizeY; i++, currentY++) {
        current = *currentY;
        for (int j = 0; j < sizeX; j++) {
            if (current == nullptr || current->x != j)
                cout << "-->\t0\t";
            else {
                cout << "-->\t" << current->value << "\t";
                current == current->next[0];
            }
        }
        cout << endl;
    }
}