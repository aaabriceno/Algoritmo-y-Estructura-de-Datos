#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <class T, T NE>
class CSparseMatrix
{
    typedef unsigned int uint;
    typedef T value_type;
public:
    CSparseMatrix(uint xdim, uint ydim);
    void Set(uint x, uint y, T value);
    T    Get(uint x, uint y);
    void Print();
    
private:
    vector< list<T> > matrix;
    uint m_XDim, m_YDim;
};

template <class T, T NE>
CSparseMatrix<T,NE>::CSparseMatrix(uint xdim, uint ydim)
{
    m_XDim = xdim; m_YDim = ydim;
    matrix.resize(m_XDim);
}

template <class T, T NE>
void CSparseMatrix<T,NE>::Set(uint x, uint y, T value)
{
    
}

template <class T, T NE>
typename CSparseMatrix<T,NE>::value_type CSparseMatrix<T,NE>::Get(uint x, uint y)
{
    return 0;
}

template <class T, T NE>
void CSparseMatrix<T,NE>::Print()
{
    int xi, yi;
    for (yi = 0; yi < m_YDim; yi++)
    {
        for (xi = 0; xi < m_XDim; xi++)
        {
            T value = Get(yi,xi);
            cout<< value<<" ";
        }
        cout<<endl;
    }
    cout<<"---"<<endl;
}


int main(int argc, const char * argv[])
{
    CSparseMatrix<int,0> m(5,5);
    
    m.Set(0,0,2);   m.Set(2,0,0);   m.Set(3,1,5);
    m.Set(1,2,6);   m.Set(2,2,7);   m.Set(3,2,0);
    m.Set(4,2,9);   m.Set(1,3,1);   m.Set(0,4,0);
    m.Set(3,4,8);
    m.Print();
    
    m.Set(3,1,0);   m.Set(1,2,0);   m.Set(0,4,0);
    m.Set(4,4,0);
    m.Print();
    
    return 0;
}
