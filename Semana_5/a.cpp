#include <iostream>
using namespace std;

struct Cola {
  int A[10];
  int *head = nullptr;
  int *tail = nullptr;
  bool push(int v);
  bool pop(int &v);
  void print();
};

bool Cola::push(int v) {
  if (tail == nullptr) {
    tail = A;
    head = A;
    *tail = v;
    tail++;
    return true;
  }
  if (tail == A + 10 && head != A) {
    tail = A;
    *tail = v;
    tail++;
    return true;
  }
  if (tail == A + 10 && head == A) {
    return false;
  } 
  else {
    *tail = v;
    tail++;
    return true;
  }
}

bool Cola::pop(int &v) {
  if (head == nullptr) {
    return false;
  }
  if(head == A + 10 && tail != A + 10){
    head = A;
    v = *head;
    return true;
  }
  if(tail == A + 10 && head == A + 10){
    return false;
  }
  if(tail == head){
    return false;
  }
  else {
    v = *head;
    head++;
    return true;
  }
}

int main(){
  Cola c;
  for(int i = 0; i < 10; i++){
    c.push(i);
  }
  int elemet = 0;
  c.pop(elemet); 
  c.pop(elemet);
  c.pop(elemet);
  c.pop(elemet);
  c.pop(elemet);
  c.pop(elemet);
  c.pop(elemet);
  c.pop(elemet);
  c.pop(elemet);
  c.pop(elemet);
  c.pop(elemet);
  c.push(10);
  c.pop(elemet);
  c.print();
  
}