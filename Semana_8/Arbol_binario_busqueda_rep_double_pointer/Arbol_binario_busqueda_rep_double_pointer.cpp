#include <iostream>
using namespace std;

struct CbintreeNode {
	int dato;
	int contador;
	CbintreeNode* nodes[2];
	CbintreeNode(int d) {
		dato = d;
		contador = 1;
		nodes[0] = nodes[1] = 0;
	}
};

class Cbintree {
public:
	Cbintree();
	~Cbintree();
	void print();
	bool insertar(int x);
	bool remover(int x);

private:
	void inOrder(CbintreeNode* n);
	bool buscar(int x, CbintreeNode**& p);
	bool bb;
	CbintreeNode* root;
};
Cbintree::Cbintree() {bb = 0;root = 0;}
Cbintree::~Cbintree() {}

bool Cbintree::buscar(int x, CbintreeNode**&p){
	p = &root;
	while ((*p != 0) && (((*p)->dato != x) || (*p)->dato == x)) {
		p = &((*p)->nodes[x > (*p)->dato]);
	}
	return (*p != 0);
}
bool Cbintree::insertar(int x) {
	CbintreeNode** p;
	if (buscar(x, p)) {
		if (*p) {
			CbintreeNode* t = *p;
			*p = new CbintreeNode(x);
			(*p)->nodes[0] = t;
		}
		else {
			*p = new CbintreeNode(x);
		}
		(*p)->contador++;
	}
	else {
		*p = new CbintreeNode(x);
	}
	return 1;
}
/*
bool Cbintree::remover(int x) {

}
*/
void Cbintree::inOrder(CbintreeNode* n) {
	if (!n) return;
	inOrder(n->nodes[0]);
	cout << n->dato << " ";
	inOrder(n->nodes[1]);
}
void Cbintree::print() {
	inOrder(root);
	cout << "\n";
}


int main() {
	Cbintree l;
	l.insertar(12);
	l.insertar(13);
	l.insertar(1);
	l.insertar(3);
	l.insertar(5);
	l.insertar(24);
	l.insertar(12);
	l.insertar(45);
	l.insertar(5);
	l.insertar(45);
	l.insertar(46);
	l.insertar(47);
	l.insertar(4);
	l.print();

	return 0;
}