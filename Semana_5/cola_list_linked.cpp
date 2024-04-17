#include <iostream>
using namespace std;

struct Nodo{
    int dato ;
    Nodo* next;
};

class cola_linked_list{
    public:
        int *TOP = nullptr;
        bool push(int n);
        bool pop(int &n);
        void print();
};

bool cola_linked_list::push(int n){
    if (TOP == nullptr){
        
    }
}

bool cola_linked_list::pop(int &n){

}

void cola_linked_list::print(){

}

int main(){
    return 0;
}