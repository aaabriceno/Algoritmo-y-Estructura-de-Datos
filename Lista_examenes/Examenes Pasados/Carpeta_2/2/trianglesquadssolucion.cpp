#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<class G>
struct CNode{
    typedef typename G::Edge Edge;
    typedef typename G::N    N;

    CNode(N v){
        value = v;
    }

    list<Edge*> edges;
    N value;
};

template<class G>
struct CEdge
{
    typedef typename G::Node Node;
    typedef typename G::E    E;

    CEdge(Node* a, Node* b, E e, bool d)
    {
        nodes[0] = a; nodes[1] = b;
        value = e; dir = d;
        nodes[0]->edges.push_back(this);
        nodes[1]->edges.push_back(this);
    }

    ~CEdge()
    {
    }

    Node* nodes[2];
    E value;
    bool dir; //0=bidireccional, 1 = nodes[0]=>nodes[1]
};

template<class _N, class _E>
class CGraph{
public:
    typedef CGraph<_N, _E>   G;
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

    bool InsertEdge(Node* a, Node* b, E e, bool dir)
    {
        new Edge(a, b, e, dir);
        return 1;
    }

    bool RemoveEdge(Node* a, Node* b, E e)
    {
        Edge* edge_a, * edge_b;
        edge_a = RemoveEdgeFromNode(nodes[0], e);
        edge_b = RemoveEdgeFromNode(nodes[1], e);
        assert(edge_a == edge_b);
        delete edge_a;
    }

    Edge* RemoveEdgeFromNode(Node* n, E e)
    {
        for (auto i : n->edges)
            if (i->value == e)
            {
                n->edges.erase(i);
                return *i;
            }
        return 0;
    }

    bool RemoveNode(Node* n)
    {
        for (auto i : n->edges)
            RemoveEdge(i->nodes[0], i->nodes[1], i->value);
        for (auto ni : nodes)
            if (*ni == n)
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

class CCharGraph : public CGraph<char, int>
{
public:
    int TriangleCounting(){
        vector<vector<char>> triangulos;
        int nods =0;
        while (nods!=nodes.size()){
            for (auto p = nodes[nods]->edges.begin(); p != nodes[nods]->edges.end(); ++p) {
                Node* a;
                Node* b;
                Node* a1;
                if (nodes[nods] == (*p)->nodes[0]) {
                    b = (*p)->nodes[1];
                    a1= (*p)->nodes[0];
                } 
                else {
                    b = (*p)->nodes[0];
                    a1= (*p)->nodes[1];
                }

                for (auto q = b->edges.begin(); q != b->edges.end(); ++q) {

                    Node* c;
                    if (b == (*q)->nodes[0]) c = (*q)->nodes[1];
                    else c = (*q)->nodes[0];
                    for (auto w = nodes[nods]->edges.begin(); w != nodes[nods]->edges.end(); ++w) {
                        if (nodes[nods] == (*w)->nodes[0]) {
                            a = (*w)->nodes[1];
                        }
                        else a = (*w)->nodes[1];
                        if (a == c) {
                            vector<char> tri = { a1->value,b->value,c->value };
                            vector<char> tri1 = { a1->value,c->value,b->value };
                            vector<char> tri2 = { b->value,a1->value,c->value };
                            vector<char> tri3 = { b->value,c->value,a1->value };
                            vector<char> tri4 = { c->value,a1->value,b->value };
                            vector<char> tri5 = { c->value,b->value,a1->value };
                            bool pasa = 0;
                            for (int i = 0; i != triangulos.size(); i++) {
                                if (triangulos[i] == tri || triangulos[i] == tri1 || triangulos[i] == tri2 || triangulos[i] == tri3 || triangulos[i] == tri4 || triangulos[i] == tri5) {
                                    pasa = 1;
                                }
                            }
                            if (pasa == 0) {
                                triangulos.push_back(tri);
                            }
                        }
                    }
                }
            }
            nods++;
        }
        for (int i = 0;i<triangulos.size(); i++) {
            bool fas = 1;
            while (fas == 1) {
                if (i == triangulos.size()) {
                    fas = 0;
                }
                else if (triangulos[i][0] == triangulos[i][1] || triangulos[i][0] == triangulos[i][2] || triangulos[i][1] == triangulos[i][2]) {
                    triangulos.erase(triangulos.begin() + i);
                }
                else {
                    fas = 0;
                }
            }
        }
        return triangulos.size();
    }

    int QuadCounting(){
        vector<vector<char>> cuadrados;
        int nods = 0;
        while (nods != nodes.size()) {
            for (auto p = nodes[nods]->edges.begin();p!=nodes[nods]->edges.end(); ++p) {
                Node* a, * b;
                if (nodes[nods] == (*p)->nodes[0]) {
                    b = (*p)->nodes[1]; a = (*p)->nodes[0];
                }
                else {
                    b = (*p)->nodes[0]; a = (*p)->nodes[1];
                }
                Node* c, * d;
                
                for (auto q = a->edges.begin(); q != a->edges.end(); ++q) {
                    if (a == (*q)->nodes[1]) {
                        c = (*q)->nodes[0];
                    }
                    else {
                        c = (*q)->nodes[1];
                    }
                    for (auto e = b->edges.begin(); e != b->edges.end(); ++e) {
                        if (b == (*e)->nodes[0]) d = (*e)->nodes[1];
                        else d = (*e)->nodes[0];
                        for (auto w = c->edges.begin(); w != c->edges.end(); ++w) {
                            if (((*w)->nodes[0] == d || (*w)->nodes[1] == d) && a->value!=b->value && a->value != c->value && a->value != d->value && b->value != c->value && b->value != d->value && d->value != c->value) {
                                vector<char> tetra = {a->value,b->value, c->value, d->value};
                                bool pasa = 0;
                                for (int i = 0;i<cuadrados.size(); i++) {
                                    if (cuadrados[i] == tetra) pasa = 1;
                                }
                                if (pasa == 0) {
                                    cuadrados.push_back(tetra);
                                }
                            }
                        }
                    }
                }
            }
            nods++;
        }
        for (int j = 0;j<cuadrados.size();j++) {
            vector<char> pri = cuadrados[j];
            char a = pri[0], b = pri[1],c = pri[2],d = pri[3];
            vector<char> ga = {a,b,d,c};
            vector<char> ga1 = { a,d,b,c };
            vector<char> ga2 = { a,d,c,b };
            vector<char> ga3 = { a,c,d,b };
            vector<char> ga4 = { a,c,b,d };
            vector<char> ga5 = { b,a,d,c };
            vector<char> ga6 = { b,a,c,d };
            vector<char> ga7 = { b,c,d,a };
            vector<char> ga8 = { b,c,a,d };
            vector<char> ga9 = { b,d,a,c };
            vector<char> ga10 = { b,d,c,a };
            vector<char> ga11 = { c,b,a,c };
            vector<char> ga12= { c,b,c,a };
            vector<char> ga13 = { c,a,d,b };
            vector<char> ga14 = { c,a,b,d };
            vector<char> ga15 = { c,d,b,a };
            vector<char> ga16 = { c,d,a,b };
            vector<char> ga17 = { d,b,a,c };
            vector<char> ga18 = { d,b,c,a };
            vector<char> ga19 = { d,a,b,c };
            vector<char> ga20 = { d,a,c,b };
            vector<char> ga21 = { d,c,b,a };
            vector<char> ga22 = { d,c,a,b };
            int i = 0;
            while (i+1 != cuadrados.size()) {
                if (cuadrados[i+1] == ga || cuadrados[i+1] == ga1 || cuadrados[i+1] == ga2 || cuadrados[i+1] == ga3 || cuadrados[i+1] == ga4 || cuadrados[i+1] == ga5 || cuadrados[i+1] == ga6 || cuadrados[i+1] == ga7 || cuadrados[i+1] == ga8 || cuadrados[i+1] == ga9 || cuadrados[i+1] == ga10 || cuadrados[i+1] == ga11 || cuadrados[i+1] == ga12 || cuadrados[i+1] == ga13 || cuadrados[i+1] == ga14 || cuadrados[i+1] == ga15 || cuadrados[i+1] == ga16 || cuadrados[i+1] == ga17 || cuadrados[i+1] == ga18 || cuadrados[i+1] == ga19 || cuadrados[i+1] == ga20 || cuadrados[i+1] == ga21 || cuadrados[i+1] == ga22) {
                    cuadrados.erase(cuadrados.begin()+i+1);
                }
                else i++;
            }
        }
        return cuadrados.size();
    }
};


int main(){
    char nodes[12] = { 'A','B','C','D','E','F','G','H','I','J','K','L' };
    CCharGraph g;

    for (int i = 0; i < 12; i++)
        g.InsertNode(nodes[i]);

    g.InsertEdge(g.GetNode(1), g.GetNode(0), 1, 0);            g.InsertEdge(g.GetNode(4), g.GetNode(0), 1, 0); g.InsertEdge(g.GetNode(5), g.GetNode(0), 1, 0);
    g.InsertEdge(g.GetNode(2), g.GetNode(1), 1, 0);            g.InsertEdge(g.GetNode(5), g.GetNode(1), 1, 0);
    g.InsertEdge(g.GetNode(3), g.GetNode(2), 1, 0);            g.InsertEdge(g.GetNode(6), g.GetNode(2), 1, 0);
    g.InsertEdge(g.GetNode(6), g.GetNode(3), 1, 0);    g.InsertEdge(g.GetNode(7), g.GetNode(3), 1, 0);
    g.InsertEdge(g.GetNode(5), g.GetNode(4), 1, 0);            g.InsertEdge(g.GetNode(8), g.GetNode(4), 1, 0);
    g.InsertEdge(g.GetNode(6), g.GetNode(5), 1, 0);            g.InsertEdge(g.GetNode(9), g.GetNode(5), 1, 0);    g.InsertEdge(g.GetNode(10), g.GetNode(5), 1, 0);
    g.InsertEdge(g.GetNode(7), g.GetNode(6), 1, 0);            g.InsertEdge(g.GetNode(10), g.GetNode(6), 1, 0);
    g.InsertEdge(g.GetNode(11), g.GetNode(7), 1, 0);
    g.InsertEdge(g.GetNode(9), g.GetNode(8), 1, 0);
    g.InsertEdge(g.GetNode(10), g.GetNode(9), 1, 0);
    g.InsertEdge(g.GetNode(11), g.GetNode(10), 1, 0);

    std::cout << "\nTriangles: " << g.TriangleCounting();
    std::cout << "\nQuads: " << g.QuadCounting();
}
