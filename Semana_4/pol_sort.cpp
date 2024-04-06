#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
class comparacion{
    public:
        virtual bool compara(int a, int b) = 0;
        virtual ~comparacion(){};
};

class ascendente:public comparacion{
    public:
        bool compara(int a, int b) override ;
};

bool ascendente::compara(int a, int b) {
    return a < b;
}

class descendente:public comparacion{
    public:
        bool compara(int a, int b) override;
};

bool descendente::compara(int a, int b){
    return a > b;
}

class quick_sort{
    public:
        void sort_algoritmo (int arr[], int size, comparacion* cmp) {
            ordenar(arr,0, size - 1, cmp);
        }
    private:
        void swap(int& a, int& b);
        int particion(int arr[],int low, int high, comparacion* cmp);
        void ordenar(int arr[],int low, int high, comparacion* cmp);
};  

void quick_sort::swap (int&a, int &b){
    int temp = a;
    a = b;    
    b = temp;
}

int quick_sort::particion(int arr[], int low, int high, comparacion* cmp){
    int pivote = arr[high];
    int i = low - 1;

    for (int j = low; j <= high; j++){
        if (cmp->compara(arr[j],pivote)){
            ++i;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i + 1],arr[high]);
    return i + 1;
}

void quick_sort::ordenar(int arr[], int low, int high, comparacion* cmp){
    if (low < high){
        int pi = particion(arr, low, high, cmp);
        ordenar(arr, low, pi - 1, cmp); // Corrección aquí
        ordenar(arr, pi + 1, high, cmp);
    }
}


int main(){
    auto start = chrono::high_resolution_clock::now();
    const int size = 100;
    int arr[size];
    srand(time(nullptr));

    for(int i = 0; i < size; ++i){
        arr[i] = rand() % 100;
    }

    cout << "Arreglo sin ordenar:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quick_sort sorter;
    ascendente* asc = new ascendente();
    sorter.sort_algoritmo(arr, size, asc);

    cout << "Arreglo ordenado en orden ascendente:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    descendente* desc = new descendente();
    sorter.sort_algoritmo(arr, size, desc);

    cout << "Arreglo ordenado en orden descendente:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Liberar la memoria
    delete asc;
    delete desc;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\nTiempo:\nEl programa tardo " << duration.count() << " milisegundos en ejecutarse.\n";
    
    return 0;
}