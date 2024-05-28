// recorrido_inorder_arbol_binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

template <class T>
struct nodo {
    T dato;
    nodo* ptrs[2];
    nodo::nodo(T d) { dato = d; ptrs[0] = ptrs[1] = 0; }
};

template <class T>
class arbol_binario {
public:
    arbol_binario();
    ~arbol_binario();
    bool agregar(T x);
    bool remover(T x);
    void print();
private:
    bool buscar(T x, nodo<T>** p);
    nodo<T>** reemplazar(nodo<T>** p);
    void inorder(nodo<T>* x);
    nodo<T>* raiz;
    bool bb;
};

template <class T>
arbol_binario<T>::arbol_binario() {
    raiz = 0;
    bb = 0;
}
template <class T>
arbol_binario<T>::~arbol_binario() {
    //
}

template <class T>
bool arbol_binario<T>::buscar(T x,nodo<T>**p) {
    p = &raiz;
    while ((*p) && (*p)->dato != x) {
        p = &((*p)->ptrs[x > (*p)->dato])
    }
    return *p && (*p)->dato == x;
}
template <class T>
nodo<T>** arbol_binario<T>::reemplazar(nodo<T>** p) {

}

template <class T>
bool arbol_binario<T>::agregar(T x) {
    nodo<T>** p = &raiz;
    if (buscar(x, p)) return 0;
    *p = new nodo<T>(x);
    return 1;
}
template <class T>
bool arbol_binario<T>::remover(T x) {
    nodo <T>** p = &raiz;
    if (!buscar(x, p)) return 0;
    // caso 2 hijos

}

template <class T>
void arbol_binario<T>::inorder(nodo<T>* nodo_in) {
    if (nodo_in) {
        inorder(nodo_in->ptrs[0]);
        cout << nodo->dato << " ";
        inorder(nodo_in->ptrs[1]);
    }
}
int main()
{
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
