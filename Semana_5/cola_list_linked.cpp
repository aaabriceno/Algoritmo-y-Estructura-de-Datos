#include <iostream>
using namespace std;

struct Nodo{
    int dato ;
    Nodo* next;
};

class cola_linked_list{
    public:
        Nodo* head = nullptr;
        Nodo* tail = nullptr;
        bool push(int n);
        bool pop(int &n);
        void print();
};

bool cola_linked_list::push(int n){
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo -> dato = n;
    nuevo_nodo -> next = nullptr;
    if(head == nullptr){
        head = nuevo_nodo;
        tail = nuevo_nodo;
    }
    else{
        tail -> next= nuevo_nodo;
        tail = nuevo_nodo;
    }
    return true;
}

bool cola_linked_list::pop(int &n){

}

void cola_linked_list::print(){
    Nodo* p = head;
    if (p == nullptr){
        cout << "Cola vacia" << endl;
    }
    while(p != nullptr){
        cout << p->dato << " -> ";
        p = p ->next;
    }
    cout << "NULL " << endl;
}

int main(){
    cola_linked_list c;
    cout << "Agrengando elementos (push) - Cola en Lista enlazada: " << endl;
    int cant1;
    cout << "Ingrese la cantidad de elementos que desea ingresar: " ; cin>> cant1;
    for (int i = 0; i < cant1; i++){
        if(c.push(i)){
            cout << "Agregando elemento: " << i << endl;
        }
        else{
            break;
        }
    }
    cout << "Imprimiendo cola en lista enlazada: " << endl;
    c.print();

    return 0;
}