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