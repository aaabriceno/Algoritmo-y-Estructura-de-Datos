/*Recorrido de arboles*/
#include <iostream>
using namespace std;
/*
	Cabe recalcar que se procesa en un stack, while(mientras la pila no este vacia se
	procesa el tope, se utiliza recursividad, y se procesa el stack, bajo el control del usuario) 
	Se debe trrabajar por estados para que se pueda recorrer el arbol de manera correcta
-	Estado 0: Si el recorrido se hace por primera vez
-	Estado 1: Si ya se bajo por izquierda y regreso al nodo 
-	Estado 2: Si debe bajar por la derecha y regresa al nodo
-	Estado 3: Que se debe sacar

struct  cx{
	cx* n;
	int s;
}
std::stack<cx> s;

std::pair <char,int> uu;
uu first = 'c';
uu second = 7;
std::stack <std::pair<Node*, int>> s; <---- el stack esta basado en un deque :)
s.push ({p,z});


existe tambien --> std::tuple<int , char, float> t;
*/
struct Node {
	int valor;
	Node* nodes[2];
	Node(int v) {
		valor = v;
		nodes[0] = nodes[1] = 0;
	}
};

/*Esta funcion es un stack recursivo automatico a diferencia del caso de arriba*/
void inorder(Node* n) { //metodo in orden tipico 
	if (!n) return;
	inorder(n->nodes[0]);
	cout << n->valor;
	inorder(n->nodes[1]);
}
void preorder(Node* n) { // metodo preorder tipico
	if (!n) return;
	cout << n->valor;
	preorder(n->nodes[0]);
	preorder(n->nodes[1]);
}
void postorder(Node* n) { // metodo postorder tipico
	if (!n) return;
	postorder(n->nodes[0]);
	postorder(n->nodes[1]);
	cout << n->valor;
}

int  main() {

}