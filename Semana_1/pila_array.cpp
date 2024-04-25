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
    }

    // Método para verificar si la pila está vacía
    bool estaVacia() {
        return TOP == nullptr;
    }

    // Método para insertar un elemento en la pila
    bool push(int a) {
        if (estaLlena()) {
            cerr << "La pila está llena." << endl;
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
            std::cerr << "La pila está vacía." << std::endl;
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

    // Insertar elementos en la pila
    miPila.push(10);
    miPila.push(20);
    miPila.push(30);

    // Imprimir la pila con los elementos agregados
    miPila.imprimirPila();

    int valor;
    // Eliminar elementos de la pila y mostrarlos
    while (!miPila.estaVacia()) {
        miPila.pop(valor);
        cout << "Elemento retirado de la pila: " << valor << std::endl;
    }

    return 0;
}