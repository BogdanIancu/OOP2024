#include <iostream>
using namespace std;

float pretInvalid = 0;

class Masina
{
private:
	string producator;
	string model;
	int anFabricatie;
	float pret;
	float* preturiDotariExtra = nullptr;
	int numarDotariExtra = 0;
	const int serie;
	static string normaPoluare;

public:
	Masina() : serie(-1)
	{
		anFabricatie = 1900;
		this->pret = 100;
	}

	Masina(int serie, float pret, float* preturiDotari, int numarDotari) : serie(serie)
	{
		this->pret = pret;
		this->anFabricatie = 1900;
		if (preturiDotari != nullptr && numarDotari > 0)
		{
			this->numarDotariExtra = numarDotari;
			this->preturiDotariExtra = new float[numarDotari];
			for (int i = 0; i < numarDotari; i++)
			{
				this->preturiDotariExtra[i] = preturiDotari[i];
			}
		}
	}

	Masina(string producator, string model, int anFabricatie, int serieSasiu) : serie(serieSasiu)
	{
		this->producator = producator;
		this->model = model;
		this->anFabricatie = anFabricatie;
		this->pret = 200;
	}

	Masina(const Masina& m) : serie(m.serie)
	{
		this->producator = m.producator;
		this->model = m.model;
		this->anFabricatie = m.anFabricatie;
		this->pret = m.pret;
		if (m.preturiDotariExtra != nullptr && m.numarDotariExtra > 0) {
			this->numarDotariExtra = m.numarDotariExtra;
			this->preturiDotariExtra = new float[m.numarDotariExtra];
			for (int i = 0; i < numarDotariExtra; i++) {
				this->preturiDotariExtra[i] = m.preturiDotariExtra[i];
			}
		}
	}

	~Masina()
	{
		if (preturiDotariExtra != nullptr)
		{
			delete[] preturiDotariExtra;
		}
	}

	Masina& operator=(const Masina& m)
	{
		if (this != &m)
		{
			if (preturiDotariExtra != nullptr)
			{
				delete[] preturiDotariExtra;
			}

			this->producator = m.producator;
			this->model = m.model;
			this->anFabricatie = m.anFabricatie;
			this->pret = m.pret;
			if (m.preturiDotariExtra != nullptr && m.numarDotariExtra > 0) {
				this->numarDotariExtra = m.numarDotariExtra;
				this->preturiDotariExtra = new float[m.numarDotariExtra];
				for (int i = 0; i < numarDotariExtra; i++) {
					this->preturiDotariExtra[i] = m.preturiDotariExtra[i];
				}
			}
			else
			{
				this->numarDotariExtra = 0;
				this->preturiDotariExtra = nullptr;
			}
		}
		return *this;
	}

	float getPret()
	{
		return pret;
	}

	float* getPreturiDotariExtra()
	{
		if (preturiDotariExtra != nullptr && numarDotariExtra > 0)
		{
			float* copie = new float[numarDotariExtra];
			for (int i = 0; i < numarDotariExtra; i++)
			{
				copie[i] = preturiDotariExtra[i];
			}
			return copie;
		}
		return nullptr;
	}

	int getNumarDotariExtra()
	{
		return numarDotariExtra;
	}

	float getPreturiDotariExtra(int index) 
	{
		if (index >= 0 && index < numarDotariExtra) {
			return preturiDotariExtra[index];
		}
		return 0;
	}

	void setPreturiDotariExtra(float* preturi, int nrPreturi)
	{
		if (preturi != nullptr && nrPreturi > 0) {
			if (preturiDotariExtra != nullptr) {
				delete[] preturiDotariExtra;
			}
			numarDotariExtra = nrPreturi;
			preturiDotariExtra = new float[nrPreturi];
			for (int i = 0; i < nrPreturi; i++) {
				preturiDotariExtra[i] = preturi[i];
			}
		}
	}

	void setPret(float pretNou)
	{
		if (pretNou >= 0)
		{
			pret = pretNou;
		}
	}

	bool operator!()
	{
		return (preturiDotariExtra != nullptr);

	}

	Masina& operator++()
	{
		pret = pret + 100;
		return *this;
	}

	Masina operator++(int)
	{
		Masina copie = *this;
		this->pret += 100;
		return copie;
	}

	Masina operator*(float valoare)
	{
		Masina copie = *this;
		copie.pret = copie.pret * valoare;
		return copie;
	}

	explicit operator int()
	{
		return anFabricatie;
	}

	float& operator[](int i)
	{
		if (this->preturiDotariExtra != nullptr &&
			i >= 0 && i < numarDotariExtra)
		{
			return this->preturiDotariExtra[i];
		}
		throw exception("Index invalid!");
	}

	static string getNormaPoluare() 
	{
		return normaPoluare;
	}

	static void setNormaPoluare(string normaPoluare)
	{
		Masina::normaPoluare = normaPoluare;
	}

	static double valoareFlota(Masina* masini, int nrMasini) 
	{
		double valoare = 0;
		if (masini != nullptr) {
			for (int i = 0; i < nrMasini; i++) {
				valoare += masini[i].pret;
			}
		}
		return valoare;
	}

	string getModel();
	friend Masina operator*(float valoare, Masina m);
	friend ostream& operator<<(ostream& out, Masina m);
	friend istream& operator>>(istream& in, Masina& m);
};
string Masina::normaPoluare = "euro 6";

string Masina::getModel() 
{
	return model;
}

Masina operator*(float valoare, Masina m)
{
	m.pret = m.pret * valoare;
	return m;
}
ostream& operator<<(ostream& out, Masina m)
{
	out << "Serie: " << m.serie << endl;
	out << "Producator: " << m.producator << endl;
	out << "Model: " << m.model << endl;
	out << "An fabricatie: " << m.anFabricatie << endl;
	out << "Pret: " << m.pret << endl;
	out << "Nr dotari extra: " << m.numarDotariExtra << endl;
	out << "Preturi dotari extra: ";
	for (int i = 0; i < m.numarDotariExtra; i++)
	{
		out << m.preturiDotariExtra[i] << " ";
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Masina& m)
{
	cout << "Producator: ";
	in >> m.producator;
	cout << "Model: ";
	in >> m.model;
	cout << "An fabricatie: ";
	in >> m.anFabricatie;
	cout << "Pret: ";
	in >> m.pret;
	cout << "Nr dotari extra: ";
	in >> m.numarDotariExtra;
	if (m.preturiDotariExtra != nullptr)
	{
		delete[] m.preturiDotariExtra;
	}
	m.preturiDotariExtra = new float[m.numarDotariExtra];
	cout << "Preturi dotari extra: ";
	for (int i = 0; i < m.numarDotariExtra; i++)
	{
		in >> m.preturiDotariExtra[i];
	}
	return in;
}

class MasinaElectrica : public Masina
{
private:
	int capacitateBaterie;
	char* producatorBaterie = nullptr;

public:
	MasinaElectrica()
	{
		capacitateBaterie = 0;
	}

	MasinaElectrica(string producator, string model, int capacitateBaterie, const char* producatorBaterie) :Masina(producator, model, 2020, 777)
	{
		this->capacitateBaterie = capacitateBaterie;
		if (producatorBaterie != nullptr) 
		{
			this->producatorBaterie = new char[strlen(producatorBaterie) + 1];
			strcpy_s(this->producatorBaterie, strlen(producatorBaterie) + 1, producatorBaterie);
		}
	}

	~MasinaElectrica() 
	{
		if (producatorBaterie != nullptr) 
		{
			delete[]producatorBaterie;
		}
	}

	MasinaElectrica(const MasinaElectrica& m) :Masina(m) 
	{
		capacitateBaterie = m.capacitateBaterie;
		if (m.producatorBaterie != nullptr)
		{
			producatorBaterie = new char[strlen(m.producatorBaterie) + 1];
			strcpy_s(producatorBaterie, strlen(m.producatorBaterie) + 1, m.producatorBaterie);
		}
	}

	MasinaElectrica& operator=(const MasinaElectrica& m)
	{
		if (this != &m)
		{
			Masina::operator=(m);
			if (producatorBaterie != nullptr)
			{
				delete[]producatorBaterie;
			}
			capacitateBaterie = m.capacitateBaterie;
			if (m.producatorBaterie != nullptr) 
			{
				producatorBaterie = new char[strlen(m.producatorBaterie) + 1];
				strcpy_s(producatorBaterie, strlen(m.producatorBaterie) + 1, m.producatorBaterie);
			}
			else
			{
				producatorBaterie = nullptr;
			}
		}
		return *this;

	}

	friend ostream& operator<<(ostream& out, MasinaElectrica m);
	friend istream& operator>>(istream& in, MasinaElectrica& m);
};

ostream& operator<<(ostream& out, MasinaElectrica m)
{
	out << (Masina)m;
	out << "Capacitate baterie: " << m.capacitateBaterie << endl;
	if (m.producatorBaterie != nullptr)
	{
		out << "Producator baterie: " << m.producatorBaterie << endl;
	}
	return out;
}

istream& operator>>(istream& in, MasinaElectrica& m)
{
	in >> (Masina&)m;
	cout << "Capacitate baterie: ";
	in >> m.capacitateBaterie;
	char buffer[250];
	cout << "Producator baterie: ";
	in >> buffer;
	if (m.producatorBaterie != nullptr)
	{
		delete[] m.producatorBaterie;
	}
	m.producatorBaterie = new char[strlen(buffer) + 1];
	strcpy_s(m.producatorBaterie, strlen(buffer) + 1, buffer);
	return in;
}

int main()
{
	Masina m1;
	Masina m2("Mercedes", "CLA", 2015, 1111);
	Masina m3(m2);
	Masina m4 = m3;

	cout << m2.getModel() << endl;
	m1.setPret(1000);
	cout << m1.getPret() << endl;

	cout << Masina::getNormaPoluare() << endl;
	Masina::setNormaPoluare("euro 7");
	cout << m4.getNormaPoluare() << endl;

	Masina vectorMasini[2]{ m1, m2 };
	cout << Masina::valoareFlota(vectorMasini, 2) << endl;

	float vector[3]{ 100.5,220.7,350.2 };
	Masina m5(123, 20000, vector, 3);
	vector[0] = 300;

	float* preturi = m5.getPreturiDotariExtra();
	cout << "preturi: ";
	for (int i = 0; i < m5.getNumarDotariExtra(); i++)
	{
		cout << preturi[i] << " ";
	}
	cout << endl;
	delete[] preturi;
	preturi = nullptr;
	float* valoriDotari = new float[2] {700.99, 500.91};
	m5.setPreturiDotariExtra(valoriDotari, 2);
	delete[] valoriDotari;
	valoriDotari = nullptr;
	cout << m5.getPreturiDotariExtra(1);
	cout << endl;
	Masina m6 = m5;
	m1 = m2 = m5;
	m1.operator=(m2.operator=(m5));

	cout << !m5 << endl;
	cout << !m3 << endl;
	Masina m7 = ++m5;
	cout << m7.getPret() << ' ' << m5.getPret() << endl;
	Masina m8 = m5++;
	cout << m8.getPret() << ' ' << m5.getPret() << endl;
	Masina m9 = m5 * 2;
	cout << m9.getPret() << ' ' << m5.getPret() << endl;
	Masina m10 = 2 * m5;
	cout << m10.getPret() << ' ' << m5.getPret() << endl;
	int an = (int)m10;
	cout << an << endl;
	m10[1] = 123.456;
	cout << m10[1] << endl;
	cin >> m10;
	cout << m10;

	MasinaElectrica e1;
	m10 = e1;

	MasinaElectrica e2("Dacia", "Spring", 30, "Panasonic");
	MasinaElectrica e3(e2);
	e1 = e3;

	cin >> e1;
	cout << e1;

	try
	{
		cout << e1[1] << endl;
	}
	catch (exception e)
	{
		cout << e.what();
	}
	catch (...)
	{
		cout << "A aparut o eroare" << endl;
	}
}