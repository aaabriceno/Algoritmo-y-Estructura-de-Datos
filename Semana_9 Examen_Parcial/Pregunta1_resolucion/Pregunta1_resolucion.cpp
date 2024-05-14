/*
Pregunta 1
    En el siguiente código implementa el método ADD y DEL de la clase CircularLinkedList 
    que es una lista circular ordenada.
*/

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
};

class CircularLinkedList
{
    node* head = NULL;
public:
    bool buscar(int x, node**& p) {
        p = &head;
        while (*p && (*p)->data < x) {p = &((*p)->next);}
        return 1;
    }
   void add(int x)
    {
        node** p;
        if (buscar(x, p)) return ;
        node* t = *p;
        *p = new node;
        (*p)->data = x;
        (*p)->next = t;
        if (head)
            t->next = head;
        else
            (*p)->next = *p;
    }

    bool del(int x)
    {
        node** p;
        if (!buscar(x, p)) return 0;


    }

    void print()
    {
        int cont = 0;
        node* ptr = head;
        cout << "head->";
        while (head && cont < 1)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
            if (ptr == head) cont++;
        }
        if (head) cout << ptr->data;
        cout << " <- head \n ";

    }
};

int main()
{
    int ADD[10] = { 2,4,6,8,10,1,3,5,7,9 };
    int DEL[10] = { 9,7,5,3,1,10,8,6,4,2 };
    CircularLinkedList CLL;
    for (int i = 0; i < 10; i++)
    {
        cout << "ADD " << ADD[i] << endl;
        CLL.add(ADD[i]);
        CLL.print();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "DEL " << DEL[i] << endl;
        CLL.del(DEL[i]);
        CLL.print();
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
