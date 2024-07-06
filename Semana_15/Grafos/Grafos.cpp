//Implementacion de un grafo

#include <iostream>
#include<forward_list>
#include <vector>


/*debemos usar templates*/
using namespace std;

struct Cedge {
	Cedge(int id = -1, int v = 0) {
		id_node = id;
		valor = v;
	}
	int id_node;
	int valor;
};

struct Cnode {
	Cnode(int id = -1, int v = 0) {
		id_node = id;
		valor = v;
	}
	int id_node	;
	char valor;
	forward_list <Cedge> edges;
};

//template <class T>   //template para que el grafo pueda ser de cualquier tipo
// Cgraph <char, int> g ;
//Cgraph <coord,int> g;  grafo de una ciudad
class Cgraph {
public:
	void InsertNode(char v);
	void InsertEdge(int idn1, int idn2, int v);
	void RemNode(char v); //implementar
	void RemEdge(int idn1, int idn2, int v); //implementar
	void print();
	vector <Cnode> nodes;
};

void Cgraph::InsertNode(char v) {
	Cnode n(nodes.size(), v);
	nodes.push_back(n);
}
void Cgraph::RemNode(char v) {
	// Encontrar el nodo a eliminar
	auto it = find_if(nodes.begin(), nodes.end(), [v](const Cnode& node) {
		return node.valor == v;
		});

	if (it != nodes.end()) {
		int id = it->id_node;

		// Eliminar todas las aristas que apuntan al nodo
		for (auto& node : nodes) {
			node.edges.remove_if([id](const Cedge& edge) {
				return edge.id_node == id;
				});
		}

		// Eliminar el nodo
		nodes.erase(it);

		// Actualizar los IDs de los nodos restantes
		for (size_t i = 0; i < nodes.size(); ++i) {
			nodes[i].id_node = i;
		}

		// Actualizar los IDs de las aristas
		for (auto& node : nodes) {
			for (auto& edge : node.edges) {
				if (edge.id_node > id) {
					edge.id_node--;
				}
			}
		}
	}
}

void Cgraph::RemEdge(int idn1, int idn2, int v) {
	if (idn1 < nodes.size()) {
		nodes[idn1].edges.remove_if([idn2, v](const Cedge& edge) {
			return edge.id_node == idn2 && edge.valor == v;
			});
	}
}

void Cgraph::InsertEdge(int idn1, int idn2, int v) {
	Cedge e(idn2,v);
	nodes[idn1].edges.push_front(e);
}

void Cgraph::print() {
	for (auto n : nodes)
	{
		cout << n.valor << " ";
		for (auto e : n.edges)
			cout <<" -> " << nodes[e.id_node].valor << "." << e.valor;
		cout << endl;
	}

}

int main()
{
	Cgraph g;
	g.InsertNode('A');
	g.InsertNode('B');
	g.InsertNode('C');
	g.InsertNode('D');
	g.InsertNode('X');

	g.InsertEdge(0, 1, 3); g.InsertEdge(0, 2, 7); //A
	g.InsertEdge(1, 3, 4); g.InsertEdge(1, 2, 2); //B
	g.InsertEdge(2, 3, 1); g.InsertEdge(2, 4, 5); //C
	
	cout << "Grafo original:" << endl;
	g.print();

	g.RemNode('C');
	cout << "\nGrafo despues de eliminar el nodo 'C':" << endl;
	g.print();

	g.RemEdge(0, 1, 3);
	cout << "\nGrafo despues de eliminar la arista de 'A' a 'B' con valor 3:" << endl;
	g.print();
	return 0;
}