// threads_sorting_method.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm> // Para std::inplace_merge
#include <future> // Para std::async
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        // Limitar el número de hilos creados
        if (high - low > 1000) {
            std::thread t1(quick_sort, ref(arr), low, pi - 1);
            std::thread t2(quick_sort, ref(arr), pi + 1, high);
            t1.join();
            t2.join();
        }
        else {
            quick_sort(arr, low, pi - 1);
            quick_sort(arr, pi + 1, high);
        }
    }
}

void print(const vector<int>& arr) {
    for (const int& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void thread_sort(vector<int>& arr) {
    quick_sort(arr, 0, arr.size() - 1);
}

int main()
{
    int n = 8; // numero de threads
    vector<int> arr(10000);
    for (int& i : arr) {
        i = rand() % 10000;
    }

    vector<vector<int>> chunks(n);
    vector<thread> threads(n);

    
    int chunk_size = arr.size() / n;  // Divide the array into n chunks
    for (int i = 0; i < n; i++) {
        auto start_itr = arr.begin() + i * chunk_size;
        auto end_itr = (i == n - 1) ? arr.end() : start_itr + chunk_size;
        chunks[i] = vector<int>(start_itr, end_itr);
    }

    for (int i = 0; i < n; i++) {  // Inicia n hilos para ordenar cada fragmento
        threads[i] = thread(thread_sort, ref(chunks[i]));
    }

    for (auto& t : threads) { // Esperar a que todos los hilos terminen
        t.join();
    }

    
    vector<int> sorted_arr = chunks[0];  // juntar los subarr ordenados usando std::inplace_merge
    for (int i = 1; i < n; i++) {
        sorted_arr.insert(sorted_arr.end(), chunks[i].begin(), chunks[i].end());
        inplace_merge(sorted_arr.begin(), sorted_arr.begin() + i * chunk_size, sorted_arr.end());
    }

   
    print(sorted_arr); //Array ordenado

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
