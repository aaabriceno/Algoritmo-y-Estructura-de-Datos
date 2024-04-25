//Lista enlazada ordenada sin repeticion en orden descendente

#include <iostream>
using namespace std;

struct nodo //estructura nodo
{
    int valor;
    nodo* next;
    nodo(int val) : valor(val), next(nullptr) {}
};

class lista_enlace_orden_dsc{
    public:
        lista_enlace_orden_dsc() : head(nullptr){} //constructor
        bool buscar(int x, nodo** &p);
        bool insertar(int x);
        bool extraer(int x);
        void print();
        nodo* head;
};
bool lista_enlace_orden_dsc::buscar(int x, nodo** &p){
    p = &head;
    while(*p != 0 && (*p)->valor > x){
        p = &((*p)->next);
    }
    return  *p != 0 && (*p) -> valor == x;
}   

bool lista_enlace_orden_dsc::insertar(int x){
    nodo** p;
    if(buscar(x,p)){
        return 0;
    }
    nodo* t = new nodo(x);
    t -> next = *p;
    *p = t;
    return 1;
}

bool lista_enlace_orden_dsc::extraer(int x){
    nodo ** p;
    if(!buscar(x,p)) return 0;
    nodo* t = *p;
    *p = t -> next;
    delete t;
    return 1;
}

void lista_enlace_orden_dsc::print(){
    nodo* current = head;
    while(current != nullptr){
        cout << current -> valor << " ";
        current = current ->next;
    }
    cout << endl;
}

int main(){
    lista_enlace_orden_dsc l;
    l.insertar(3);
    l.insertar(12);
    l.insertar(1);
    l.insertar(10);
    l.insertar(34);
    l.insertar(-4);
    l.insertar(11);
    l.print();

    l.extraer(9);
    l.extraer(13);
    l.extraer(10);
    l.print();

    return  0;
}