#include <iostream>
using namespace std;

int * mid(int * a, int * b){
    return a + (b - a) /2;
}

void busq_bin(int *ini, int *fin, int *& pos, int n){
    if (n < *ini) {
        pos = ini;
        //cout << n << " se insertara al principio del array" << endl;
        return;
    }
    if (n > *fin) {
        pos = fin + 1;
        //cout << n << " se insertara al final del array" << endl;
        return;
    }
    int *medio = mid(ini, fin);
    while (ini <= fin) {
        if (*medio == n) {
            pos = medio; 
            return;
        } else if (*medio < n) {
            ini = medio + 1;
        } else {
            fin = medio - 1;
        }
        medio = mid(ini, fin);
    }
    pos = ini;
    //cout << n << " se insertara entre " << *(ini - 1) << " y " << *ini << endl;
}

bool bin_bus_del(int *ini, int *fin, int *& pos, int n){
    while (ini <= fin) {
        int *medio = mid(ini, fin);
        if (*medio == n) {
            pos = medio; 
            return true;
        } else if (*medio < n) {
            ini = medio + 1; 
        } else {
            fin = medio - 1; 
        }
    }
    //cout << "No se encontro el valor " << n << endl;
    return false; 
}


class elementor{
    int arr[10];
    int tam_arr;
    int tam_act;
    elementor *next;
    int *ini;
    int *fin;
    public:
        void print();
        void insertar_elem(int *&pos, int a);
        void encontrar_arr(elementor *&pos, int a);
        void add(int a);
        void del(int a);
        elementor() : tam_arr(10), tam_act(0), next(nullptr), ini(nullptr), fin(nullptr) {
            for(int * i = arr; i < arr + 10; i++){
                *i = -1;
            }
        }
        ~elementor(){
        }
};

void elementor::print() {
    elementor *act = this;
    while (act) {
        cout << "[ ";
        for (int *p = act->arr; p < act->arr + 10; p++) {
            if (*p == -1) {
                cout << " - ";
            } else {
                cout << *p << " ";
            }
        }   
        cout << " ] -> ";
        cout <<endl;
        act = act->next; // Avanzamos al siguiente elementor
    }
}


void elementor::insertar_elem(int *&pos, int a){
    if (pos == fin && *fin <= a) {
        *fin = a;
    } else {
        for (int *i = fin + 1; i > pos; --i) {
            *i = *(i - 1);
        }
        *pos = a;
    }
    tam_act++;
    fin++;
}

void elementor::encontrar_arr(elementor *&pos, int a) {
    elementor *p = this;
    while (p->next) {
        if (a >= *(p->ini) && a <= *(p->fin)) {
            pos = p;
            return;
        }
        p = p->next;
    }
    pos = p;
}


void elementor::add(int a) {
    elementor *pos = nullptr;
    encontrar_arr(pos, a); 
    if(pos->tam_act < 10){
        if (pos->ini == nullptr) {
            pos->ini = pos->arr;
            *(pos->ini) = a;
            pos->fin = pos->ini;
            pos->tam_act++;
        } else if (pos->ini == pos->fin) {
            if (*(pos->ini) < a) {
                *(pos->ini + 1) = a;
                pos->tam_act++;
                pos->fin++;
            } else {
                *(pos->ini + 1) = *pos->ini;
                *pos->ini = a;
                pos->tam_act++;
                pos->fin++;
            }
        } else {
            int *p = nullptr;
            busq_bin(pos->ini, pos->fin, p, a);
            insertar_elem(p, a);
        }
    } else if (pos->tam_act == 10 && pos->next == nullptr){
        int tmp = *(pos->fin);
        elementor *new_elementor = new elementor();
        new_elementor->ini = new_elementor->arr;
        *(new_elementor->ini) = tmp;
        new_elementor->fin = new_elementor->ini;
        new_elementor->tam_act++;
        new_elementor->next = pos->next;
        pos->next = new_elementor;
        int *p = nullptr;
        busq_bin(ini, fin, p, a);
        for (int *i = fin; i > p; --i) {
            *i = *(i - 1);
        }
        *p = a;
        
    } else if(pos->tam_act == 10 && pos->next != nullptr){
        int tmp = *(pos->fin);
        int *p = nullptr;
        busq_bin(ini, fin, p, a);
        for (int *i = fin; i > p; --i) {
            *i = *(i - 1);
        }
        *p = a;
        pos->next->add(tmp);
    } else if (pos->tam_act < 10 && pos->next == nullptr){
        if (pos->ini == pos->fin) {
            if (*(pos->ini) < a) {
                *(pos->ini + 1) = a;
                pos->tam_act++;
                pos->fin++;
            } else {
                *(pos->ini + 1) = *pos->ini;
                *pos->ini = a;
                pos->tam_act++;
                pos->fin++;
            }
        } else {
            int *p = nullptr;
            busq_bin(pos->ini, pos->fin, p, a);
            insertar_elem(p, a);
        }
    }
}


void elementor::del(int a){
    elementor *pos =nullptr;
    encontrar_arr(pos, a);
    int *p = nullptr;
    if(pos->next == nullptr){
        if(*pos->ini == a){
            //cout << "Eliminando elemento " << *pos->arr << endl;
            for(int *i = pos->arr; i < pos->arr + pos->tam_act; i++){
                *i = *(i + 1);
            }
            pos->tam_act--;
            *(pos->arr +pos-> tam_act) = -1;
            pos->fin--;
        } else if(*pos->fin == a){
            //cout << "Eliminando elemento " << *pos->fin << endl;
            *pos->fin = -1;
            pos->fin--;
            pos->tam_act--;
        } else if(bin_bus_del(pos->ini, pos->fin, p, a)){
            //cout << "Eliminando elemento " << a << endl;
            for(int *i = p; i < p + pos->tam_act; i++){
                *i = *(i + 1);
            }
            pos->tam_act--;
            *(p + pos->tam_act) = -1;
            pos->fin--;
        }
    }else {
        if(*pos->ini == a){
            int tmp = *pos->next->ini;
            //cout << "Eliminando elemento " << *pos->arr << endl;
            for(int *i = pos->arr; i < pos->arr + pos->tam_act; i++){
                *i = *(i + 1);
            }
            *pos->fin = tmp;
            pos->next->del(tmp);
        } else if(*pos->fin == a){
            int tmp = *pos->next->fin;
            //cout << "Eliminando elemento " << *pos->fin << endl;
            *pos->fin = *pos->next->ini;
            pos->next->del(*pos->next->ini);
        } else if(bin_bus_del(pos->ini, pos->fin, p, a)){
            //cout << "Eliminando elemento " << a << endl;
            for(int *i = p; i < p + pos->tam_act; i++){
                *i = *(i + 1);
            }
            pos->tam_act--;
            *(p + pos->tam_act) = -1;
            pos->fin--;
        }
    }
}

int main(){
    elementor e;
    cout << "\nFuncion add"<<endl;
    e.print();
    e.add(6);
    e.print();
    e.add(2);
    e.print();
    e.add(12);
    e.print();
    e.add(0);
    e.print();
    e.add(10);
    e.print();
    e.add(1);
    e.print();
    e.add(9);
    e.print();
    e.add(9);
    e.print();
    e.add(90);
    e.print();
    e.add(912);
    e.print();
    e.add(25);
    e.print();
    e.add(89);
    e.print();
    e.add(6);
    e.print();
    e.add(3);
    e.print();
    e.add(92);
    e.print();
    cout << "\nFuncion del" << endl;
    e.del(25);
    e.print();
    e.del(0);
    e.print();
    e.del(89);
    e.print();
    return 0;
}