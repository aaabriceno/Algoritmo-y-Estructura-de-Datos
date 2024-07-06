#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CAVLNode
{
    CAVLNode(int _v)
    {
        value = _v; nodes[0] = nodes[1] = 0;
    }
    int value;
    CAVLNode* nodes[2];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////

class CAVLTree
{
public:
    CAVLTree();
    ~CAVLTree();
    bool Insert(int x);
    bool Remove(int x);
    void Print();
    int MaxNodeHeight(CAVLNode* n);
    int MaxHeight();
    CAVLNode* m_root;

private:
    bool Find(int x, CAVLNode**& p);
    CAVLNode** Rep(CAVLNode** p);
    void InOrder(CAVLNode* n);
    
};

CAVLTree::CAVLTree()
{
    m_root = 0;
}

CAVLTree::~CAVLTree()
{}

bool CAVLTree::Find(int x, CAVLNode**& p)
{
    for (p = &m_root; *p && (*p)->value != x; p = &((*p)->nodes[(*p)->value < x]));
    return *p && (*p)->value == x;
}

bool CAVLTree::Insert(int x)
{
    CAVLNode** p;
    if (Find(x, p)) return 0;
    *p = new CAVLNode(x);
    return 0;
}
bool CAVLTree::Remove(int x)
{
    CAVLNode** p;
    if (!Find(x, p)) return 0;
    if ((*p)->nodes[0] && (*p)->nodes[1])
    {
        CAVLNode** q = Rep(p);
        (*p)->value = (*q)->value;
        p = q;
    }
    CAVLNode* t = *p;
    *p = (*p)->nodes[!(*p)->nodes[0]];
    delete t;
    return 1;
}

CAVLNode** CAVLTree::Rep(CAVLNode** p)
{
    bool b = rand() % 2;
    for (p = &((*p)->nodes[b]); (*p)->nodes[!b]; p = &((*p)->nodes[!b]));
    return p;
}

void CAVLTree::InOrder(CAVLNode* n)
{
    if (!n) return;
    InOrder(n->nodes[0]);
    cout << n->value << " ";
    InOrder(n->nodes[1]);
}

void CAVLTree::Print()
{
    InOrder(m_root);
    cout << endl;
}

//======================================================
int CAVLTree::MaxNodeHeight(CAVLNode* n)
{
    if (!n) return -1; // Si el nodo es nulo, la altura es -1
    int leftHeight = MaxNodeHeight(n->nodes[0]);
    int rightHeight = MaxNodeHeight(n->nodes[1]);
    return 1 + max(leftHeight, rightHeight);
}

// Función para calcular la altura máxima de un subárbol
void MaxHeightThread(CAVLNode* n, int& height, CAVLTree* tree)
{
    height = tree->MaxNodeHeight(n);
}

// Calcula la altura máxima del árbol utilizando 4 hilos
int CAVLTree::MaxHeight()
{
    if (!m_root) return 0; // Si el árbol está vacío, la altura es 0

    int heights[4] = { 0, 0, 0, 0 };
    thread threads[4];

    // Crear 4 hilos para calcular la altura de los subárboles
    threads[0] = thread(MaxHeightThread, m_root->nodes[0], ref(heights[0]), this);
    threads[1] = thread(MaxHeightThread, m_root->nodes[1], ref(heights[1]), this);
    threads[2] = thread(MaxHeightThread, m_root->nodes[0] ? m_root->nodes[0]->nodes[0] : nullptr, ref(heights[2]), this);
    threads[3] = thread(MaxHeightThread, m_root->nodes[1] ? m_root->nodes[1]->nodes[1] : nullptr, ref(heights[3]), this);

    // Esperar a que los hilos terminen
    for (int i = 0; i < 4; ++i)
    {
        threads[i].join();
    }

    // Calcular la altura máxima
    int maxHeight = 1 + max({ heights[0], heights[1], heights[2], heights[3] });
    return maxHeight;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int v[150] = { 239, 389, 128, 46, 235, 65, 423, 417, 121, 451, 396, 
    331, 158, 100, 95, 353, 470, 207, 453, 156, 98, 160, 373, 44, 313, 
    284, 152, 131, 236, 340, 369, 408, 411, 174, 141, 69, 96, 451, 259, 
    28, 234, 158, 168, 100, 379, 1, 487, 307, 182, 486, 385, 221, 30, 305, 
    41, 115, 415, 227, 166, 85, 220, 446, 127, 66, 316, 298, 144, 446, 65, 425, 
    241, 160, 215, 346, 212, 341, 44, 452, 226, 168, 132, 230, 448, 173, 174, 483, 
    59, 237, 436, 28, 472, 2, 142, 194, 203, 355, 410, 78, 418, 489, 220, 258, 19,
    411, 373, 216, 311, 31, 411, 357, 334, 205, 118, 471, 252, 291, 389, 40, 389, 
    437, 36, 134, 475, 401, 448, 133, 30, 251, 456, 220, 417, 302, 256, 34, 120, 
    115, 318, 459, 110, 251, 392, 360, 261, 389, 450, 122, 308, 188, 212, 37 };

    CAVLTree t;
    for (int i = 0; i < 150; i++)
        t.Insert(v[i]);
    t.Print();

    cout << "Altura del nodo con valor 239: " << t.MaxNodeHeight(t.m_root) << endl;
    cout << "Altura del nodo con valor 389: " << t.MaxNodeHeight(t.m_root->nodes[1]) << endl;

    cout << "Max Height is: " << t.MaxHeight() << endl;
}