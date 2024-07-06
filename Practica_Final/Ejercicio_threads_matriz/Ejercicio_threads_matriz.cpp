


///////////////////
#include <iostream>
//cuidar que solo uno escriba al mismo tiempo
//4 threads

//COMPILAR VARIAS VECES PORSEACA <3

#include <thread>
#include <mutex>
using namespace std;
mutex mtx;

int m[10][10] =
{
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,1,0,0,0,0,},
    {0,2,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,1,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,2,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
};

void printm()
{
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        { 
            if ((j == 1 && i == 5) || (j == 2 && i == 1) || (j == 3 && i == 7) || (j == 7 && i == 4))
                cout << "" << m[j][i] << "* ";
            
            else
            {
                if (m[j][i] == 0)
                    std::cout << "  ";
                else
                    std::cout << m[j][i] << "  ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "------------------------------\n";
}
/*
struct c
{
    int x, y;
};
*/
void thread_function(int startX, int endX, int startY, int endY)
{
    int a = 1, b = 9; //
    for (int val = a; val <= b; val++)
    {
        mtx.lock();
        for (int j = startY; j <= endY; j++)
        {
            for (int i = startX; i <= endX; i++)
            {
                if (m[j][i] == val)
                {
                    if (i > 0 && m[j][i - 1] == 0)
                        m[j][i - 1] = val + 1;
                    if (i < 9 && m[j][i + 1] == 0)
                        m[j][i + 1] = val + 1;
                    if (j > 0 && m[j - 1][i] == 0)
                        m[j - 1][i] = val + 1;
                    if (j < 9 && m[j + 1][i] == 0)
                        m[j + 1][i] = val + 1;
                }
            }
        }
        mtx.unlock();
    }
}

void levels()
{
    int tam = 10; //x la matriz
    int inicio = 0, mitad = tam / 2, end = tam - 1;

    thread t1(thread_function, inicio, mitad, inicio, mitad);
    thread t2(thread_function, mitad + 1, end, inicio, mitad);
    thread t3(thread_function, inicio, mitad, mitad + 1, end);
    thread t4(thread_function, mitad + 1, end, mitad + 1, end);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

int main()
{
    printm();
    levels();
    printm();
}

