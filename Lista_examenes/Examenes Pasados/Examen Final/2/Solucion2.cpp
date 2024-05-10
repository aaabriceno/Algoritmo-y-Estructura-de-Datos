#include <iostream>
#include <list>
using namespace std;

struct CSNode{
    CSNode(int _x, int _y, int _v);
    int x, y;
    int value;
    CSNode* next=nullptr;
};

CSNode::CSNode(int _x, int _y, int _v)
{
    x = _x; y = _y; value = _v;
}

class CSparseMatrix{
public:
    list<CSNode*> matra;
    CSNode** X;
    int operator()(int x, int y);
    CSparseMatrix(int xdim = 0, int ydim = 0); 
    ~CSparseMatrix();
    bool Set(int x, int y, int value);
    int Get(int x, int y);
    bool find(int x, int y, CSNode**&p);
    void Print();
    int XDim, YDim;
    list<CSNode> smatrix;
};
bool CSparseMatrix::find(int x, int y, CSNode**& p) {
    if ((*p)) {
        for (auto it = matra.begin();it!=matra.end(); it++) {
            CSNode** q = &(*it);
            if (*q) {
                for (int _y = 0, _x = (*q)->x; *q && _y <= y && _x == x; _y++, q = &((*q)->next)) {
                    if ((*q)->y == y) {
                        p = q;
                        return 1;
                    }
                    else if ((*q)->y > y) {
                        return 0;
                    }
                    else if ((*q)->next == nullptr) {
                        p = &(*q)->next;
                        return 0;
                    }
                    p = q;
                }
            }
        }
    }
    return 0; 
}
CSparseMatrix::CSparseMatrix(int _xdim, int _ydim){
    XDim = _xdim; YDim = _ydim;
    X = new CSNode * [XDim];
    for (int i = 0; i < XDim; i++) {
        X[i] = nullptr;
        matra.push_back(X[i]);
    }
}

CSparseMatrix::~CSparseMatrix()
{
}

bool CSparseMatrix::Set(int x, int y, int value) {
    CSNode** p=&X[x];
    if(find(x,y,p)){
        //for(;(*p)->y;p=&((*p)->next))
        (*p)->value = value;
    }
    else {
        if (!(*p)) {
            (*p) = new CSNode(x, y, value);
            (*p)->next = nullptr;
            //X[x] = *p;
            int a = 0;
            if (X[x] == *p) {
                for (auto it = matra.begin(); it != matra.end() && a <= x; ++it, a++) {
                    if (a == x) {
                        (*it) = *p;
                    }
                }
            }
        }
        else {
            CSNode* nuevo = new CSNode(x,y,value);
            CSNode** temp = &X[x];
            for (; (*temp)->y <= y; temp = &((*temp)->next));
            CSNode** sigui = &((*temp)->next);
            (*temp)->next = nuevo;
            nuevo->next = *sigui;
        }
    }
    return 0;
}

int CSparseMatrix::Get(int x, int y){
    CSNode** p = &X[x];
    if (find(x, y, p)) {
        return (*p)->value;
    }
    return 0;
}


int CSparseMatrix::operator()(int x, int y){
    return Get(x, y);
}

void CSparseMatrix::Print(){
    cout << "\n--------------------\n";
    for (int f = 0; f < XDim; f++) {
        for (int c = 0; c < YDim; c++) {
            cout << Get(f, c) << "  ";
        } cout << endl;
    }
    cout << endl;
}
struct Objeto {
    CSparseMatrix* p;
};
int main(void)
{
    CSparseMatrix m(5, 5);

    m.Set(0, 0, 3);
    m.Set(2, 1, 5);
    m.Set(1, 2, 1);
    m.Set(4, 3, 8);
    m.Set(0, 4, 6);
    //----------------------
    m.Set(1, 2, 7);
    m.Set(4, 3, 0);
    m.Set(0, 4, 0);
    m.Print();

    
        m(0,0) = 0;
        m(4,0) = 1;
        m(4,4) = 2;
        m(0,4) = 3;
        m1.Print();
        cout << "\n 0,0 => " << m(0, 0);
        cout << "\n 3,5 => " << m(4, 1);
        cout << "\n 7,3 => " << m(1, 2);
    

    return 0;
}


