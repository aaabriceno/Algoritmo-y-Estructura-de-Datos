#include <iostream> // Para usar cout
#include <cstdlib>  // Para usar nullptr

class piLa
{
private:
    int elem[10];
    int *TOP = nullptr;

public:
    bool push(int a);
    bool pop(int &a);
};

bool piLa::push(int a) {
    if (TOP - elem < 10) {
        *(++TOP) = a;
        return true;
    } else {
        std::cout << "Stack overflow!" << std::endl;
        return false;
    }
}


bool piLa::pop(int &a) {
    if (TOP >= elem) {
        a = *(TOP--);
        return true;
    } else {
        std::cout << "Stack underflow!" << std::endl;
        return false;
    }
}

int main() {
    piLa stack;
    int x;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    while (stack.pop(x)) {
        std::cout << "Popped: " << x << std::endl;
    }

    return 0;
}
