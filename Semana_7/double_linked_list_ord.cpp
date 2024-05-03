#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T valor;
    Node<T>* prev;
    Node<T>* next;
    Node(T valor, Node<T>* prv = nullptr, Node<T>* nxt = nullptr){
        valor = v;
        prv = prev;
        nxt = next;
    }  
};

template <class T>
class double_linked_list{
    public:
        Node<T>* head = nullptr;
        double_linked_list(){}
        void push(T val);
        void pop(T val);
        void print();
};
template <class T>
void double_linked_list<T>::push(T val){
    Node<T> nuevo_nodo = new Node <T>(valor,nullptr,next);
    head = nuevo_nodo;
}

template <class T>
void double_linked_list<T>::pop(T val){

}

template<class T>
void double_linked_list<T>::print(){

}

int main(){
    return 0;
}