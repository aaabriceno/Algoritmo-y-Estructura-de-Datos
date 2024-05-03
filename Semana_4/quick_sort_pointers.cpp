//Metodo de ordenancion basico con punteros
#include <iostream>
#include <chrono>
using namespace std;

void swap(int* a, int* b, int arr[], int tam){
    int temp = *a;
    *a = *b;
    *b = temp;

    // Imprimir el array después del intercambio
    cout << "Array después del intercambio: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* particion(int* low, int* high, int arr[], int tam){
    int pivote = *high;
    int* i = low - 1;
    
    for(int* j = low; j <= high; j++){
        if(*j < pivote){
            i++;
            swap(i,j,arr,tam); // Pasar el array y su tamaño
        }
    }
    swap(i+1,high,arr,tam); // Pasar el array y su tamaño
    return(i+1);
}

void quick_sort(int* low, int*high, int arr[], int tam){
    if(low < high){
        int *pi=particion(low,high,arr,tam); // Pasar el array y su tamaño
        quick_sort(low,pi-1,arr,tam); // Pasar el array y su tamaño
        quick_sort(pi+1,high,arr,tam); // Pasar el array y su tamaño
    }
}

int main(){
    auto start = chrono::high_resolution_clock::now();
    
    int arr[]={1,9,2,8,3,7,4,6,5,0};
    int tam = sizeof(arr)/sizeof(arr[0]);
    
    cout << "\nArray desordenado:" << endl;
    for (int i = 0; i < tam; i++){
        cout << arr[i] << " ";
    }

    cout << "\nArray ordenado" << endl;
    quick_sort(arr,arr + tam - 1,arr,tam); // Pasar el array y su tamaño

    cout << "Array ordenado: ";
    for (int i = 0; i < tam; i++){
        cout << arr[i] << " ";
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);
    cout << "\nTiempo:\nEl programa tardo " << duration.count() << " milisegundos en ejecutarse.\n";


    return 0;
}
