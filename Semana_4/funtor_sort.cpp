#include <iostream>
#include<chrono>
#include<ctime>
#include <cstdlib>



template <class T>
struct c_greater
{
    bool cmp(T a, T b){
        return a < b;
    }
};

template <class T>  
struct c_less
{
    bool cmp(T a, T b){
        return a > b;
    }
};


void sort(float* arr){
    
}

int main(){
    
        
    return 0;
}
