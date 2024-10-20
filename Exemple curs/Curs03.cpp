#include <iostream>
using namespace std;

void modifica(int** v)
{
	int* new_vector = new int[3];
	new_vector[0] = (*v)[0];
	new_vector[1] = (*v)[1];
	new_vector[2] = 300;
	delete[] * v;
	*v = new_vector;
}

int main()
{
	int a = 99;
	int& r = a;
	a++;
	cout << r << endl;
	r = 23;
	cout << a << endl;

	int* vector = new int[2];
	vector[0] = 100;
	vector[1] = 200;
	modifica(&vector);
	cout << vector[0] << endl;
	cout << vector[1] << endl;
	cout << vector[2] << endl;
}