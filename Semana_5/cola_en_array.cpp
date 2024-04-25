#include <iostream>
using namespace std;

class cola_en_array {
public:
    int arr[10];
    int *head = nullptr;
    int *tail = nullptr;
    bool push(int n);
    bool pop(int &n);
    void print();
};

bool cola_en_array::push(int n) {
    if ((head == arr && tail == arr + 9) || (head == tail + 1)) {
        // Cola llena
        return false;
    }
    else if (tail == nullptr && head == nullptr) {
        // Cola vacía
        head = arr;
        tail = arr;
    }
    else if (tail == arr + 9) {
        tail = arr;
    }
    else {
        tail++;
    }
    *tail = n;
    return true;
}

bool cola_en_array::pop(int &n) {
    if (head == nullptr && tail == nullptr || head == tail+1) {
        return false; // Cola vacía
    }
    n = *head;
    if (head == arr + 9) {
        head = arr + 10;
    }
    else {
        head++;
    }
    if (head == tail + 1) {
        // Último elemento eliminado
        n = *head;
        head = nullptr;
        tail = nullptr;
    }
    return true;
}

void cola_en_array::print() {
    if (head == nullptr || tail == nullptr) {
        cout << "La cola está vacia." << endl;
        return;
    }
    cout << "Elementos en la cola: ";
    int *current = head;
    while (current != tail) {
        cout << *current << " ";
        if (current == arr + 9) {
            current = arr;
        }
        else {
            current++;
        }
    }
    cout << *current << endl;
}

int main() {
    cola_en_array cola;
    cout << "Agregando elementos (push) - Cola en array " << endl;
    int cant1;
    cout << "Ingrese la cantidad de elementos a ingresar: "; cin>> cant1;
    // Agregar elementos a la cola
    for (int  i = 0; i < cant1; i++){
        if (cola.push(i)){
            cout << "Agregando elemento: " << i << endl;
        }
        else{
            break;
        }
    }
    cout << "Imprimiendo cola en lista enlazada: " << endl;
    cola.print();

    cout << "Eliminando elementos (pop) - Cola en Lista enlazada: " << endl;
    int a, cant2;
    cout << "Ingrese cantida de elementos a eliminar: "; cin >> cant2;
    for (int i = 0; i < cant2;++i){
        if(cola.pop(a)){
            cout << "Elemento eliminado:" << a << endl;
        }
        else{
            cout << "Pila vacia: " << endl;
            break;
        }
    }
    cout << "Imprimiendo cola en lista enlazada: " << endl;
    cola.print();
    cola.push(111);
    cola.push(112);
    cola.push(113);
    
    cola.print();
    return 0;
}
