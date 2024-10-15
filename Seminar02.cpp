#include <iostream>
#include <string>
using namespace std;

void afisare(int x) {
	cout << x << endl;
}

int main() {
	int x = 2;
	int* p = nullptr;
	p = &x;
	cout << p << endl;

	afisare(*p);

	int* q = ++p;
	cout << q << endl;
	q = q + 3;
	cout << q << endl;

	cout << q - p << endl;
	cout << sizeof(q) << endl;

	p--;
	void* t = p;
	cout << *((int*)t) << endl;

	int& r = x;
	x++;
	cout << r << endl;

	const unsigned int dimensiune = 5;
	int v[dimensiune]{ 1, 2, 3, 4, 5 };
	cout << v << endl;
	cout << v[3] << endl;

	cout << sizeof(v) / sizeof(int) << endl;

	unsigned int dim = 5;
	int* w = new int[dim];
	w[1] = 99;
	delete[] w;
	w = nullptr;

	char s[20];
	strcpy_s(s, "Ana");
	cout << s << endl;
	cout << strlen(s) << endl;

	char* sir = new char[strlen(s) + 1];
	strcpy_s(sir, strlen(s) + 1, s);
	cout << sir << endl;
	delete[] sir;
	sir = nullptr;

	string nume = "Daniel";
	cout << "Nume: " + nume << endl;
	nume = s;
	cout << nume << endl;
	const char* n = nume.c_str();
}