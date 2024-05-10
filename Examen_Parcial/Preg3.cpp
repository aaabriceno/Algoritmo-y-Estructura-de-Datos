#include <iostream>

class XVector
{
public:
    XVector(int size_map, int size_vec);
    ~XVector();
    //push_back
    //push_front
    //operator[]
    int** map;
    int size_map, size_vec;
};

XVector::XVector(int sm, int sv)
{
    size_map = sm;
    size_vec = sv;
    
}

XVector::~XVector()
{}

void print( XVector* p)
{ //no modificar esta función
    for ( int i = 0; i < p->size; i++ )
        std::cout<<(*p)[i]<<" ";
    std::cout<<"\n";
}

int main()
{
    //no modificar esta función main
    XVector v(4,3);
    v.push_back(3); v.push_back(8); v.push_back(1);
    v.push_back(4); v.push_back(9); v.push_back(6);
    v.push_back(7);
    print(&v);
    v.push_front(5); v.push_front(2);
    print(&v);
    v.push_front(11); v.push_front(17);
    v.push_back(22);
    print(&v);
    v.push_front(33); v.push_back(77);
    print(&v);
}
