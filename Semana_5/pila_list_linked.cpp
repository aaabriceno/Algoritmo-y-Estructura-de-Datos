#include <iostream>
using namespace std;

struct Node{
    int dato;
    Node* next;
};

class pila_linked_list{
    private:

    public:
        Node* top = nullptr;
        Node* aux = nullptr;
        ~pila_linked_list(){
            while(top != nullptr){
                Node* temp = top;
                top = top -> next;
                delete temp;
            }
        }
        bool push(int n);
        bool pop( int &n);
        void print();
};

bool pila_linked_list::push(int n){
    Node* nuevo_nodo = new Node;
    nuevo_nodo -> dato = n; 
    nuevo_nodo -> next = top;
    top = nuevo_nodo;
    return true;
}

bool pila_linked_list::pop(int &n){
    if( top == nullptr){
        return false;
    }
    Node* aux = top; 
    n = aux -> dato;
    top = aux -> next;
    delete aux;
    return true;
}

void pila_linked_list::print(){
    Node* actual = top;
    if(actual == nullptr){
        cout << "La pila esta vacia..." << endl;
    }
    while(actual != nullptr){
        cout << actual -> dato << " -> ";
        actual = actual -> next;
    }
    cout << "NULL"<< endl;
}

int main(){
    pila_linked_list p;
    cout << "Agregando elementos (push) - Pila en Lista enlazada: " << endl;
    
    int cant1;
    cout << "Ingrese la cantidad de elementos a agregar: "; cin >> cant1;
    
    for (int i = 0; i < cant1; i++){
        if (p.push(i)){
            cout << "Elemento agregado: " << i << endl;
        }
        else{
            break;
        }
    }
    /*
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    p.push(80);
    */
    cout << "Imprimir elementos de la pila: " << endl;
    p.print();

    cout << "Eliminando elementos (pop) - Pila en Lista enlazada: " << endl;
    
    int x, cant2;
    cout << "Ingrese cantida de elementos a eliminar: "; cin >> cant2;
    
    for (int i = 0; i < cant2; ++i){
        if(p.pop(x)){
            cout << "Elemento eliminado: " << x << endl;
        }
        else{
            cout << "Pila vacia... " << endl;
            break;
        }
    }
    /*
    p.pop(x);
    p.pop(x);
    p.pop(x);
    */
    cout << "Elementos restantes: " << endl;
    p.print();   
    return 0;
}