#include <iostream>
using namespace std;

class Pila {
private:
    int elem[10]; // Array para almacenar los elementos de la pila
    int* top = nullptr; // Puntero que apunta al elemento superior de la pila

public:
    bool push(int a); // Función para insertar un elemento en la pila
    bool pop(int& a); // Función para extraer un elemento de la pila
    void print(); // Función para imprimir todos los elementos de la pila
};

// Implementación de la función push para insertar elementos en la pila
bool Pila::push(int a) {
    if (top == nullptr) { // Si la pila está vacía
        *elem = a; // Insertar el elemento en la primera posición del array
        top = elem; // Actualizar el puntero 'top' para que apunte al primer elemento
        return true; // Indicar que la inserción fue exitosa
    }
    else if (top) { // Si la pila no está vacía
        top++; // Mover el puntero 'top' hacia arriba
        *top = a; // Insertar el elemento en la nueva posición del array
        return true; // Indicar que la inserción fue exitosa
    }
    return false; // Indicar que la inserción no fue exitosa
}

// Implementación de la función pop para extraer elementos de la pila
bool Pila::pop(int& a) {
    if (top >= elem) { // Si la pila no está vacía
        a = *(top--); // Extraer el elemento superior de la pila y actualizar el puntero 'top'
        return true; // Indicar que la extracción fue exitosa
    }
    return false; // Indicar que la extracción no fue exitosa
}

// Implementación de la función para imprimir todos los elementos de la pila
void Pila::print() {
    int* temp = top; // Creamos un puntero temporal para no modificar el puntero 'top' original
    while (temp >= elem) { // Mientras haya elementos en la pila
        cout << *temp << " "; // Imprimimos el elemento
        temp--; // Movemos el puntero temporal hacia abajo para imprimir el siguiente elemento
    }
    cout << endl; // Imprimimos un salto de línea al final
}

// Función principal
int main() {
    Pila pila; // Crear un objeto de tipo Pila
    int elemento = 0; // Variable para almacenar el elemento extraído de la pila

    // Insertar elementos en la pila
    for (int i = 1; i <= 10; ++i) {
        pila.push(i);
    }

    cout << "Pila completa: ";
    pila.print(); // Imprimir todos los elementos de la pila

    cout << "Sacando elementos de la pila:" << endl;
    // Extraer y mostrar cada elemento de la pila
    while (pila.pop(elemento)) {
        cout << "El elemento sacado de la pila es: " << elemento << endl;
    }

    return 0;
}
