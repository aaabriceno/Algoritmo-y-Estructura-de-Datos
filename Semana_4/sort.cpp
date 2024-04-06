#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* particion_asc(int* low, int* high){
    int pivote = *high;
    int* i = low - 1;
    
    for(int* j = low; j <= high; j++){
        if(*j < pivote){
            i++;
            swap(i,j);
        }
    }
    swap(i+1,high);
    return(i+1);
}

int* particion_desc(int* low, int* high) {
    int pivot = *high;
    int *i = low - 1;

    for (int *j = low; j <= high - 1; j++) {
        if (*j >= pivot) {  
            i++;
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return i + 1;
}


void quick_sort_asc(int* low, int*high){
    if(low < high){
        int *pi = particion_asc(low, high);
        quick_sort_asc(low, pi - 1);
        quick_sort_asc(pi + 1, high);
    }
}

void quick_sort_desc(int* low, int*high){
    if(low < high){
        int *pi = particion_desc(low, high);
        quick_sort_desc(low, pi - 1);
        quick_sort_desc(pi + 1, high);
    }
}

int main(){
    auto start = chrono::high_resolution_clock::now();
    const int size = 50;
    int arr[size];

    srand(time(nullptr));

    for(int i = 0; i < size; ++i){
        arr[i] = rand() % 1000;
    }

    cout << "\nArray desordenado:" << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << "\nArray ordenado ascendente:" << endl;
    quick_sort_asc(arr, arr + size - 1);

    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << "\nArray ordenado descendente:" << endl;
    quick_sort_desc(arr, arr + size - 1);

    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\nTiempo:\nEl programa tardó " << duration.count() << " milisegundos en ejecutarse.\n";

    return 0;
}
