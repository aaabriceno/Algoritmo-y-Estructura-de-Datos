#ifndef Cvector_h
#define Cvector_h
#include <iostream>

class Cvector
{   /* data */
public:
    int* arr = nullptr;
    int* head = nullptr;
    int* tail = nullptr;
    int tam = 5;
    int elemt = 0;
    void push_front(int val);
    void push_back(int val);
    void popfront();
    void popback();
    void rescribir(int newtam);
    void print();
    int& operator[](int val);
    int size(); // Método para obtener el tamaño del Cvector
    ~Cvector(); // Destructor para liberar la memoria asignada dinámicamente
};

void Cvector::rescribir(int newtam) {
    int* newarr = new int[newtam];
    int* ini = head;
    int av = 0;

    if (head != nullptr) {
        while (ini <= tail) {
            *(newarr + av) = *ini;
            ini++;
            av++;
        }
    }

    delete[] arr;
    arr = newarr;
    tam = newtam;
    head = arr;
    if (head != nullptr)
        tail = arr + av - 1;
}

void Cvector::push_front(int val) {
    if (arr == nullptr) {
        arr = new int[tam];
        head = arr;
        tail = arr;
        *head = val;
        elemt++;
        return;
    }

    if (tail == arr + elemt - 1) {
        rescribir(tam * 2);
    }

    int* ini = tail + 1;

    while (ini > head) {
        *ini = *(ini - 1);
        ini--;
    }

    *head = val;
    tail++;
    elemt++;
}

void Cvector::push_back(int val) {
    if (arr == nullptr) {
        arr = new int[tam];
        head = arr;
        tail = arr;
        *head = val;
        elemt++;
        return;
    }

    if (tail == arr + elemt - 1) {
        rescribir(tam * 2);
    }

    *(tail + 1) = val;
    tail++;
    elemt++;
}

void Cvector::popfront() {
    if (head == nullptr) {
        return;
    }

    int* ini = head;

    while (ini < tail) {
        *ini = *(ini + 1);
        ini++;
    }

    *tail = 0;
    elemt--;
    tail--;
}

void Cvector::popback() {
    if (tail == nullptr) {
        return;
    }

    *tail = 0;
    elemt--;
    tail--;
}

void Cvector::print() {
    int* ini = head;

    while (ini <= tail) {
        std::cout << *ini << " ";
        ini++;
    }
}

int& Cvector::operator[](int val) {
    int i = 0;
    for (; i < val; i++);
    return arr[i];
}

int Cvector::size() {
    return elemt;
}

Cvector::~Cvector() {
    delete[] arr;
}
#endif 