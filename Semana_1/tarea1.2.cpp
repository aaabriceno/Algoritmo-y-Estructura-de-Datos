#include <iostream>
#include <stdexcept> // Para lanzar excepciones
using namespace std;

template <class T>
class Stack {
public:
    // Constructor
    Stack() : top(0) {}
    
    // Destructor
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Función para agregar un elemento a la pila
    void push(const T& object);
    
    // Función para eliminar y devolver el elemento superior de la pila
    T pop();
    
    // Función para verificar si la pila está vacía
    bool isEmpty();

    // Función para imprimir los elementos de la pila
    void printStack();

private:
    // Definición de un nodo de la pila
    struct StackNode {
        T data;
        StackNode* next;

        StackNode(const T& newData, StackNode* nextNode)
            : data(newData), next(nextNode) {}
    };
    StackNode* top;
};

// Implementación de la función push
template <class T>
void Stack<T>::push(const T& obj) {
    StackNode* newNode = new StackNode(obj, top);
    top = newNode;
}

// Implementación de la función pop
template <class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }

    T poppedData = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp;

    return poppedData;
}

// Implementación de la función isEmpty
template <class T>
bool Stack<T>::isEmpty() {
    return top == 0;
}

// Implementación de la función printStack
template <class T>
void Stack<T>::printStack() {
    StackNode* current = top;
    cout << "Elementos en la pila: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Imprimir la pila con todos los elementos agregados
    myStack.printStack();

    //cout << "Eliminando elementos de la pila:" << endl;

    // Eliminar los elementos uno por uno
    while (!myStack.isEmpty()) {
        cout << "Elemento en la cima de la pila: ";
        cout << myStack.pop() << endl;
    }

    return 0;
}
