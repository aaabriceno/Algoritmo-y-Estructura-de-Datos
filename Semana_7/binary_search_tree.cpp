/*Arbol binario de búsqueda con doble puntero **p, sin repeticion y ordenado ascendentemente*/

#include <iostream>
using namespace std;

struct CbintreeNode
{
    CbintreeNode(int d)
    {
        dato = d; 
        nodes[0]=nodes[1] = 0;
    }
    int dato;
    CbintreeNode* nodes[2];
};

class Cbintree{
    public:
        //CbintreeNode **p;
        Cbintree();
        ~Cbintree(); 
        bool insertar(int x);
        bool remover(int x);
        void print();       
    private:
        bool buscar(int x, CbintreeNode** p);
        void imprimirEnOrden(CbintreeNode* nodo);
        CbintreeNode** reemplazo(CbintreeNode** q);
        CbintreeNode* root;
        bool bb;
};

Cbintree::Cbintree()
{
    root = 0;
    bb = 0;
}

Cbintree::~Cbintree(){
    //
};

bool Cbintree::buscar(int x, CbintreeNode** p){
    p = &root;
    while( (*p) && (*p)-> dato != x ){                             
        p = &((*p)->nodes[x > (*p)-> dato]);    //[(*p)->dato < x];
    }
    return *p && (*p) -> dato == x;             //return *p != 0;
}
/*
bool Cbintree::insertar(int x){
    CbintreeNode** p = &root;
    while (*p) {
        if (x < (*p)->dato) {
            p = &((*p)->nodes[0]); // Moverse al subárbol izquierdo si x es menor
        } else if (x > (*p)->dato) {
            p = &((*p)->nodes[1]); // Moverse al subárbol derecho si x es mayor
        } else {
            return false; // No se permiten elementos duplicados
        }
    }
    *p = new CbintreeNode(x); // Insertar el nuevo nodo en la posición adecuada
    return true;
}
*/
bool Cbintree::insertar(int x){
    CbintreeNode** p = &root;
    if( buscar(x,p) ) return 0;
    *p = new CbintreeNode(x);
    return 1;
}
CbintreeNode** Cbintree::reemplazo(CbintreeNode** p){
    CbintreeNode** q;
    int b = bb;
    q = &((*p) -> nodes[b]);
    while ((*q)-> nodes[!b] != 0)
        q = &((*q)->nodes[!b]);
    bb = !bb;
    return q;
}
bool Cbintree::remover(int x){
    CbintreeNode** p=&root;
    if(!buscar(x,p)) return 0;

     //caso 2: dos hijos
    if ( (*p)->nodes[0] && (*p)->nodes[1] ){           
        CbintreeNode** q = reemplazo(p);
        (*p) -> dato = (*q) -> dato;
        p = q;
    }

    //caso 1 y 0 : un hijo (izq o der) o 0 hijos
    CbintreeNode* t = *p;                           
    *p = (*p) -> nodes [(*p) -> nodes[0] == 0];
    delete t;
    return 1;
}

void Cbintree::imprimirEnOrden(CbintreeNode* nodo) {
    if (nodo) {
        imprimirEnOrden(nodo->nodes[0]); // Recorre el subárbol izquierdo
        cout << nodo->dato << " ";       // Imprime el dato del nodo actual
        imprimirEnOrden(nodo->nodes[1]); // Recorre el subárbol derecho
    }
}

void Cbintree::print(){
    cout << "Elementos del árbol en orden ascendente:" << endl;
    imprimirEnOrden(root); // Inicia el recorrido en orden desde el nodo raíz
    cout << endl;
}
int main() {
    Cbintree arbol;

    // Insertar elementos
    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);
    arbol.print();
    return 0;
}

