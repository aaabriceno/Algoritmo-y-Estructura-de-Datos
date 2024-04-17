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
    Node* aux = top;

}

void pila_linked_list::print(){
    Node* actual = top;
    if(top == nullptr){
        cout << "La pila esta vacia..." << endl;
    }
    while(actual != nullptr){
        cout << actual -> dato << " ";
        actual = actual -> next;
    }
    cout << endl;
}

int main(){
    pila_linked_list p;
    cout << "Metodo push en pila_linked_list: " << endl;
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    p.push(50);
    p.push(60);
    p.push(70);
    p.push(80);


    //cout << "Imprimir elementos de la pila: " << endl;
    p.print();
    return 0;
}