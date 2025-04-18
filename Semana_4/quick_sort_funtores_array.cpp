//Método de ordenamiento Quicksort con funtores(templates) - sin inline
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
struct cless{
    bool cmp(T a, T b){
        return a < b;
    }
};
template <class T>
struct cgreater{
    bool cmp(T a,T b){
        return a > b;
    }
};

template <class T>
void cambia(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T, class Functor>
int particion(T arr[], int low, int high, Functor compara){
    T pivote = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){ // Corrección del límite del bucle
        if (compara.cmp(arr[j], pivote)){
            i++;
            cambia(arr[i], arr[j]);
        }
    }
    cambia(arr[i + 1], arr[high]);
    return i + 1;
}

template <class T, class Functor>
void quickSort(T arr[], int low, int high, Functor compara){
    if (low < high){
        int pi = particion(arr, low, high, compara);

        quickSort(arr, low, pi - 1, compara);
        quickSort(arr,pi +1, high, compara);
    }
}

int main(){
    auto start = chrono::high_resolution_clock::now();
    const int size = 10000;
    int arr[size];

    srand(time(nullptr));

    for (int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }

    cout << "Arreglo sin ordenar:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cless<int> le;
    quickSort(arr,0,size - 1,le);

    cout << "\nArreglo Ordenado Ascendentemente " << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cgreater<int> gr;
    quickSort(arr,0,size - 1,gr);

    cout << "\nArreglo Ordenado Descendentemente " << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nTiempo:\nEl programa tardo " << duration.count() << " microsegundos en ejecutarse.\n";
    return 0;
}
