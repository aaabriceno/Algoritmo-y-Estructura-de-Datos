#include <iostream>
using namespace std;

class cola_en_array{
    public:
        int arr[10];
        int *head = nullptr;
        int *tail = nullptr;
        bool push(int n);
        bool pop(int &n);
        void print();
};


bool cola_en_array::push(int n){
    if ((head == nullptr && tail == nullptr) || (head == arr + 10 && tail == arr +10)){
        head = arr;
        tail = arr;
    }
    else if(head != arr && tail == arr + 10) {
        tail = arr;
    }
    else if(head != arr && tail != arr + 10){
        return false;
    }
    else if(head == arr && tail == arr + 10){
        if (*(tail) != 0){
            return false;
        }
        tail = arr;
    }
    *tail = n;
    tail++; 
    return true;   
}

bool cola_en_array::pop(int &n){
    if((tail == nullptr && head == nullptr) || (tail == arr + 10 && head == arr + 10)){
        return false;
    }
    else if ((head != nullptr && tail != nullptr) || (tail == arr + 10 && head != arr + 9)||(tail != arr + 10 && head != arr + 10)){
        n = *head;
        head++;
        if(head == arr +10){
            head == arr;
        }
    }
    else if ((tail == arr && head == arr) || (tail == arr + 10 && head == arr + 9) || (tail == head + 1 && tail != arr))
    {
        n = *head;
        head = nullptr;
        tail = nullptr;
    }
    else if (head == arr + 10 && tail != arr + 10){
        n = *head;
        head = arr;
    }
    return true;
}

void cola_en_array::print() {
    if (head == nullptr && tail == nullptr) {
        cout << "La cola está vacía." << endl;
        return;
    }
    cout << "Elementos en la cola: ";
    int *current = head;
    while (current != tail) {
        cout << *current << " ";
        current++;
        if (current == arr + 11) {
            current = arr;
        }
    }
    //cout << *current << endl;
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
    cola.push(13);
    
    //cola.pop(12);
    
    cola.print();

    return 0;
}


