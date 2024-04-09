#include <iostream>

template <class T>
class Cdeque {
    T* map[11];
    int FRONT=5;
    int BACK=5;
    int front=4;
    int back=5;
    T error=0;
    
public:
    Cdeque<T>() {
        map[5] = new T [10];
    }
    ~Cdeque<T>(){
        while(FRONT <= BACK)
            delete[] map[FRONT++];
    }
    void push_back(T v);
    void push_front(T v);
    T pop_back();
    T pop_front();
    int size();
    T& operator [] (int i);
};

template <class T>
void Cdeque<T>::push_back(T v) {
    if (back <= 9) {
        *(map[BACK] + back++) = v;
    }
    else {
        if (BACK < 10) {
            BACK++;
            back = 0;
            map[BACK] = new T [10];
            *(map[BACK] + back++) = v;
        }
    }
}

template <class T>
void Cdeque<T>::push_front(T v) {
    if (front >= 0) {
        *(map[FRONT] + front--) = v;
    }
    else {
        if (FRONT > 0) {
            FRONT--;
            front = 9;
            map[FRONT] = new T [10];
            *(map[FRONT] + front--) = v;
        }
    }
}

template <class T>
T Cdeque<T>::pop_back() {
    T tmp = error;
    if (BACK != FRONT || back > front+1) {
        if (back != 0)
            tmp = *(map[BACK] + --back);
        else {
            delete[] map[BACK];
            back = 9;
            tmp = *(map[--BACK] + back);
        }
    }
    return tmp;
}

template <class T>
T Cdeque<T>::pop_front() {
    T tmp = error;
    if (BACK != FRONT || back > front+1) {
        if (front != 9)
            tmp = *(map[FRONT]+ ++front);
        else {
            delete[] map[FRONT];
            front = 0;
            tmp = *map[++FRONT];
        }
    }
    return tmp;
}

template <class T>
int Cdeque<T>::size() {
    int tmp;
    int aux = BACK - FRONT;
    if (aux == 0)
        tmp = back - front - 1;
    else {
        tmp = (aux - 1) * 10;
        tmp += 9 - front + back;
    }
    return tmp;
}

template <class T>
T& Cdeque<T>::operator [] (int i) {
    int s = size();
    if (s>i) {
        int aux1, aux2;
        aux1 = i / 10;
        aux2 = i % 10 + front+1;
        if (aux2 < 10)
            return *(map[FRONT + aux1] + aux2);
        else {
            return *(map[FRONT + aux1 + 1] + aux2 - 10);
        }
    }
    return error;
}

int main() {
    Cdeque<int> d1;
    for (int i = 1; i < 13; i++) {
        d1.push_back(i);
        d1.push_front(i);
    }
    int s = d1.size();

    for (int i = 0; i < s; i++)
        std::cout << d1[i] << " ";
    std::cout << "\n";

    for (int i = 0; i < s / 3; i++) {
        std::cout << d1.pop_front() << " ";
        std::cout << d1.pop_back() << " ";
    }
    std::cout << "\n";

    for (int i=0; i<s;i++)
        std::cout << d1[i]<<" ";
    d1[7] = 88;
    std::cout << "\n";

    for (int i = 0; i < s; i++)
        std::cout << d1[i] << " ";

    return 0;
}