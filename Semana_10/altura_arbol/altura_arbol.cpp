/*Altura de un arbol*/
#include <iostream>
using namespace std;
struct node {
	int dato;
	node* nodes[2];
	node(int d) { dato = d; nodes[1] = nodes[0] = 0; };
};
/*
void inorder(node* n, int h, int &altura) { // f(h>hm) hm = h;
	if (!n) return;
	inorder(n->nodes[0], h + 1, altura);
	cout << n -> dato;
	inorder(n->nodes[1], h + 1, altura);
}
*/
/*
Primero ver que la cantidad de nodos debe ser balanceado en ambos lados por lo general,
uno: calcular los espacios 
dos: como recorro por niveles el arbol
*/

int altura(node* n) {
	if (!n) return 0;
	int l = altura(n->nodes[0]); //izquierda
	int r = altura(n->nodes[1]); //derecha
	return (l > r ? l : r) + 1;
}


int main() {
    // Crear un árbol de ejemplo con más elementos
    node* raiz = new node(1);
    raiz->nodes[0] = new node(2);
    raiz->nodes[1] = new node(3);
    raiz->nodes[0]->nodes[0] = new node(4);
    raiz->nodes[0]->nodes[1] = new node(5);
    raiz->nodes[1]->nodes[0] = new node(6);
    raiz->nodes[1]->nodes[1] = new node(7);
    raiz->nodes[0]->nodes[0]->nodes[0] = new node(8);
    raiz->nodes[0]->nodes[0]->nodes[1] = new node(9);
    raiz->nodes[0]->nodes[1]->nodes[0] = new node(10);
    raiz->nodes[0]->nodes[1]->nodes[1] = new node(11);

    // Calcular y mostrar la altura del árbol
    cout << "La altura del árbol es: " << altura(raiz) << endl;

    return 0;
}