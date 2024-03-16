#include <iostream>
using namespace std;

bool busq_bin(int *ini, int *fin, int *&pos, int key) {
    if (ini >= fin) 
    {
        cout << "False" << endl; // Imprime "false" si el rango es vacío
        return false;
    }

    int *inicio = ini;
    int *final = fin - 1; // Ajustamos el puntero final para que apunte al último elemento del rango

    for (int *p = inicio; inicio < final; ) 
    {
        int *mid = inicio + (final - inicio) / 2;
        if (*mid == key) {
            pos = mid;
            cout << "True\nPosición: " << (mid - ini) << endl; // Imprime "true" y la posición del elemento
            return true;
        } else if (*mid < key) {
            inicio = mid + 1;
        } else {
            final = mid - 1;
        }
    }

    if (*inicio == key) 
    {
        pos = inicio;
        cout << "True\nPosición: " << (inicio - ini) << endl; // Imprime "true" y la posición del elemento
        return true;
    }

    cout << "False" << endl; // Imprime "false"
    return false;
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;
    cout << "Ingrese el elemento a buscar: ";
    cin >> key;

    int *pos;
    busq_bin(arr, arr + sizeof(arr) / sizeof(arr[0]), pos, key);

    return 0;
}
