//Lista enlazada ordenada sin repeticion en orden asscendente

#include <iostream>
using namespace std;

struct nodo{
    int value;
    nodo* next;
    nodo(int val) : value(val), next(nullptr) {}
};

class Linked_list{
    public:
        Linked_list(): head (nullptr){}
        bool find(int n, nodo** &p);
        bool insert(int x);
        bool remove(int x);
        void print();
        nodo* head;
};

bool Linked_list::find(int x, nodo** &p){
    p = &head;
    while(*p != 0 && (*p) -> value < x)
    {
        p = &((*p) -> next);
    }
    return *p != 0 && (*p) ->value == x;
}
bool Linked_list::insert(int x){
    nodo** p;
    if (find(x,p)) return 0;
    nodo* t = new nodo(x);
    t -> next = *p;
    *p = t;
    return 1;
}
bool Linked_list::remove(int x){        
    nodo** p;
    if (!find(x,p)) return 0;
    nodo* t = *p;
    *p = t -> next;
    delete t;
    return 1;
}
void Linked_list::print()
{
    nodo* current = head;
    while (current != nullptr) 
    {
        cout << current->value << " "; 
        current = current->next; 
    }
    cout << endl; 
}
int main(){
    Linked_list list;
    list.insert(5);
    list.insert(3);
    list.insert(7);
    list.insert(2);
    list.insert(12);
    list.insert(34);
    list.insert(56);
    list.insert(9);
    list.insert(7);
    list.insert(0);
    list.insert(4);
    list.insert(8);
    list.insert(134);
    list.insert(45);
    list.remove(3);
    list.print();
    list.remove(9);
    list.remove(7);
    list.remove(12);
    list.print();

    
    return 0;
}