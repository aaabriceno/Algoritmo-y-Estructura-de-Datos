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
	CbintreeNode** reemplazar(CbintreeNode** p);
	bool buscar(int x, CbintreeNode**& p);
	bool buscar_remove(int x, CbintreeNode**& p);
	bool bb;
	CbintreeNode* root;
};
Cbintree::Cbintree() { bb = 0; root = 0; }
Cbintree::~Cbintree() {}

bool Cbintree::buscar(int x, CbintreeNode**& p) {
	p = &root;
	while ((*p != 0) && (((*p)->dato != x) || (*p)->dato == x)) {
		p = &((*p)->nodes[x > (*p)->dato]);
	}
	return (*p != 0);
}
bool Cbintree::buscar_remove(int x, CbintreeNode**& p) {
	p = &root;
	while ((*p != 0) && (((*p)->dato != x)	) {
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
CbintreeNode** Cbintree::reemplazar(CbintreeNode** p){
	CbintreeNode** q;
	int b = bb;
	q = &((*p)->nodes[b]);
	while ((*q)->nodes[!b]) {
		q = &((*q)->nodes[!b]);
	}
	bb = !bb;
	return q;
}

bool Cbintree::remover(int x) {
	CbintreeNode** p;
	if (!buscar_remove(x,p) )return 0;
	/*caso 2; si es que tiene dos hijos*/
	if ((*p)->nodes[0] && (*p)->nodes[1]){
		CbintreeNode** q = reemplazar(p);
		(*p)->dato = (*q)->dato;
		p = q;
	}
	//caso 1.1 - 1.2 si es que tiene un hijo izquierda o derecha
		CbintreeNode* t = *p;

		*p = (*p)->nodes[(*p)->nodes[0] == 0];
		delete t;
		(*p)->contador--;
		return 1;
}

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
	l.insertar(3);
	l.print();

	l.remover(5);
	l.remover(3);
	l.remover(45);
	l.print();

	return 0;
}