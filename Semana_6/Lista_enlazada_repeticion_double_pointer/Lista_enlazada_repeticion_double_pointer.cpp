// Lista_enlazada_repeticion_double_pointer.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
using namespace std;

struct nodo_lista {
	int dato; nodo_lista* next;
	nodo_lista(int d) { dato = d; next = 0; }
};

class Clist {
public:
	Clist();bool insertar(int x); bool remover(int x); void print();
private:
	bool buscar(int x, nodo_lista**& p); nodo_lista* head;
};
Clist::Clist() { head = 0; }
bool Clist::buscar(int x, nodo_lista**& p) {
	p = &head;
	while (*p != 0 && (*p)->dato < x){
		p = &((*p)->next);
	}
	return ((*p) != 0 && (*p)->dato == x);
}
bool Clist::insertar(int x) {
	nodo_lista** p; //si lo encuentra el dato
	buscar(x, p);
	nodo_lista* t = *p;
	*p = new nodo_lista(x);
	(*p)->next = t;
	return 1;
}
/*
bool Clist::insertar(int x) {
	nodo_lista** p; //si lo encuentra el dato
	if (buscar(x,p)) {
		nodo_lista* t = new nodo_lista(x);
		(*t)->next ) = *p;
		*p = t;
	}
	else {
		nnodo_lista* t = new nodo_lista(x);
		(*t)->next ) = *p;
		*p = t;
	}
	return 1;
}
*/

bool Clist::remover(int x) {
	nodo_lista** p;
	if (!buscar(x, p)) return 0;
	nodo_lista* t = *p;
	*p = (*p)->next;
	delete t;
	return 1;
}

void Clist::print() {
	for (nodo_lista* t = head; t; t = t->next) {
		cout << t->dato << " ";
	}
	cout << "\n";
}		

int main()
{
	Clist l;
	l.insertar(2);
	l.insertar(3);
	l.insertar(6);
	l.insertar(7);
	l.insertar(5);
	l.insertar(1);
	l.insertar(8);
	l.insertar(2);
	l.insertar(3);
	l.insertar(3);
	l.insertar(3);
	l.insertar(3);
	l.insertar(3);

	l.print();
	l.remover(3);
	l.remover(3);
	l.remover(2);
	l.remover(1);
	l.print();
}
