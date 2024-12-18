#include <iostream>
using namespace std;

class Comparabil
{
public:
	virtual string getUniqueId() = 0;
	virtual bool operator<(Comparabil* c) = 0;
};

class Animal : public Comparabil
{
public:
	int varsta = 0;
	char* nume = nullptr;

	virtual void scoateSunet() = 0;

	virtual ~Animal()
	{
		cout << "Destructor Animal" << endl;
	}

	bool operator<(Comparabil* c) override
	{
		if (c->getUniqueId() == this->getUniqueId())
		{
			Animal* a = (Animal*)c;
			return this->varsta < a->varsta;
		}
		else throw exception("Cannot compare two different datatypes");
	}

	string getUniqueId() override
	{
		return "Animal";
	}
};

class Caine : public Animal
{
public:
	char* rasa = nullptr;

	void scoateSunet() override
	{
		cout << "Ham-ham" << endl;
	}

	~Caine()
	{
		cout << "Destructor caine" << endl;
	}
};

class Pisica : public Animal
{
public:
	void scoateSunet() override
	{
		cout << "Miau" << endl;
	}
};

class Rata : public Animal
{
public:
	void scoateSunet()
	{
		cout << "Mac-mac" << endl;
	}
};

class Masina : public Comparabil
{
public:
	double capacitateCilindrica = 1000;

	bool operator<(Comparabil* c) override
	{
		Masina* m = (Masina*)c;
		return this->capacitateCilindrica < m->capacitateCilindrica;
	}

	string getUniqueId() override
	{
		return "Masina";
	}
};

int main()
{
	Animal** vector = new Animal* [3];
	vector[0] = new Caine();
	vector[0]->varsta = 2;
	vector[1] = new Pisica();
	vector[1]->varsta = 3;
	vector[2] = new Rata();

	cout << (*(vector[0]) < vector[1]) << endl;

	Masina m;
	m.capacitateCilindrica = 1999;

	//cout << (*(vector[0]) < &m) << endl;

	for (int i = 0; i < 3; i++)
	{
		vector[i]->scoateSunet();
	}

	for (int i = 0; i < 3; i++)
	{
		delete vector[i];
	}
	delete[] vector;
	vector = nullptr;

	//cout << sizeof(Animal) << endl;
}