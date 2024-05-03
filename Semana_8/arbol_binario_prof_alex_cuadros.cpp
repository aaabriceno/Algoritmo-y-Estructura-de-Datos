#include <iostream>
struct CBinTreeNode
{
    CBinTreeNode(int v)
    {
        value = v;
        nodes[0] = nodes[1] = 0;
    }
    CBinTreeNode* nodes[2];
    int value;
};

class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    void Print();
    bool Insert(int x);
    bool Remove(int x);
private:
    bool Find(int x, CBinTreeNode**& p);
    CBinTreeNode** Rep(CBinTreeNode** p);
    void InOrder(CBinTreeNode* n);
    CBinTreeNode* root;
    bool bb;
};

CBinTree::CBinTree()
{   
    root = 0;
    bb = 0;
}

CBinTree::~CBinTree()
{   //...
}


bool CBinTree::Find(int x, CBinTreeNode**& p)
{
    for ( p = &root; *p && (*p)->value != x;
         p = &((*p)->nodes[ x > (*p)->value ]) );
    return *p != 0;
}
/*
 bool CBinTree::Find(int x, CBinTreeNode**& p)
 {
     p = &root;
     while ( *p && (*p)->value != x )
         p = &((*p)->nodes[ x > (*p)->value ]);
     return *p != 0;
 }

 */

bool CBinTree::Insert(int x)
{
    CBinTreeNode** p;
    if ( Find(x,p) ) return 0;
    *p = new CBinTreeNode(x);
    return 1;
}
    
bool CBinTree::Remove(int x)
{
    CBinTreeNode** p;
    if ( !Find(x,p) ) return 0;
    // case 2
    if ( (*p)->nodes[0] && (*p)->nodes[1] )
    {
        CBinTreeNode** q = Rep(p);
        (*p)->value = (*q)->value;
        p = q;
    }
    // case 0, 1
    CBinTreeNode* t = *p;
    *p = (*p)->nodes[ (*p)->nodes[0] == 0 ];
    delete t;
    return 1;
}

CBinTreeNode** CBinTree::Rep(CBinTreeNode** p)
{
    CBinTreeNode** q;
    int b = bb;
    for ( q = &((*p)->nodes[b]);
         (*q)->nodes[!b] != 0;
         q = &((*q)->nodes[!b]) );
    bb = !bb;
    return q;
}

/*
 CBinTreeNode** CBinTree::Rep(CBinTreeNode** p)
 {
     CBinTreeNode** q;
     int b = bb;
     q = &((*p)->nodes[b]);
     while ( (*q)->nodes[!b] != 0 )
         q = &((*q)->nodes[!b]);
     bb = !bb;
     return q;
 }

 */

void CBinTree::InOrder(CBinTreeNode* n)
{
    if ( !n ) return;
    InOrder( n->nodes[0] );
    std::cout<<n->value<<" ";
    InOrder( n->nodes[1] );
}

void CBinTree::Print()
{
    InOrder(root);
    std::cout<<"\n";
}

int main()
{
    CBinTree t;
    t.Insert(51);
    t.Insert(33);
    t.Insert(11);
    t.Insert(42);
    t.Insert(77);
    t.Insert(61);
    t.Insert(84);
    t.Insert(36);
    t.Insert(65);
    t.Print();
    std::cout<<"case0 (65)=> "; t.Remove(65); t.Print();
    std::cout<<"case2 (51), case1 (42) => "; t.Remove(51); t.Print();
    std::cout<<"case2 (42), case0 (61) => "; t.Remove(42); t.Print();
    std::cout<<"case1 (77) => "; t.Remove(77); t.Print();
    std::cout<<"case2 (33), case0 (36) => "; t.Remove(33); t.Print();
    std::cout<<"case1 (36) => "; t.Remove(36); t.Print();
    std::cout<<"case0 (11) => "; t.Remove(11); t.Print();
    std::cout<<"case1 (61) => "; t.Remove(61); t.Print();
    std::cout<<"case0 (84) => "; t.Remove(84); t.Print();
}
