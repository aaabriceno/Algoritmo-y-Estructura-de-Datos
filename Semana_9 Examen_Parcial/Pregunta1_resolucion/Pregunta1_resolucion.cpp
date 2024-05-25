/*
Pregunta 1
    En el siguiente código implementa el método ADD y DEL de la clase CircularLinkedList 
    que es una lista circular ordenada.
*/

#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
};

class CircularLinkedList
{
	node* head = NULL;
public:
	void add(int value) {
		node* newNode = new node;
		newNode->data = value;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}

		else if (value <= head->data)
		{
			newNode->next = head->next;
			head->next = newNode;
			swap(head->data, newNode->data);
		}

		else
		{
			node* current = head;
			while (current->next != head && current->next->data < value)
				current = current->next;

			newNode->next = current->next;
			current->next = newNode;
		}
	}

	void del(int value) {
		if (head == nullptr)
			return;

		node* temp = head;
		node* prev = nullptr;


		while (temp->data != value && temp->next != head)
		{
			prev = temp;
			temp = temp->next;
		}


		if (temp->data == value && temp == head)
		{
			if (temp->next == head)
			{
				delete temp;
				head = nullptr;
			}
			else
			{
				prev = head;
				while (prev->next != head)
					prev = prev->next;
				prev->next = head->next;
				delete head;
				head = prev->next;
			}
		}

		else if (temp->data == value)
		{
			prev->next = temp->next;
			delete temp;
		}

	}

	void print()
	{
		int cont = 0;
		node* ptr = head;
		cout << "head->";
		while (head && cont < 1)
		{

			cout << ptr->data << " -> ";
			ptr = ptr->next;
			if (ptr == head) cont++;
		}
		if (head) cout << ptr->data;
		cout << " <- head \n ";

	}
};

int main()
{
	int ADD[10] = { 2,4,6,8,10,1,3,5,7,9 };
	int DEL[10] = { 9,7,5,3,1,10,8,6,4,2 };
	CircularLinkedList CLL;
	for (int i = 0; i < 10; i++) {
		cout << "ADD " << ADD[i] << endl;
		CLL.add(ADD[i]);
		CLL.print();
	}

	for (int i = 0; i < 10; i++) {
		cout << "DEL " << DEL[i] << endl;
		CLL.del(DEL[i]);
		CLL.print();
	}
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
