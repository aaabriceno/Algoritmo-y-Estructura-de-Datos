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
    bool Find(int x, CNode**& p);
    bool Insert(int x);
    bool Remove(int x);
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

int  main() //Al comienzo era void main(){} solo que el compilador de VsCode no me deja
{
    COrderedList l;
    l.Remove(12);
    l.Remove(1);
    l.Remove(11);
    l.Remove(0);
    l.Remove(21);
    l.Remove(7);
    l.Remove(3);

}
