// CicrcularLinkedList.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int v, node* n = nullptr) {
        data = v;
        next = n;
    }
};

class CircularLinkedList
{
    node* head = NULL;
    //node** start = nullptr;
public:


    void add(int value)
    {
        //TO DO
        
        if (head == nullptr) {
            head = new node(value);
            head->next = head;
            return;
        }

        node** current = &head->next;

        if (value < head->data) {
            while (*current != head) {
                current = &(*current)->next;
            }
            *current = new node(value, *current);
            head = *current;
            return;
        }

        while (value > (*current)->data && *current != head) {
            current = &(*current)->next;
        }
        *current = new node(value, *current);
        return;
    }

    void del(int value)
    {
        // TO DO

        if (head == head->next) {
            delete head;
            head = nullptr;
            return;
        }

        node** current = &head->next;
        
        while (value != (*current)->data && *current != head) {
            current = &(*current)->next;
        }

        if ((*current)->data == value) {
            node* tmp = *current;
            *current = (*current)->next;
            if (head == tmp)
                head = head->next;
            delete tmp;
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
    for (int i = 0; i < 10; i++)
    {
        cout << "ADD " << ADD[i] << endl;
        CLL.add(ADD[i]);
        CLL.print();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "DEL " << DEL[i] << endl;
        CLL.del(DEL[i]);
        CLL.print();
    }
}