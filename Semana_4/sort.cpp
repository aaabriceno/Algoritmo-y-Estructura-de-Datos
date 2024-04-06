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

int* particion(int* low, int* high){
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


void quick_sort(int* low, int*high){
    if(low < high){
        int *pi=particion(low,high);
        quick_sort(low,pi-1);
        quick_sort(pi+1,high);
    }
}
int main(){
    
    auto start = chrono::high_resolution_clock::now();
    const int size = 100;
    int arr[size];

    srand(time(nullptr));

    for(int i = 0; i < size; ++i){
        arr[i] = rand() % 1000;
    }

    cout << "\nArray desordenado:" << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << "\nArray ordenado:" << endl;
    quick_sort(arr,arr + size - 1);

    for (int i = 0; i < size; i++){
        
        cout << arr[i] << " ";
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\nTiempo:\nEl programa tardo " << duration.count() << " milisegundos en ejecutarse.\n";

    return 0;
}