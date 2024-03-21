#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
    Stack() : top(0) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& object);
    T pop();
    bool isEmpty();

private:
    struct StackNode {
        T data;
        StackNode* next;

        StackNode(const T& newData, StackNode* nextNode)
            : data(newData), next(nextNode) {}
    };
    StackNode* top;
};

template <class T>
bool Stack<T>::isEmpty() {
    return top == 0;
}

template <class T>
void Stack<T>::push(const T& obj) {
    StackNode* newNode = new StackNode(obj, top);
    top = newNode;
}

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

int main() {
    Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    while (!myStack.isEmpty()) {
        cout << myStack.pop() << " ";
    }

    return 0;
}