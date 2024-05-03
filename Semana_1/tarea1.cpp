#include <iostream>
using namespace std;

class Pila {
private:
    int elem[10]; // Arreglo para almacenar los elementos de la pila
    int* TOP; // Puntero para rastrear el elemento superior de la pila

public:
    // Constructor
    Pila() : TOP(nullptr) {}

    // Método para verificar si la pila está llena
    bool estaLlena() {
        return TOP == &elem[9];
        //cout << "Pila llena" << endl;
    }

    // Método para verificar si la pila está vacía
    bool estaVacia() {
        return TOP == nullptr;
        //cout << "Pila vacia" << endl;
    }

    // Método para insertar un elemento en la pila
    bool push(int a) {
        if (estaLlena()) {
            //cerr << "La pila está llena." << endl;
            return false;
        }
        if (estaVacia())
            TOP = &elem[0]; // Si la pila está vacía, TOP apunta al primer elemento
        else
            TOP++; // Mover TOP al siguiente elemento en el arreglo
        *TOP = a; // Asignar el valor a la posición actual de TOP
        return true;
    }

    // Método para eliminar un elemento de la pila y devolver su valor
    bool pop(int &a) {
        if (estaVacia()) {
            //std::cerr << "La pila está vacía." << std::endl;
            return false;
        }
        a = *TOP; // Obtener el valor del elemento en la cima de la pila
        if (TOP == &elem[0])
            TOP = nullptr; // Si la pila tiene solo un elemento, se convierte en vacía
        else
            TOP--; // Mover TOP al elemento anterior en el arreglo
        return true;
    }

    // Método para imprimir los elementos de la pila
    void imprimirPila() {
        if (estaVacia()) {
            cout << "La pila está vacía." << std::endl;
            return;
        }
        cout << "Elementos en la pila: ";
        for (int* ptr = TOP; ptr >= &elem[0]; ptr--) {
            cout << *ptr << " ";
        }
        cout << std::endl;
    }
};

int main() {
    Pila miPila;
    cout << "HACIENDO PUSH EN LA PILA\n";
    for (int i = 1; i <= 12; i++) {
        if (!miPila.push(i * 10)) {
            miPila.imprimirPila();
            cout << "No se pudo insertar el elemento en la pila. La pila está llena." << endl;
            break;
        }
    }

    cout << "\n\nHACIENDO POP EN LA PILA\n";
    miPila.imprimirPila();
    int valor;
    // Eliminar elementos de la pila y mostrarlos
    for (int i = 1; i <= 12; i++) {
        if (miPila.pop(valor)) {
            cout << "Elemento retirado de la pila: " << valor << endl;
        } else {
            cout << "La pila está vacía." << endl;
            break; // Rompe el bucle si la pila está vacía
        }
    }
    miPila.imprimirPila();
    return 0;
}