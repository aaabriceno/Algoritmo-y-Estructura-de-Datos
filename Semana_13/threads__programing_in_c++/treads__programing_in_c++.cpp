// treads__programing_in_c++.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <mutex>
#include <thread>

#include <vector>
using namespace std;

mutex m;
long sum = 0;


void F1(char c, int n) {
    for (int i = 0; i < n; i++) {
        cout << c;
    }
}

void F2(int x, int n) {
    for (int i = 0; i < n; i++) {
        m.lock();
        sum += x;
        m.unlock();
    }
}

int main()
{
    
    /*
    thread t(F1, 'c', 50);
    t.join();
    cout << "\n";
    */

    /*
    int i = 0, nThreads = thread::hardware_concurrency();
    vector <thread> ths(nThreads);

    for (int i = 0; i < nThreads; i++) {
        ths[i] = thread(F1, char('a' + i), 100);
        //ths[i].join();
    }

    for (int i = 0; i < nThreads; i++) {
        ths[i].join();
    }
    */

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
