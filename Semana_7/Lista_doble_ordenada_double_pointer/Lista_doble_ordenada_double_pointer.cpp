// Lista_doble_ordenada_double_pointer.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
struct nodo_doble_lista {
    int dato;
    nodo_doble_lista* nodos[2];
    nodo_doble_lista(int d) { dato = d; nodos[0] = nodos[1] = 0; }
};
class Cdoublelist {
public:
    Cdoublelist() {head = 0;}
    
    bool insertar(int x) {
        nodo_doble_lista** p;
        if (buscar(x, p)) return 0;
        nodo_doble_lista* t = new nodo_doble_lista(x);
        t->nodos[1] = *p;
        *p = t;
         return 1;
    }

    //bool remover(int x){}
    
    void print(){
        for (nodo_doble_lista* t = head; t; t = t->nodos[1]) 
            cout << t->dato << " ";
        cout << "\n";
    }
private:
    bool buscar(int x, nodo_doble_lista**& p) {  
        p = &head;
        while ((*p) && (*p)->dato < x) {
            p = &((*p)->nodos[1]);
        }
        return *p != 0 && (*p)->dato == x;
    }
    nodo_doble_lista* head;
};

int main()
{
    Cdoublelist l;
    l.insertar(12);
    l.insertar(1);
    l.insertar(4);
    l.insertar(6);
    l.insertar(7);
    l.insertar(8);
    l.insertar(0);
    l.insertar(2);
    l.insertar(-8);
    l.insertar(-7);
    l.insertar(3);
    l.print();
    return 0;
}

