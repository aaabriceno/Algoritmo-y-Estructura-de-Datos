#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<class G>
struct CNode
{
    typedef typename G::Edge Edge;
    typedef typename G::N    N;
    
    CNode(N v)
    {   value = v; }
    
    list<Edge*> edges;
    N value;
};

template<class G>
struct CEdge
{
    typedef typename G::Node Node;
    typedef typename G::E    E;
    
    CEdge(Node* a, Node*b, E distancia, E tiempo, bool d)
    {
        nodes[0] = a; nodes[1] = b;
        value[0] = distancia; value[1] = tiempo; dir = d;
        nodes[0]->edges.push_back(this);
        nodes[1]->edges.push_back(this);
    }
    
    ~CEdge()
    {
    }
        
    Node* nodes[2];
    E value[2]; //distancia , tiempo
    bool dir; //0=bidireccional, 1 = nodes[0]=>nodes[1]
};

template<class _N, class _E>
class CGraph
{
public:
    typedef CGraph<_N,_E>   G;
    typedef _N              N;
    typedef _E              E;
    typedef CNode<G>        Node;
    typedef CEdge<G>        Edge;

    bool InsertNode(N n)
    {
        Node* node = new Node(n);
        nodes.push_back(node);
        return 1;
    }
    
    bool InsertEdge(Node* a, Node* b, E dist, E tiempo, bool dir)
    {
        new Edge(a,b,dist, tiempo,dir);
        return 1;
    }
    
    bool RemoveEdge(Node* a, Node* b, E e)
    {
        Edge* edge_a, *edge_b;
        edge_a = RemoveEdgeFromNode(nodes[0], e);
        edge_b = RemoveEdgeFromNode(nodes[1], e);
        assert(edge_a == edge_b);
        delete edge_a;
    }
    
    Edge* RemoveEdgeFromNode(Node* n, E e)
    {
        for ( auto i : n->edges )
            if ( i->value == e )
            {   n->edges.erase(i);
                return *i;
            }
        return 0;
    }
    
    bool RemoveNode(Node* n)
    {
        for ( auto i : n->edges )
            RemoveEdge(i->nodes[0], i->nodes[1], i->value);
        for ( auto ni : nodes )
            if ( *ni == n )
            {
                nodes.erase(ni);
                return 1;
            }
        return 0;
    }

    Node* GetNode(int i)
    {
        return nodes[i];
    }
    
public:
    vector<Node*> nodes;
};

class CCharGraph : public CGraph<char,int>
{
public:
    void  Path()
    {
        //TO DO
    }
};



class CMain{};
int main()
{
    char nodes[11] = {'A','B','C','D','E','F','G','H','I','J','K'};
    CCharGraph g;
    
    for (int i = 0; i < 11; i++)
        g.InsertNode(nodes[i]);
        
    g.InsertEdge(g.GetNode(0), g.GetNode(1), 1, 2, 1);
    g.InsertEdge(g.GetNode(0), g.GetNode(2), 1, 4, 1);
    g.InsertEdge(g.GetNode(1), g.GetNode(2), 3, 5, 1);
    g.InsertEdge(g.GetNode(1), g.GetNode(3), 1, 3, 1);
    g.InsertEdge(g.GetNode(2), g.GetNode(5), 2, 3, 1);
    g.InsertEdge(g.GetNode(2), g.GetNode(9), 4, 2, 1);
    g.InsertEdge(g.GetNode(3), g.GetNode(9), 3, 5, 1);
    g.InsertEdge(g.GetNode(4), g.GetNode(7), 1, 1, 1);
    g.InsertEdge(g.GetNode(4), g.GetNode(8), 2, 1, 1);
    g.InsertEdge(g.GetNode(5), g.GetNode(9), 2, 3, 1);
    g.InsertEdge(g.GetNode(6), g.GetNode(10), 4, 6, 1);
    g.InsertEdge(g.GetNode(7), g.GetNode(6), 1, 1, 1);
    g.InsertEdge(g.GetNode(7), g.GetNode(8), 1, 5, 1);
    g.InsertEdge(g.GetNode(7), g.GetNode(10), 3, 3, 1);
    g.InsertEdge(g.GetNode(8), g.GetNode(10), 2, 2, 1);
    g.InsertEdge(g.GetNode(9), g.GetNode(4), 1, 2, 1);
    g.InsertEdge(g.GetNode(9), g.GetNode(6), 1, 2, 1);

    g.Path();
}
