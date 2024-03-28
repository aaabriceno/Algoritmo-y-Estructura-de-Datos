/*
Hacer un vector
*/

#include <iostream>
using namespace std;

struct Cvector {
	int* arr = nullptr;
	int* head = nullptr;
	int* tail = nullptr;
	int tam = 5;
	int elemt = 0;
	void pushfront(int val);
	void pushback(int val);
	void popfront();
	void popback();
	void rescribir(int newtam);
	void print();
	int& operator[](int val);
};

void Cvector::rescribir(int newtam) {
	int* newarr = new int[newtam];
	int av = 0;
	int* ini = head;
	int* fin = tail;
	for (; ini <= fin; ini++, av++) {
		*(ini + av) = *(newarr + av);
	}

	delete[] arr;
	arr = newarr;
	tam = newtam;
	head = arr;
	tail = arr + av;
	av = 0;

};

void Cvector::pushfront(int val) {
	if (arr == nullptr) {
		arr = new int[tam];
		head = arr;
		tail = arr;
		*head = val;
		elemt++;
		return;
	}
	if (tail == arr + elemt) {
		rescribir(tam * 2);

	}

	for (int i = elemt; *(head + i) != *head; i--) {
		*(head + i) = *(head - 1 + i);

	}
	*head = val;
	tail++;
	elemt++;


}

void Cvector::pushback(int val) {
	if (arr == nullptr) {
		arr = new int[tam];
		head = arr;
		tail = arr;
		*head = val;
		elemt++;
		return;
	}
	if (tail == arr + elemt) {
		rescribir(tam * 2);

	}
	arr[elemt++] = val;
	tail++;
}

void Cvector::popfront() {
	int* ini = head;
	for (; ini < tail; ini++) {
		*ini = *(ini + 1);
	}
	*tail = NULL;
	elemt--;
	tail--;


}

void Cvector::popback() {
	*tail = NULL;
	elemt--;
	tail--;
}

void Cvector::print() {
	for (int* ini = head; ini <= tail; ini++) {
		cout << *ini << " ";
	}
}

int& Cvector::operator[](int val) {
	int i = 0;
	for (; i < val; i++);
	return arr[i];
}


int main() {
	Cvector vec;
	for (int i = 0; i < 8; i++) {
		vec.pushfront(i);
	}


	for (int i = 20; i < 24; i++) {
		vec.pushback(i);
	}



	vec.print();


	cout << endl;

	vec.popfront();

	vec.print();


	vec.popback();

	cout << endl;
	vec.print();

	int a = vec[4];
	cout << a;
}