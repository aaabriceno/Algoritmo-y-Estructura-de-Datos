#include <iostream>
using namespace std;

struct Cnode{
    Cnode** p;
    bool t;
};

class Linked_list{
    public:
        Cnode** p;
        bool find(int n, Cnode** &p);
        bool insert(int x);
        bool remove(int x);
};

bool Linked_list::find(int n, Cnode** &p){

}
bool Linked_list::insert(int x){

}
bool Linked_list::remove(int x){

}

int main(){
    Linked_list l;
    return 0;
}