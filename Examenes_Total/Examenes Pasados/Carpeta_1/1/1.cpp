#include <iostream>
using namespace std;

// Estructura de datos para almacenar nodos de lista de adyacencia
struct Node
{
	int val;
	Node* next;
};

// Estructura de datos para almacenar una arista de grafo
struct Edge {
	int src, dest;
};

class Graph
{
	// Función para asignar un nuevo nodo para la lista de adyacencia
	Node* getAdjListNode(int dest, Node* head)
	{
		Node* newNode = new Node;
		newNode->val = dest;

		// apunta nuevo nodo a la cabeza actual
		newNode->next = head;

		return newNode;
	}

	int N;	// número total de nodos en el grafo

public:

	// Una array de punteros al nodo para representar la
	// lista de adyacencia
	Node** head;

	// Constructor
	Graph(Edge edges[], int n, int N)
	{
		// asignar memoria
		head = new Node * [N]();
		this->N = N;

		// inicializar el puntero de cabeza para todos los vértices
		for (int i = 0; i < N; i++) {
			head[i] = nullptr;
		}

		// agregar aristas al grafo dirigido
		// se insertan aristas de ida y vuelta
		for (unsigned i = 0; i < n; i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			// insertar al principio
			Node* newNode = getAdjListNode(dest, head[src]);

			// apuntar el puntero de la cabeza al nuevo nodo
			head[src] = newNode;

			
			newNode = getAdjListNode(src, head[dest]);

			// cambia el puntero de la cabeza para que apunte al nuevo nodo
			head[dest] = newNode;
			
		}
	}

	// Destructor
	~Graph() {
		for (int i = 0; i < N; i++) {
			delete[] head[i];
		}

		delete[] head;
	}


};

// Función para imprimir todos los vértices vecinos de un vértice dado
void printList(Node* ptr)
{
	while (ptr != nullptr)
	{
		cout << " -> " << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

// Halla todos los recorridos desde el nodo ptr que recorra
// todas las aristas del grafo, sin repetir una arista
// se puede pasar por un nodo mas de una vez
void printTravelEdge(Node* ptr)
{
	// RESOLVER 
	cout << " Imprimir recorridos AQUI " << endl;
}

// Implementación de grafos
int main()
{
	// un array de aristas del grafo según el diagrama
	Edge edges[] =
	{
		// par `(x, y)` representa una arista de `x` a` y`
		{ 0, 1 }, { 0, 2 }, { 1, 2 }, { 1, 3 }, { 1, 4 }, { 2, 4 }, { 3, 4 }
	};

	// número total de nodos en el grafo
	int N = 5;

	// calcula el número total de aristas
	int n = sizeof(edges) / sizeof(edges[0]);

	// construir grafo
	Graph graph(edges, n, N);

	// imprimir la representación de la lista de adyacencia de un grafo
	for (int i = 0; i < N; i++)
	{
		// imprimir el vértice dado
		cout << i << " --";

		// imprime todos sus vértices vecinos
		printList(graph.head[i]);
	}

	//prueba de recorridos de aristas
	for (int i = 0; i < N; i++)
	{
		// imprimir el vértice de inicio
		cout << "Partiendo del nodo " << i << endl;

		// imprime el recorrido de todas las aristas sin repetir
		printTravelEdge(graph.head[i]);
	}

	return 0;
}