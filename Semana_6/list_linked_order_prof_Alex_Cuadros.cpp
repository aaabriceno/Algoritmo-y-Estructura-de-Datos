#include <iostream>
struct CNode
{
    CNode(int v)
    {   value = v; next = 0;    }
    int value;
    CNode* next;
};

class COrderedList
{
public:
    COrderedList();
    void Print();
    bool Insert(int x);
    bool Remove(int x);
private:
    bool Find(int x, CNode**& p);
    CNode* head;
};

COrderedList::COrderedList()
{   head = 0;   }

bool COrderedList::Find(int x, CNode**& p)
{
    for ( p = &head; 
          *p != 0 && (*p)->value < x;
         p = &((*p)->next) );
    return *p != 0 && (*p)->value == x;
}

/*
 bool COrderedList::Find(int x, CNode**& p)
 {
     p = &head;
     while (*p != 0 && (*p)->value < x )
         p = &((*p)->next);
     return *p != 0 && (*p)->value == x;
 }
 */

bool COrderedList::Insert(int x)
{
    CNode** p;
    if ( Find(x,p) ) return 0;
    CNode* t = new CNode(x);
    t->next = *p;
    *p = t;
    return 1;
}
    
bool COrderedList::Remove(int x)
{
    CNode** p;
    if ( !Find(x,p) ) return 0;
    CNode* t = *p;
    *p = t->next;
    delete t;
    return 1;
}

void COrderedList::Print()
{
    for ( CNode* t = head; t ; t = t->next )
        std::cout<<t->value<<" ";
    std::cout<<"\n";
}

int main()
{
    COrderedList l;
    l.Insert(22);
    l.Insert(11);
    l.Insert(4);
    l.Insert(17);
    l.Print();
    l.Remove(33);
    l.Remove(17);
    l.Remove(22);
    l.Remove(4);
    l.Remove(11);
    l.Print();
}
