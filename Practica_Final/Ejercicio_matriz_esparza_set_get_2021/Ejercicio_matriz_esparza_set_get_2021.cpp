#include <iostream>
#include <vector>
#include <list>
#include <utility> // Para std::pair
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
    vector< list< pair<uint, T> > > matrix; // Cambiar a pair para almacenar coordenadas y valores
    uint m_XDim, m_YDim;
};

template <class T, T NE>
CSparseMatrix<T, NE>::CSparseMatrix(uint xdim, uint ydim)
{
    m_XDim = xdim; m_YDim = ydim;
    matrix.resize(m_XDim);
}

template <class T, T NE>
void CSparseMatrix<T, NE>::Set(uint x, uint y, T value)
{
    if (x >= m_XDim || y >= m_YDim) return; // Verificar límites

    auto& row = matrix[x];
    auto it = row.begin();
    while (it != row.end() && it->first < y) ++it;

    if (it != row.end() && it->first == y) {
        if (value == NE) {
            row.erase(it); // Eliminar si el valor es el predeterminado
        }
        else {
            it->second = value; // Actualizar el valor
        }
    }
    else {
        if (value != NE) {
            row.insert(it, { y, value }); // Insertar nuevo valor
        }
    }
}

template <class T, T NE>
typename CSparseMatrix<T, NE>::value_type CSparseMatrix<T, NE>::Get(uint x, uint y)
{
    if (x >= m_XDim || y >= m_YDim) return NE; // Verificar límites

    const auto& row = matrix[x];
    for (const auto& elem : row) {
        if (elem.first == y) return elem.second;
    }
    return NE; // Devolver valor predeterminado si no se encuentra
}

template <class T, T NE>
void CSparseMatrix<T, NE>::Print()
{
    for (uint yi = 0; yi < m_YDim; yi++) // Cambiar a uint para evitar conflictos de signed/unsigned
    {
        for (uint xi = 0; xi < m_XDim; xi++) // Cambiar a uint para evitar conflictos de signed/unsigned
        {
            T value = Get(yi, xi);
            cout << value << " ";
        }
        cout << endl;
    }
    cout << "---" << endl;
}

int main(int argc, const char* argv[])
{
    CSparseMatrix<int, 0> m(5, 5);

    m.Set(0, 0, 2);   m.Set(2, 0, 0);   m.Set(3, 1, 5);
    m.Set(1, 2, 6);   m.Set(2, 2, 7);   m.Set(3, 2, 0);
    m.Set(4, 2, 9);   m.Set(1, 3, 1);   m.Set(0, 4, 0);
    m.Set(3, 4, 8);
    m.Print();

    m.Set(3, 1, 0);   m.Set(1, 2, 0);   m.Set(0, 4, 0);
    m.Set(4, 4, 0);
    m.Print();

    return 0;
}