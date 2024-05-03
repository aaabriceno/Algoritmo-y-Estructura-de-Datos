#include <iostream>
using namespace std;
struct nodo {
	int arr[5] = { 0,0,0,0,0 };
	nodo* next;
	nodo* prev;
	nodo(nodo* t = 0, nodo* v = 0) {
		next = t;
		prev = v;
	}
};
struct elementor {
	nodo* ini;
	nodo* n_fin=0;
	int* fin=0;
	elementor() {
		ini = new nodo;
		fin = 0;
	}
	~elementor() {
		while (n_fin->prev) {
			n_fin = n_fin->prev;
			delete n_fin->next;
		}
		delete ini;
	}
	bool find(int*& p, nodo*& tmp, int val) {
		p = ini->arr;
		tmp = ini;
		if (*fin < val) {
			if (fin == n_fin->arr + 4) {
				p = n_fin->next->arr;
				tmp = n_fin->next;
			}
			else {
				p = fin + 1;
				tmp = n_fin;
			}
			return 0;
		}

		while (*p < val) {
			if (tmp != n_fin && *(tmp->arr + 4) < val) {
				tmp = tmp->next;
				p = tmp->arr;
			}
			else {
				break;
			}
		}
		while (*p < val) {
			p++;
		}
		return (*p == val);
	}

	void move(int* p, nodo* n_pos, bool direc) {
		if (direc) {
			int owu;
			int ewe = *p;
			while (p != fin)
			{
				if (p != n_pos->arr + 4) {
					owu = *(p + 1);
					*(p + 1) = ewe;
					p++;
					ewe = owu;

				}
				else {
					p = n_pos->next->arr;
					n_pos = n_pos->next; //ojo
					owu = *p;
					*p = ewe;
					ewe = owu;
				}
			}
		}
		else {
			int ewe;
			while (p != fin)
			{
				if (p != n_pos->arr + 4) {
					ewe = *(p + 1);
					*p = ewe;
					p++;
				}
				else {
					n_pos = n_pos->next; //ojo
					ewe = *n_pos->arr;
					*p = ewe;
					p = n_pos->arr;
				}
			}
		}
	}

	void add(int val) {
		if (!fin) {
			ini = new nodo;
			ini->arr[0] = val;
			fin = ini->arr;
			n_fin = ini;
		}
		else {
			if (fin != n_fin->arr + 4) {
				int* p;
				nodo* n_pos;
				if (!find(p, n_pos, val)) {
					fin++;
					if (p == fin) {
						*p = val;
					}
					else {
						move(p, n_pos, 1);
						*p = val;
					}
				}
			}
			else {
				n_fin->next = new nodo(0,n_fin);
				int* p;
				nodo* n_pos;
				if (!find(p, n_pos, val)) {
					n_fin = n_fin->next;
					fin = n_fin->arr;
					if (p == fin) {
						*p = val;
					}
					else {
						move(p, n_pos, 1);
						*p = val;
					}

				}
			}
		}
	}

	void del(int val) {
		if (fin) {
			if (fin != n_fin->arr) {
				int* p;
				nodo* n_pos;
				if (find(p, n_pos, val)) {
					if (p == fin) {
						*p = 0;
					}
					else {
						move(p, n_pos, 0);
					}
					fin--;
				}
			}
			else {
				int* p;
				nodo* n_pos;
				if (find(p, n_pos, val)) {
					if (p == fin) {
						n_fin = n_fin->prev;
						delete n_fin->next;
						n_fin->next = 0;
						fin = n_fin->arr + 4;
					}
					else {
						move(p, n_pos, 0);
						n_fin = n_fin->prev;
						delete n_fin->next;
						n_fin->next = 0;
						fin = n_fin->arr + 4;
					}

				}
			}
		}
	}

	void print() {
		for (nodo** i = &ini; *i; i = &((*i)->next))
		{
			if (*i == n_fin) {
				for (int* o = (*i)->arr; o <= fin; o++)
				{
					cout << *o << " ";
				}
			}
			else {
				for (int o = 0; o < 5; o++)
				{
					cout << (*i)->arr[o] << " ";
				}
			}
			//cout << "  ";
			if ((*i)->next){
				cout << "--> ";
			}
		}
		cout << endl;
	}
};

int main()
{
	elementor prueba;
	prueba.add(0);
	prueba.add(1);
	prueba.add(2);
	prueba.add(3);
	prueba.add(4);
	prueba.add(5);
	prueba.add(5);
	prueba.add(6);
	prueba.add(-7);
	prueba.add(-1);
	prueba.add(20);
	prueba.add(1);
	prueba.add(7);
	prueba.print();
	prueba.del(2);
	prueba.del(0);
	prueba.del(4);
	prueba.print();
}