#include <iostream>
using namespace std;

int main()
{
	int* p = nullptr;

	int x = 2;
	p = &x;
	int** q = &p;

	cout << *q << endl;
	p++;
	cout << p << endl;

	float v[3];
	cout << v << endl;
	v[1] = 99;
	cout << v[1] << endl;
	cout << *(v + 1) << endl;
	cout << "dimensiune " << sizeof(v)/sizeof(float) << endl;

	float* w = (float*)malloc(3 * sizeof(float));
	if (w != nullptr)
	{
		w[1] = 100;
		cout << w[1] << endl;
	}
	//...
	free(w);
	w = nullptr;
	cout << w << endl;
}