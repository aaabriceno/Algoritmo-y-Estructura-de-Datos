/*
*/

#include <iostream>
using namespace std;

class piLa
{
    int elem[10];
    int *TOP = NULL;
    bool push(int a);
    bool pop(int &a);
};

bool pila::push(int a)
{
    if (TOP - elem < 10)
    {
        *(+TOP) = a;
        
    }
}

int main()
{

};