/*Altura de un arbol*/
#include <iostream>
using namespace std;
struct node {
	int dato;
	node* nodes[2];
	node(int d) { dato = d; nodes[1] = nodes[0] = 0; };
};

void inorder(node* n, int h, int &altura) { // f(h>hm) hm = h;
	if (!n) return;
	inorder(n->nodes[0], h + 1, altura);
	cout << n -> dato;
	inorder(n->nodes[1], h + 1, altura);
}

/*
Primero ver que la cantidad de nodos debe ser balanceado en ambos lados por lo general,
uno: calcular los espacios 
dos: como recorro por niveles el arbol
*/

int h(node* n) {
	if (!n) return 0;
	int l = h(n->nodes[0]); //izquierda
	int r = h(n->nodes[1]); //derecha
	return (l > r ? l : r) + 1;
}


int main() {
	return 0;
}