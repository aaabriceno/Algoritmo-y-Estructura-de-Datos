#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  // Include this header for std::sort

struct CBinTreeNode
{
    CBinTreeNode(int v)
    {
        value = v;
        nodes[0] = nodes[1] = 0;
    }
    CBinTreeNode* nodes[2];
    int value;
};

class CBinTree
{
public:
    CBinTree();
    void Print();
    bool Insert(int x);
    bool Remove(int x);
    CBinTreeNode* get_root();
private:
    bool Find(int x, CBinTreeNode**& p);
    CBinTreeNode** Rep(CBinTreeNode** p);
    void InOrder(CBinTreeNode* n);
    void Levels(CBinTreeNode* n);
    CBinTreeNode* root;
};

CBinTree::CBinTree()
{
    root = 0;
}

CBinTreeNode* CBinTree::get_root()
{
    return root;
}

bool CBinTree::Find(int x, CBinTreeNode**& p)
{
    for (p = &root; *p && (*p)->value != x;
        p = &((*p)->nodes[x > (*p)->value]));
    return *p != 0;
}

bool CBinTree::Insert(int x)
{
    CBinTreeNode** p;
    if (Find(x, p)) return 0;
    *p = new CBinTreeNode(x);
    return 1;
}

void CBinTree::InOrder(CBinTreeNode* n)
{
    if (!n) return;
    InOrder(n->nodes[0]);
    std::cout << n->value << " ";
    InOrder(n->nodes[1]);
}

void CBinTree::Levels(CBinTreeNode* n)
{
    if (!n) return;
    std::queue<std::pair<CBinTreeNode*, int>> q;
    q.push({ n,0 });
    int l = 0;
    while (!q.empty())
    {
        int last = l;
        std::pair<CBinTreeNode*, int> pp = q.front();
        CBinTreeNode* nn = pp.first;
        l = pp.second;
        if (nn->nodes[0])  q.push({ nn->nodes[0],l + 1 });
        if (nn->nodes[1])  q.push({ nn->nodes[1],l + 1 });
        if (last != l)    std::cout << "\n";
        std::cout << nn->value << "(" << l << ") ";
        q.pop();
    }
}
void CBinTree::Print()
{
    Levels(root);
    std::cout << "\n";
}

void print_half(CBinTree* r, int* ini, int* fin)
{
    if (ini >= fin) return;
    int* mid = ini + (fin - ini) / 2;
    r->Insert(*mid);
    print_half(r, ini, mid);
    print_half(r, mid + 1, fin);
}

void VecInsert(CBinTree* t, int* v, int size)
{
    std::sort(v, v + size);
    print_half(t, v, v + size);
}

int main()
{
    CBinTree t;
    int v[] = { 20,19,18,15,16,17,14,11,13,12,9,7,8,10,6,5,2,4,3,1 };
    VecInsert(&t, v, 20);
    t.Print();
    return 0;
}
