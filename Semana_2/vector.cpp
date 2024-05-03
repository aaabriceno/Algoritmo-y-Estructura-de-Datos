#include <iostream>
using namespace std;

struct Cvector {
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
    int size(); // Método para obtener el tamaño del vector
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

int main() {
    Cvector vec;
    cout << "Push back en el vector:" ;
    vec.push_back(8);
    vec.print();
    cout << endl;
    vec.push_back(4);
    vec.print();
    cout << endl;
    vec.push_back(1);
    vec.print();
    cout << endl;
    vec.push_back(2);
    vec.print();
    cout << endl;
    vec.push_back(3);
    vec.print();
    cout << "\n";

    cout << "\nPush front en el vector:\n";
    vec.push_front(12);
    vec.print();
    cout << endl;
    vec.push_front(34);
    vec.print();
    cout << endl;
    vec.push_front(13);
    vec.print();
    cout << endl;
    vec.push_front(5);
    vec.print();
    cout << endl;
    vec.push_front(7);
    vec.print();
    cout << "\n\n";

    cout << "Pop back y pop front en el vector:\n";
    vec.popback();
    vec.print();
    cout << endl;
    vec.popfront();
    vec.print();
    cout << "\n\n";

    int y;
    do {
        cout << "Acceder a un elemento del vector e imprimirlo: ";
        cin >> y;
    } while (y < 0 || y >= vec.size());

    int a = vec[y];
    cout << "El elemento en la posición " << y << " es: " << a << endl;

    return 0;
}
