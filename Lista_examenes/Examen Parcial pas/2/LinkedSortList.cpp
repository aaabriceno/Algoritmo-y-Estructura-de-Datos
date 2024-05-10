
#include <iostream>

using namespace std;

template <class T>
struct CLess
{
    inline bool operator()(T a, T b)
    {
        return a < b;
    }
};

template <class T>
struct CGreater
{
    inline bool operator()(T a, T b)
    {
        return a > b;
    }
};

template <class T>
struct CNode
{
    CNode(T _v) { v = _v; next = 0; }
    T v;
    CNode<T>* next;
};

template <class T, class C>
class CList
{
public:
    CList();
    ~CList();
    bool Find(T x, CNode<T>**& p);
    bool Insert(T x);
    bool Remove(T x);
    void Print();
private:
    CNode<T>* m_head;
    C m_c;
};

template <class T, class C>
CList<T, C>::CList()
{
    m_head = 0;
}

template <class T, class C>
CList<T, C>::~CList()
{
    CNode<T>* a = m_head, * b;
    while (a)
    {
        b = a->next;
        delete a;
        a = b;
    }
}

template <class T, class C>
bool CList<T, C>::Find(T x, CNode<T>**& p)
{
    for (p = &m_head;
        *p && m_c((*p)->v, x); // (*p)->v < x
        p = &((*p)->next));
    return *p && (*p)->v == x;
}

template <class T, class C>
bool CList<T, C>::Insert(T x)
{
    CNode<T>** p;
    if (Find(x, p)) return 0;
    CNode<T>* n = new CNode<T>(x);
    n->next = *p;
    *p = n;
    return 1;
}

template <class T, class C>
bool CList<T, C>::Remove(T x)
{
    CNode<T>** p;
    if (!Find(x, p)) return 0;
    CNode<T>* t = *p;
    *p = (*p)->next;
    delete t;
    return 1;
}

template <class T, class C>
void CList<T, C>::Print()
{
    cout << " Head -> ";
    for (CNode<T>* a = m_head; a; a = a->next)
        cout << a->v << " -> ";
    cout << "Null" << endl;
}


////////////////////////////////////////////////////////////////////////////////

int main()
{
    int A[] = { 32 , 46 , 30 , 88 , 53 , 92 , 64 , 96 , 38 , 28 , 44 , 62 , 24 , 17 , 95 , 34 , 74 , 80 , 31 , 4 , 70 , 35 , 75 , 15 , 10 , 82 , 75 , 6 , 63 , 27 , 67 , 63 , 99 , 12 , 6 , 60 , 84 , 46 , 23 , 44 , 61 , 58 , 30 , 57 , 81 , 96 , 42 , 98 , 33 , 56 , 54 , 50 , 24 , 31 , 59 , 30 , 24 , 93 , 88 , 37 , 26 , 100 , 5 , 80 , 39 , 39 , 20 , 34 , 88 , 96 , 50 , 93 , 38 , 64 , 72 , 17 , 93 , 84 , 82 , 67 , 18 , 13 , 83 , 4 , 63 , 27 , 16 , 59 , 29 , 92 , 95 , 35 , 15 , 37 , 41 , 100 , 61 , 68 , 17 , 19 , 26 , 94 , 62 , 83 , 11 , 18 , 60 , 47 , 26 , 28 , 87 , 85 , 92 , 75 , 78 , 76 , 6 , 43 , 95 , 15 , 32 , 49 , 89 , 83 , 88 , 34 , 95 , 7 , 47 , 71 , 2 , 42 , 74 , 8 , 59 , 91 , 35 , 42 , 70 , 26 , 31 , 70 , 47 , 42 , 27 , 43 , 48 , 54 , 57 , 72 , 52 , 96 , 19 , 16 , 76 , 76 , 56 , 5 , 54 , 24 , 99 , 43 , 75 , 85 , 73 , 25 , 73 , 44 , 40 , 65 , 16 , 47 , 60 , 27 , 68 , 82 , 78 , 59 , 48 , 7 , 68 , 95 , 63 , 64 , 82 , 62 , 94 , 29 , 31 , 51 , 30 , 13 , 18 , 21 , 26 , 9 , 94 , 98 , 94 , 33 , 23 , 52 , 8 , 43 , 25 , 36 , 79 , 89 , 19 , 76 , 23 , 18 , 30 , 23 , 95 , 81 , 18 , 16 , 95 , 21 , 70 , 11 , 52 , 98 , 54 , 69 , 29 , 51 , 59 , 47 , 82 , 7 , 92 , 49 , 16 , 95 , 53 , 59 , 43 , 17 , 40 , 89 , 77 , 14 , 16 , 41 , 33 , 47 , 55 , 19 , 29 , 51 , 53 , 50 , 20 , 29 , 32 , 21 , 93 , 87 , 81 , 90 , 95 , 61 , 47 , 47 , 9 , 13 , 54 , 73 , 67 , 7 , 80 , 23 , 76 , 86 , 62 , 81 , 93 , 78 , 3 , 52 , 47 , 6 , 12 , 86 , 90 , 63 , 41 , 48 , 13 , 56 , 40 , 4 , 53 , 53 , 19 , 28 , 63 , 39 , 21 , 97 , 51 , 4 , 53 , 78 , 1 , 96 , 28 , 30 , 100 , 76 , 22 , 89 , 67 , 6 , 41 , 93 , 53 , 27 , 32 , 19 , 27 , 59 , 81 , 84 , 82 , 34 , 22 , 44 , 33 , 46 , 3 , 57 , 76 , 18 , 57 , 91 , 24 , 73 , 100 , 76 , 28 , 68 , 34 , 25 , 67 , 30 , 56 , 80 , 66 , 75 , 85 , 77 , 12 , 99 , 88 , 42 , 2 , 41 , 11 , 20 , 34 , 32 , 94 , 53 , 27 , 45 , 42 , 53 , 43 , 16 , 89 , 85 , 45 , 57 , 45 , 59 , 84 , 63 , 15 , 4 , 62 , 33 , 97 , 76 , 71 , 50 , 20 , 8 , 93 , 2 , 1 , 75 , 19 , 54 , 96 , 40 , 10 , 72 , 29 , 89 , 26 , 37 , 73 , 95 , 44 , 75 , 45 , 51 , 23 , 1 , 43 , 7 , 68 , 22 , 97 , 59 , 72 , 22 , 34 , 96 , 88 , 95 , 53 , 99 , 44 , 26 , 47 , 27 , 97 , 16 , 53 , 78 , 98 , 37 , 98 , 27 , 34 , 70 , 24 , 10 , 66 , 37 , 70 , 97 , 27 , 88 , 31 , 88 , 97 , 17 , 23 , 87 , 32 , 41 , 80 , 45 , 14 , 17 , 67 , 88 , 4 , 15 , 90 , 19 , 22 , 57 , 79 , 17 , 23 , 44 , 40 , 12 , 85 , 70 , 39 , 100 , 99 , 52 , 17 , 60 , 12 , 31 , 19 , 68 , 15 , 79 , 25 , 51 , 37 , 100 , 57 , 66 , 32 , 7 , 21 , 44 };

    CList<int, CLess<int> > l; // Esta declaración se podría modificar de acuerdo a su implementación
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
        l.Insert(A[i]);
    l.Print();
}