/*Lista enlazada con array dentro ordenado entre todos los elementos agregados y eliminados*/
#include <iostream>
using namespace std;

struct nodo {
    int arr[10] ; //Tamaño 10 del array
    nodo* next;
    nodo* prev;
    nodo(nodo* t = nullptr, nodo* v = nullptr) {
        next = t;
        prev = v;
    }
};

struct elementor {
    nodo* ini;
    nodo* n_fin = nullptr;
    int* fin = nullptr;
    elementor();
    ~elementor();
    bool find(int*& p, nodo*& tmp, int val);
    void mover(int* p, nodo* n_pos, bool direc);
    void add(int val);
    void del(int val);
    void print();
};

elementor::elementor() {
    ini = new nodo;
    fin = nullptr;
}

elementor::~elementor() {
    while (n_fin->prev) {
        n_fin = n_fin->prev;
        delete n_fin->next;
    }
    delete ini;
}

bool elementor::find(int*& p, nodo*& tmp, int val) {
    p = ini->arr;
    tmp = ini;
    if (fin && *fin < val) {
        if (fin == n_fin->arr + 9) {
            p = n_fin->next->arr;
            tmp = n_fin->next;
        }
        else {
            p = fin + 1;
            tmp = n_fin;
        }
        return false;
    }

    while (*p < val) {
        if (tmp != n_fin && *(tmp->arr + 9) < val) {
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

void elementor::mover(int* p, nodo* n_pos, bool direc) {
    if (direc) {
        int owu;
        int ewe = *p;
        while (p != fin)
        {
            if (p != n_pos->arr + 9) {
                owu = *(p + 1);
                *(p + 1) = ewe;
                p++;
                ewe = owu;

            }
            else {
                p = n_pos->next->arr;
                n_pos = n_pos->next;
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
            if (p != n_pos->arr + 9) {
                ewe = *(p + 1);
                *p = ewe;
                p++;
            }
            else {
                n_pos = n_pos->next;
                ewe = *n_pos->arr;
                *p = ewe;
                p = n_pos->arr;
            }
        }
    }
}

void elementor::add(int val) {
    if (!fin) {
        ini = new nodo;
        ini->arr[0] = val;
        fin = ini->arr;
        n_fin = ini;
    }
    else {
        if (fin != n_fin->arr + 9) {
            int* p;
            nodo* n_pos;
            if (!find(p, n_pos, val)) {
                fin++;
                if (p == fin) {
                    *p = val;
                }
                else {
                    mover(p, n_pos, true);
                    *p = val;
                }
            }
        }
        else {
            n_fin->next = new nodo(nullptr, n_fin);
            int* p;
            nodo* n_pos;
            if (!find(p, n_pos, val)) {
                n_fin = n_fin->next;
                fin = n_fin->arr;
                if (p == fin) {
                    *p = val;
                }
                else {
                    mover(p, n_pos, true);
                    *p = val;
                }

            }
        }
    }
}

void elementor::del(int val) {
    if (fin) {
        if (fin != n_fin->arr) {
            int* p;
            nodo* n_pos;
            if (find(p, n_pos, val)) {
                if (p == fin) {
                    *p = 0;
                }
                else {
                    mover(p, n_pos, false);
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
                    n_fin->next = nullptr;
                    fin = n_fin->arr + 9;
                }
                else {
                    mover(p, n_pos, false);
                    n_fin = n_fin->prev;
                    delete n_fin->next;
                    n_fin->next = nullptr;
                    fin = n_fin->arr + 9;
                }

            }
        }
    }
}

void elementor::print() {
    for (nodo** i = &ini; *i; i = &((*i)->next))
    {
        cout << "[";
        if (*i == n_fin) {
            for (int* o = (*i)->arr; o <= fin; o++)
            {
                cout << *o << " ";
            }
        }
        else {
            for (int o = 0; o < 10; o++)
            {
                cout << (*i)->arr[o] << " ";
            }
        }
        if ((*i)->next) {
            cout << "] --> ";
        }
        
    }
    cout << "]";
    cout << endl;
}

int main()
{
    elementor e;
    cout << "Agregar elementos a la lista: "<< endl;
    /*
    e.add(0);
    e.add(1);
    e.add(2);
    e.add(3);
    e.add(4);
    e.add(15);
    e.add(5);
    e.add(6);
    e.add(-7);
    e.add(-1);
    e.add(20);
    e.add(13);
    e.add(71);
    e.add(12);
    e.add(16);
    e.add(19);
    e.add(21);
    e.add(8);
    e.print();
    */
    
    /*
    e.del(2);
    e.del(0);
    e.del(4);
    e.print();
    */

   for(int i = 100; i <= 500; i++){
        e.add(i);
   }
   e.print();
    cout << "\nEliminar elementos a la lista: "<< endl;
   for (int i = 100; i <= 500; i++){
    if(i % 2){
        e.del(i);
    }
   }
   e.print();
}
