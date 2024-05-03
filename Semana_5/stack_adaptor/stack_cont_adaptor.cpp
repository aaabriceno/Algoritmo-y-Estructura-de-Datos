#include <iostream>
#include <cstdlib>
#include <ctime>
#include "c_array.hpp"
#include "c_vector.hpp"
#include "c_deque.hpp"
#include "c_linked_list.hpp"

using namespace std;
template <class Conteiner = Cvector>
class stack_adaptor{
    Conteiner conteiner;
    bool push(int x);
    bool  pop(int &x);
    void print();

};