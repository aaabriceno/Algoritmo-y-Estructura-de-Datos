#include <iostream>
using namespace std;
struct CbintreeNode {
	int dato;
	int cant;
	CbintreeNode* nodes[2];
	CbintreeNode(int d)
	{
		dato = d;
		cant = 1;
		nodes[0] = nodes[2] = 0;
	}
};

class Cbintree_rep {
public:
	Cbintree_rep();
	~Cbintree_rep();
	bool insertar(int x);
	bool remover(int x);
	void print();
private:
	bool buscar(int x, CbintreeNode**& p);
	CbintreeNode** Reemplazo(CbintreeNode** p);
	bool bb;
	Cbintree_rep* root;
	void Inorden(CbintreeNode* p);

};

Cbintree_rep::Cbintree_rep() {
	bb = 0;
	root = 0;
}
Cbintree_rep::~Cbintree_rep() {
	//
}
bool Cbintree_rep::buscar(int x, CbintreeNode**& p) {
	p = &root;
	while ((*p) && ((*p)-> dato != x)||((*p)-> dato == x) {

	}
}
bool Cbintree_rep::insertar(int x) {

}
CbintreeNode** Cbintree_rep::Reemplazo(CbintreeNode** p) {

}
bool Cbintree_rep::remover(int x) {

}
void Cbintree_rep::print() {

}
void Cbintree_rep::Inorden(CbintreeNode* p) {

}


int main() {
	Cbintree_rep arbol;
	arbol.insertar(12);
	arbol.insertar(2);
	arbol.insertar(13);
	arbol.insertar(15);
	arbol.insertar(0);
	arbol.insertar(4);
}