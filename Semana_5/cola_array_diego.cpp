#include <iostream>
using namespace std;

class cola_en_array {
public:
    int arr[10];
    int *head = nullptr;
    int *tail = nullptr;
    bool push(int n);
    bool pop(int &n);
    void print();
};

bool cola_en_array::push(int n) {
    if ((head == arr && tail == arr + 9) || (head == tail + 1)) {
        // Cola llena
        return false;
    }
    else if (tail == nullptr && head == nullptr) {
        // Cola vacía
        head = arr;
        tail = arr;
    }
    else if (tail == arr + 9) {
        tail = arr;
    }
    else {
        tail++;
    }
    *tail = n;
    return true;
}

bool cola_en_array::pop(int &n) {
    if (head == nullptr && tail == nullptr || head == tail+1) {
        return false; // Cola vacía
    }
    n = *head;
    if (head == arr + 9) {
        head = arr + 10;
    }
    else {
        head++;
    }
    if (head == tail + 1) {
        // Último elemento eliminado
        n = *head;
        head = nullptr;
        tail = nullptr;
    }
    return true;
}

void cola_en_array::print() {
    if (head == nullptr || tail == nullptr) {
        cout << "La cola está vacia." << endl;
        return;
    }
    cout << "Elementos en la cola: ";
    int *current = head;
    while (current != tail) {
        cout << *current << " ";
        if (current == arr + 9) {
            current = arr;
        }
        else {
            current++;
        }
    }
    cout << *current << endl;
}

int main() {
    cola_en_array cola;

    // Agregar elementos a la cola
    cola.push(10);
    cola.push(20);
    cola.push(30);
    cola.push(100);
    cola.push(90);
    cola.push(80);
    cola.push(70);
    cola.push(50);
    cola.push(60);
    cola.push(12);
    //cola.push(13);
    cola.print();
  
    int a;
    cola.pop(a);
    cola.pop(a);
    cola.pop(a);
    cola.pop(a);
    cola.pop(a);
    cola.pop(a);
    cola.pop(a);
    cola.pop(a);
    cola.pop(a);
    cola.pop(a);
    cola.print();
    
    cola.push(111);
    cola.push(112);
    cola.push(113);
    cola.push(114);
    cola.push(115);
    cola.print();
    return 0;
}
