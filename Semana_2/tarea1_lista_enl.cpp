/*
Hacer una array que tenga funciones
push_back - push_front; pop_back - pop_front y sobrecarga de corchetes
*/

#include <iostream>
using namespace std;

struct node {
	int valor;
	node* next;
	node* prev;
	node(int value) : valor(value), next(nullptr), prev(nullptr) {}
};

struct Clist {
	node* head = nullptr;
	node* tail = nullptr;
    int num_nodo = 0;

	void pushfront(int val);
	void pushback(int val);
	void popfront();
	void popback();
	void print();
	node* operator[](int val);
    int size();
};

void Clist::pushfront(int val) {
	if (head == NULL) {
		head = new node(val);
		tail = head;
	}
	else {
		head->prev = new node(val);
		head->prev->next = head;
		head = head->prev;
	}
    num_nodo++;
}

void Clist::pushback(int val) {
	if (head == NULL) {
		head = new node(val);
		tail = head;
	}
	else {
		tail->next = new node(val);
		tail->next->prev = tail;
		tail = tail->next;
	}
    num_nodo++;
}

void Clist::popfront() {
	if (head == NULL) {
		cout << "lista vacia uwu" << endl;
	}
	else {
		node* temp = head;
		head = head->next;
		delete temp;
	}
    num_nodo--;
}

void Clist::popback() {
	if (head == NULL) {
		cout << "lista vacia uwu" << endl;
	}
    else if(head == tail ){
        delete head;
        head = tail = nullptr;
    }
	else {
		node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
	}
    num_nodo--;
}

void Clist::print() {
	node* tmp = head;
	while (tmp != nullptr) {
		cout << tmp->valor << " ";
		tmp = tmp->next;
	}
}

node* Clist::operator[](int val) {
	node* tmp = head;
	for (int i = 0; i < val && tmp != NULL; tmp = tmp->next, i++){ 
		//cout << tmp->valor << " ";
	}
	return tmp;
}

int Clist::size()
{
    return num_nodo;
}

int main() {
	Clist lis;

    cout << "Agregacion de elementos pushback y pushfront" << endl;
    lis.pushback(123);
    lis.print();
    cout << endl;
    lis.pushfront(3);
    lis.print();
    cout << endl;
    lis.pushback(4);
    lis.print(); 
    cout << endl;
    lis.pushfront(5);
    lis.print();
    cout << endl;
    lis.pushback(12);
    lis.print();
    cout << endl;
	lis.pushfront(142);
    lis.print();
    cout << endl;

    cout << "\nPopfront y popback" << endl;
	lis.print();
    cout << endl;
    lis.popfront();
    lis.print();
    cout << endl;
	lis.popback();
    lis.print();
    cout << endl;

    cout << "\nAcceder a un elemento de la lista e imprimirlo" << endl;
    int x;
    do {
        cout << "Ingrese el indice del elemento que desea imprimir: ";
        cin >> x;
        if (x < 0 || x >= lis.size()) {
            cout << "Índice inválido. ";
        }
    } while (x < 0 || x >= lis.size());
    
    node* val = lis[x];
    cout << "Valor en el índice " << x << ": " << val->valor;

    return 0;
}