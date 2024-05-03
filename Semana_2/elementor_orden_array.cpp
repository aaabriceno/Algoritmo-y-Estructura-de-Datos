#include <iostream>
#include <algorithm> // Para la función std::sort
using namespace std;

const int num_elem = 10;

struct Nodo {
    int array[num_elem];    // Array de 10 elementos en cada nodo creado
    int* ini;               // Puntero al primer elemento del array
    int* fin_valido;       // Puntero al último elemento del array
    Nodo* next;
};

class Elementor {
private:
    Nodo* head;

public:
    Elementor() {
        head = nullptr;
    }

    ~Elementor() {
        Nodo* current = head;
        while (current != nullptr) {
            Nodo* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(int numero);
    void del(int numero);
    void print();
};

void Elementor::add(int numero) {
    if (head == nullptr || head->fin_valido - head->ini >= num_elem) {
        // Si la lista está vacía o el último nodo está lleno, agregamos un nuevo nodo
        Nodo* newNodo = new Nodo;
        newNodo->ini = &newNodo->array[0];
        newNodo->fin_valido = newNodo->ini;
        newNodo->next = head;
        head = newNodo;
    }

    *(head->fin_valido) = numero;  // Agregamos el número al nodo actual
    head->fin_valido++;

    // Ordenamos el array del nodo actual
    sort(head->ini, head->fin_valido);
}

void Elementor::del(int numero) {
    Nodo* current = head;
    Nodo* previous = nullptr;

    while (current != nullptr) {
        // Buscamos el elemento en el array del nodo actual
        int* pos = find(current->ini, current->fin_valido, numero);

        if (pos != current->fin_valido) {
            // Si encontramos el elemento, lo eliminamos
            current->fin_valido = remove(current->ini, current->fin_valido, numero);
            break;
        }

        previous = current;
        current = current->next;
    }

    if (current != nullptr && current->ini == current->fin_valido) {
        // Si el nodo actual quedó vacío, lo eliminamos
        if (previous != nullptr) {
            previous->next = current->next;
        } else {
            head = current->next;
        }
        delete current;
    }
}

void Elementor::print() {
    Nodo* current = head;
    while (current != nullptr) {
        cout << "[";
        for (int* p = current->ini; p != current->fin_valido; ++p) {
            cout << *p;
            if (p != current->fin_valido - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next; // Mover al siguiente nodo
    }
    cout << endl;
}


int main() {
    Elementor lista;

    lista.add(20);
    lista.add(18);
    lista.add(17);
    lista.add(16);
    lista.add(15);
    lista.add(14);
    lista.add(13);
    lista.add(12);
    lista.add(11);
    lista.add(10);
    lista.add(9);
    lista.add(8);
    lista.add(7);
    lista.add(6);
    lista.add(5);
    lista.add(4);
    lista.add(3);
    lista.add(2);
    lista.add(1);
    lista.add(0);
    lista.add(19);
    lista.print(); // Debería imprimir: 1 2 3 4 5 6 7 
}