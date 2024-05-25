// Pregunta3_resolucion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdexcept> // Para out_of_range
using namespace std;

class XVector
{
public:
    int size = 0;
    int size_map, size_vec;
    int** inicio_vec_pt = NULL;
    int** final_vec_pt = NULL;
    int** s = NULL;
    int* inicio = NULL;
    int* final = NULL;
    int* p = NULL;
    XVector(int size_map, int size_vec);
    ~XVector();

    void push_front(int dato)
    {
        int* i = final;
        int** J = s;
        int** I = s;
        for (; i != p - 1; i--);
        int* j = i + 1;
        if (j == final)
        {
            s++;
            if (s == final_vec_pt)
            {
                size_map = size_map * 2;
                int** tmp = inicio_vec_pt;
                inicio_vec_pt = new int* [size_map];
                s = inicio_vec_pt;
                for (int** i = inicio_vec_pt; tmp != final_vec_pt; tmp++, i++, s++)
                {
                    *i = *tmp;
                }
                final_vec_pt = inicio_vec_pt + size_map;
            }
            *s = new int[size_vec];
            p = *(s);
            final = *s + size_vec;
            j = *s;
            J = s;
        }
        *j = *i;
        i--;
        j--;
        while (i != inicio - 1)
        {
            if (j == (*J) - 1)
            {
                J--;
                j = (*J) + size_vec - 1;
            }
            if (i == (*I) - 1)
            {
                I--;
                i = (*I) + size_vec - 1;
            }
            swap(*i, *j);
            i--; j--;
        }
        p++;
        *inicio = dato;
        size++;
    }
    void push_back(int dato)
    {
        if (p != final)
        {
            *p = dato;
            p++;
        }
        else
        {
            s++;
            if (s == final_vec_pt)
            {
                size_map = size_map * 2;
                int** tmp = inicio_vec_pt;
                inicio_vec_pt = new int* [size_map];
                s = inicio_vec_pt;
                for (int** i = inicio_vec_pt; tmp != final_vec_pt; tmp++, i++, s++)
                {
                    *i = *tmp;
                }
                final_vec_pt = inicio_vec_pt + size_map;
            }
            *s = new int[size_vec];
            p = *s;
            *p = dato;
            p++;
            final = *s + size_vec;
        }
        size++;
    }

    int& operator[](int dato)
    {
        if (dato < size)
        {
            int** t = inicio_vec_pt + (dato / size_vec);
            int* j = *t;
            return *(j + (dato % size_vec));
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }
};

XVector::XVector(int sm, int sv)
{
    size_map = sm;
    size_vec = sv;
    inicio_vec_pt = new int* [size_map];
    final_vec_pt = inicio_vec_pt + size_map;
    s = inicio_vec_pt;
    *inicio_vec_pt = new int[size_vec];
    inicio = *inicio_vec_pt;
    final = inicio + size_vec;
    p = inicio;
}

XVector::~XVector()
{
    for (int** i = inicio_vec_pt; i != s; i++)
    {
        delete[] * i;
    }
    delete[] inicio_vec_pt;
}

void print(XVector* p)
{
    for (int i = 0; i < p->size; i++)
        cout << (*p)[i] << " ";
    cout << "\n";
}

int main()
{
    XVector z(4, 3);
    z.push_back(3); z.push_back(8); z.push_back(1);
    z.push_back(4); z.push_back(9); z.push_back(6);
    z.push_back(7);
    print(&z);
    z.push_front(45); z.push_front(2);
    print(&z);
    z.push_front(511); z.push_front(38);
    z.push_back(112);
    print(&z);
    z.push_front(43); z.push_back(27);
    print(&z);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
