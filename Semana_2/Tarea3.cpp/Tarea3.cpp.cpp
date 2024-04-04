// Tarea3.cpp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
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

private:
    void ordenar(int* inicio, int* fin);
    Nodo* findInsertionPoint(int numero);
};

void Elementor::add(int numero) {
    Nodo* insertionPoint = findInsertionPoint(numero);

    if (insertionPoint == nullptr) {
        // Crear un nuevo nodo si la lista está vacía o el número es menor que el primer elemento
        Nodo* newNodo = new Nodo;
        newNodo->ini = &newNodo->array[0];
        newNodo->fin_valido = newNodo->ini;
        newNodo->next = head;
        head = newNodo;
        insertionPoint = head;
    }

    if (insertionPoint->fin_valido - insertionPoint->ini >= num_elem) {
        // Si el nodo está lleno, insertar un nuevo nodo antes de él
        Nodo* newNodo = new Nodo;
        newNodo->ini = &newNodo->array[0];
        newNodo->fin_valido = newNodo->ini;
        newNodo->next = insertionPoint->next;
        insertionPoint->next = newNodo;
        insertionPoint = newNodo;
    }

    // Insertar el número en la posición adecuada dentro del nodo
    int* pos = insertionPoint->fin_valido;
    while (pos != insertionPoint->ini && numero < *(pos - 1)) {
        *pos = *(pos - 1);
        --pos;
    }
    *pos = numero;
    ++(insertionPoint->fin_valido);
}

void Elementor::del(int numero) {
    Nodo* current = head;
    Nodo* previous = nullptr;

    while (current != nullptr) {
        // Buscamos el elemento en el array del nodo actual
        int* pos = current->ini;
        while (pos != current->fin_valido && *pos != numero) {
            ++pos;
        }

        if (pos != current->fin_valido) {
            // Si encontramos el elemento, lo eliminamos
            while (pos != current->fin_valido - 1) {
                *pos = *(pos + 1);
                ++pos;
            }
            --(current->fin_valido);
            break;
        }

        previous = current;
        current = current->next;
    }

    if (current != nullptr && current->ini == current->fin_valido) {
        // Si el nodo actual quedó vacío, lo eliminamos
        if (previous != nullptr) {
            previous->next = current->next;
        }
        else {
            head = current->next;
        }
        delete current;
    }
}

void Elementor::print() {
    Nodo* current = head;
    while (current != nullptr) {
        for (int* p = current->ini; p != current->fin_valido; ++p) {
            cout << *p << " ";
        }
        current = current->next;
    }
    cout << endl;
}

Nodo* Elementor::findInsertionPoint(int numero) {
    Nodo* current = head;
    Nodo* previous = nullptr;

    while (current != nullptr && numero >= *(current->ini)) {
        previous = current;
        current = current->next;
    }

    return previous;
}

int main() {
    Elementor lista;

    lista.add(20);
    lista.add(14);
    lista.add(12);
    lista.add(10);
    lista.add(9);
    lista.add(8);
    lista.add(7);
    lista.add(6);
    lista.add(5);
    lista.add(4);
    lista.add(1);
    lista.add(18);
    lista.add(16);

    lista.print();

    lista.del(10);
    lista.print();

    return 0;
}

