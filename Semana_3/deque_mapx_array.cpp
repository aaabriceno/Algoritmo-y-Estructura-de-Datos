#include <iostream>
using namespace std;
template <class T>
class Cdeque {
    T* map[10];
    T** FRONT;
    T** BACK;
    T* front;
    T* back;
    T error = 0;

public:
    Cdeque<T>() {
        map[5] = new T[10];
        BACK = map + 5;
        FRONT = map + 5;
        front = (*FRONT) + 4;
        back = (*BACK) + 5;
    }
    ~Cdeque<T>() {
        while (FRONT <= BACK)
            delete[] *FRONT++;
    }
    void push_back(T v);
    void push_front(T v);
    T pop_back();
    T pop_front();
    int size();
    T& operator [] (int i);
};

template <class T>
void Cdeque<T>::push_back(T v) {
    if (back <= *(BACK)+9) {
        *(back++) = v;
    }
    else {
        if (BACK < map + 10) {
            *(++BACK) = new T[10];
            back = *BACK;
            *back++ = v;
        }
    }
}

template <class T>
void Cdeque<T>::push_front(T v) {
    if (front >= *FRONT) {
        *(front--) = v;
    }
    else {
        if (FRONT > map) {
            *(--FRONT) = new T[10];
            front = *(FRONT)+9;
            *front-- = v;
        }
    }
}

template <class T>
T Cdeque<T>::pop_back() {
    T tmp = error;
    if (BACK != FRONT || back > front + 1) {
        if (back != *BACK)
            tmp = *--back;
        else {
            delete[] * BACK--;
            back = *(BACK)+9;
            tmp = *back;
        }
    }
    return tmp;
}

template <class T>
T Cdeque<T>::pop_front() {
    T tmp = error;
    if (BACK != FRONT || back > front + 1) {
        if (front != *(FRONT)+9)
            tmp = *++front;
        else {
            delete[] * FRONT++;
            front = *FRONT;
            tmp = *front;
        }
    }
    return tmp;
}

template <class T>
int Cdeque<T>::size() {
    int tmp;
    int aux = BACK - FRONT;
    if (aux == 0)
        tmp = back - front - 1;
    else {
        tmp = (aux - 1) * 10;
        int a = ((*FRONT) + 9) - front;
        int b = back - (*BACK);
        tmp += ((*FRONT)+9) - front + back - (*BACK);
    }
    return tmp;
}

template <class T>
T& Cdeque<T>::operator [] (int i) {
    int s = size();
    if (s > i) {
        int aux1, aux2;
        aux1 = i / 10;
        aux2 = i % 10 + front - *FRONT + 1;
        if (aux2 < 10)
            return *(*(FRONT + aux1) + aux2);
        else {
            return *(*(FRONT + aux1 + 1) + aux2 - 10);
        }
    }
    return error;
}

int main() {
    Cdeque<int> d1;
    
    // Push manualmente elementos en la parte delantera y trasera
    d1.push_back(1);
    d1.push_front(0);
    d1.push_back(2);
    d1.push_front(12);
    d1.push_back(3);
    d1.push_front(13);
    d1.push_back(4);
    d1.push_front(14);
    d1.push_back(5);
    d1.push_front(15);
    d1.push_back(6);
    d1.push_front(16);
    d1.push_back(7);
    d1.push_back(8);
    d1.push_back(9);
    d1.push_back(10);
    d1.push_back(11);


    int s = d1.size();

    // Imprimir todo el deque en una sola línea
    cout << "Deque: ";
    for (int i = 0; i < s; i++)
        std::cout << d1[i] << " ";
    cout << "\n";

    // Pop manualmente elementos de la parte delantera y trasera
    /*
    for (int i = 0; i < s / 1; i++) {
        std::cout << d1.pop_front() << " ";
        std::cout << d1.pop_back() << " ";
    }
    std::cout << "\n";

    // Imprimir el deque después de los pops
    
    std::cout << "Deque después de pops: ";
    for (int i = 0; i < d1.size(); i++)
        std::cout << d1[i] << " ";
    std::cout << "\n";
    */
    // Modificar un elemento y volver a imprimir todo el deque
    int num, n;
    
    cout << "Ingrese el indice a modificar y el numero por el que desea cambiar: "; cin >> num; cin >> n;
    cout << "Deque después de modificar el elemento "<< num << ": ";
    d1[num] = n;
    for (int i = 0; i < d1.size(); i++)
    {    
        cout << d1[i] << " ";
    }
    cout << "\n";

    return 0;
}