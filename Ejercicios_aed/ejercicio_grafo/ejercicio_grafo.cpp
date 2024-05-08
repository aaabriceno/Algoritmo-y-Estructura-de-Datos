#include <iostream>
#include<list>
#include <vector>

//referencia porque las dos clases son dependientes entre si
//solucion temporal
//template <class N,class E>
//class CEdge;
//----------------------------------
//si tuviese muchas mas clases, no hay forma de colocarlas y que compile ya que se amarra demasiado
//lo malo no es tener muchas clases
//----------------------------------


template <class G>
class CNode
{
public:
    typedef typename G::N N;
    typedef typename G::Edge Edge;


    N value;
    std::list<Edge*> edges;
};

template <class G>
class CEdge
{
public:
    typedef typename G::E E;
    typedef typename G::Node Node;

    E value;
    Node* nodes[2];
    bool dir;
};

template <class N, class E>
class CGraph
{
public:
    typedef CGraph<N, E> G;
    //typedef CNode<N,E> Node;
    //typedef CEdge<N,E> Edge;
    //esta es mi solucion al error de que si se utilizan demasiadas clases
    typedef CNode<G> Node;
    typedef CEdge<G> Edge;

    //al pasar G, estoy pasando una clase que adentro tiene varios tipos


    bool InsertNode(N v);
    bool InsertEdge(Node* a, Node* b, E e, bool dir);
    bool RemoveNode(N v);
    bool RemoveEdge(Node* a, Node* b, E e);

    std::vector<Node*> nodes;
};

template <class N, class E> bool CGraph<N, E>::InsertNode(N V)
{
    return 0;
}




int main()
{
    //CGraph<char, int> g;
}