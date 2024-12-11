#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int globala = 5;

void functie()
{
	int globala = 3;
	globala++;
	cout << globala << endl;
}

class NullPointerException : public exception
{
public:
	NullPointerException() {}
	NullPointerException(const char* msg) : exception(msg) {}
};

class TelefonMobil
{
private:
	char* model = nullptr;
	int* durataZilnicaUtilizare = nullptr;
	int nrZile = 0;

public:
	const int durataMaximaBaterie;
	string producator;
	float nivelBaterie = 0;
	static int nrTelefoane;

	TelefonMobil() : durataMaximaBaterie(12)
	{
		this->producator = "Necunoscut";
		this->model = new char[strlen("Necunoscut") + 1];
		strcpy_s(this->model, strlen("Necunoscut") + 1, "Necunoscut");
		this->nivelBaterie = 10;
		nrTelefoane++;
	}

	TelefonMobil(int nivelBaterie, int durataMaxima) : durataMaximaBaterie(durataMaxima)
	{
		this->nivelBaterie = nivelBaterie;
		nrTelefoane++;
	}

	TelefonMobil(string producator, int* durataZilnica, int numarZile) : durataMaximaBaterie(12)
	{
		this->producator = producator;
		if (durataZilnica != nullptr && numarZile > 0)
		{
			this->nrZile = numarZile;

			this->durataZilnicaUtilizare = new int[numarZile];
			for (int i = 0; i < numarZile; i++)
			{
				this->durataZilnicaUtilizare[i] = durataZilnica[i];
			}
		}
	}

	TelefonMobil(const TelefonMobil& telefon) : durataMaximaBaterie(telefon.durataMaximaBaterie)
	{
		producator = telefon.producator;
		if (telefon.model != nullptr)
		{
			this->model = new char[strlen(telefon.model) + 1];
			strcpy_s(this->model, strlen(telefon.model) + 1, telefon.model);
		}
		nivelBaterie = telefon.nivelBaterie;
		nrTelefoane++;
		if (telefon.durataZilnicaUtilizare != nullptr && telefon.nrZile > 0)
		{
			this->nrZile = telefon.nrZile;
			this->durataZilnicaUtilizare = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				this->durataZilnicaUtilizare[i] = telefon.durataZilnicaUtilizare[i];
			}
		}
	}

	~TelefonMobil()
	{
		if (durataZilnicaUtilizare != nullptr)
		{
			delete[] durataZilnicaUtilizare;
			durataZilnicaUtilizare = nullptr;
		}
		if (model != nullptr)
		{
			delete[] model;
		}
	}

	TelefonMobil& operator=(const TelefonMobil& telefon)
	{
		if (this != &telefon)
		{
			if (durataZilnicaUtilizare != nullptr)
			{
				delete[] durataZilnicaUtilizare;
				durataZilnicaUtilizare = nullptr;
			}

			if (model != nullptr)
			{
				delete[] model;
				model = nullptr;
			}

			producator = telefon.producator;
			if (telefon.model != nullptr)
			{
				this->model = new char[strlen(telefon.model) + 1];
				strcpy_s(this->model, strlen(telefon.model) + 1, telefon.model);
			}
			nivelBaterie = telefon.nivelBaterie;

			if (telefon.durataZilnicaUtilizare != nullptr && telefon.nrZile > 0)
			{
				this->nrZile = telefon.nrZile;
				this->durataZilnicaUtilizare = new int[nrZile];
				for (int i = 0; i < nrZile; i++)
				{
					this->durataZilnicaUtilizare[i] = telefon.durataZilnicaUtilizare[i];
				}
			}
			else
			{
				this->durataZilnicaUtilizare = nullptr;
				this->nrZile = 0;
			}
		}
		return *this;
	}

	string getModel()
	{
		return model;
	}

	void setModel(const char* model)
	{
		if (model != nullptr)
		{
			if (this->model != nullptr)
			{
				delete[] this->model;
			}
			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);
		}
	}

	int* getDurataZilnicaUtilizare()
	{
		if (durataZilnicaUtilizare != nullptr)
		{
			int* copie = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				copie[i] = durataZilnicaUtilizare[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getDurataZilnicaUtilizare(int index)
	{
		if (index >= 0 && index < nrZile)
		{
			return durataZilnicaUtilizare[index];
		}
		return -1;
	}

	int getNrZile()
	{
		return nrZile;
	}

	void setDurataZilnicaUtilizare(int* durate, int numarZile)
	{
		if (durate != nullptr && numarZile > 0)
		{
			if (this->durataZilnicaUtilizare != nullptr)
			{
				delete[] this->durataZilnicaUtilizare;
			}
			this->nrZile = numarZile;
			this->durataZilnicaUtilizare = new int[numarZile];
			for (int i = 0; i < numarZile; i++)
			{
				this->durataZilnicaUtilizare[i] = durate[i];
			}
		}
	}

	static int getNrTelefoane()
	{
		return nrTelefoane;
	}

	static int setNrTelefoane(int nrTelefoane)
	{
		TelefonMobil::nrTelefoane = nrTelefoane;
	}

	static float nivelMediuBaterie(TelefonMobil* telefoane, int nrTelefoane)
	{
		float suma = 0;
		if (telefoane != nullptr && nrTelefoane > 0)
		{
			for (int i = 0; i < nrTelefoane; i++)
			{
				suma += telefoane[i].nivelBaterie;
			}
			return suma / nrTelefoane;
		}
		return suma;
	}

	bool operator!()
	{
		return nivelBaterie > 0;
	}

	TelefonMobil& operator++()
	{
		this->nivelBaterie++;
		return *this;
	}

	TelefonMobil operator++(int)
	{
		TelefonMobil copie = *this;
		this->nivelBaterie++;
		return copie;
	}

	TelefonMobil operator+(int valoare)
	{
		TelefonMobil copie = *this;
		copie.nivelBaterie += valoare;
		return copie;
	}

	int& operator[](int index)
	{
		if (durataZilnicaUtilizare != nullptr && index >= 0 && index < nrZile)
		{
			return durataZilnicaUtilizare[index];
		}
		if (durataZilnicaUtilizare == nullptr)
		{
			throw NullPointerException();
		}
		if (index < 0 || index >= nrZile)
		{
			throw exception("Index invalid");
		}
	}

	explicit operator int()
	{
		return nivelBaterie;
	}

	void incarca(float nivelIncarcare);

	friend ostream& operator<<(ostream&, TelefonMobil);
	friend istream& operator>>(istream& in, TelefonMobil& t)
	{
		cout << "Producator: ";
		in >> ws;
		getline(in, t.producator);
		char buffer[31];
		cout << "Model: ";
		in >> ws;
		in.getline(buffer, 30);
		t.setModel(buffer);
		cout << "Nivel baterie: ";
		in >> t.nivelBaterie;
		cout << "Nr zile utilizare: ";
		int nrZile = 0;
		in >> nrZile;
		cout << "Durate zilnice utilizare";
		int* durate = new int[nrZile];
		for (int i = 0; i < nrZile; i++)
		{
			cout << "Ziua " << (i + 1) << ": ";
			in >> durate[i];
		}
		t.setDurataZilnicaUtilizare(durate, nrZile);
		delete[] durate;
		return in;
	}

	friend ofstream& operator<<(ofstream& f, TelefonMobil m)
	{
		f.write((char*)&m.nivelBaterie, sizeof(m.nivelBaterie));
		int dimensiune = (m.model != nullptr) ? strlen(m.model) : 0;
		f.write((char*)&dimensiune, sizeof(dimensiune));

		if (dimensiune > 0)
		{
			f.write(m.model, dimensiune + 1);
		}
		f.write((char*)&m.nrZile, sizeof(m.nrZile));

		if (m.nrZile > 0)
		{
			for (int i = 0; i < m.nrZile; i++)
			{
				f.write((char*)&m.durataZilnicaUtilizare[i],
					sizeof(m.durataZilnicaUtilizare[i]));
			}
		}

		dimensiune = m.producator.length();
		f.write((char*)&dimensiune, sizeof(dimensiune));
		f.write(m.producator.c_str(), dimensiune + 1);

		return f;
	}

	friend ifstream& operator>>(ifstream& f, TelefonMobil& m)
	{
		f.read((char*)&m.nivelBaterie, sizeof(m.nivelBaterie));
		int dimensiune = 0;
		f.read((char*)&dimensiune, sizeof(dimensiune));

		if (dimensiune > 0)
		{
			delete[] m.model;
			m.model = new char[dimensiune + 1];
			f.read(m.model, dimensiune + 1);
		}
		f.read((char*)&m.nrZile, sizeof(m.nrZile));

		if (m.nrZile > 0)
		{
			delete[] m.durataZilnicaUtilizare;
			m.durataZilnicaUtilizare = new int[m.nrZile];
			for (int i = 0; i < m.nrZile; i++)
			{
				f.read((char*)&m.durataZilnicaUtilizare[i],
					sizeof(m.durataZilnicaUtilizare[i]));
			}
		}

		dimensiune = 0;
		f.read((char*)&dimensiune, sizeof(dimensiune));
		char* prod = new char[dimensiune + 1];
		f.read(prod, dimensiune + 1);
		m.producator = prod;
		delete[] prod;
		prod = nullptr;

		return f;
	}
};
int TelefonMobil::nrTelefoane = 0;

void TelefonMobil::incarca(float nivelIncarcare)
{
	nivelBaterie += nivelIncarcare;
}

TelefonMobil operator+(int valoare, TelefonMobil t)
{
	t.nivelBaterie += valoare;
	return t;
}

ostream& operator<<(ostream& out, TelefonMobil t)
{
	out << "Producator: " << t.producator << endl;
	out << "Model: " << ((t.model != nullptr) ? t.model : "") << endl;
	out << "Durata maxima baterie: " << t.durataMaximaBaterie << endl;
	out << "Nivel baterie: " << t.nivelBaterie << endl;
	out << "Nr zile utilizare: " << t.nrZile << endl;
	out << "Durate zilnice utilizare: ";
	if (t.durataZilnicaUtilizare != nullptr)
	{
		for (int i = 0; i < t.nrZile; i++)
		{
			out << t.durataZilnicaUtilizare[i] << " ";
		}
	}
	out << endl;
	return out;
}

class TelefonMobilPliabil : public TelefonMobil
{
private:
	int* diagonalaEcrane = nullptr;
	int nrEcrane = 0;

public:
	TelefonMobilPliabil()
	{
		diagonalaEcrane = new int[1];
		nrEcrane = 1;
		diagonalaEcrane[0] = 9;
	}

	TelefonMobilPliabil(int nivelBaterie, int durataMaxima, int* diagonale, 
		int nrEcrane) : TelefonMobil(nivelBaterie, durataMaxima)
	{
		if (diagonale != nullptr && nrEcrane > 0)
		{
			diagonalaEcrane = new int[nrEcrane];
			this->nrEcrane = nrEcrane;
			for (int i = 0; i < nrEcrane; i++)
			{
				diagonalaEcrane[i] = diagonale[i];
			}
		}
	}

	TelefonMobilPliabil(const TelefonMobilPliabil& t) : TelefonMobil(t)
	{
		if (t.diagonalaEcrane != nullptr && t.nrEcrane > 0)
		{
			nrEcrane = t.nrEcrane;
			diagonalaEcrane = new int[nrEcrane];
			for (int i = 0; i < nrEcrane; i++)
			{
				diagonalaEcrane[i] = t.diagonalaEcrane[i];
			}
		}
	}

	TelefonMobilPliabil& operator=(const TelefonMobilPliabil& t)
	{
		TelefonMobil::operator=(t);
		//(TelefonMobil)*this = (TelefonMobil)t;
		if (this != &t)
		{
			if (diagonalaEcrane != nullptr)
			{
				delete[] diagonalaEcrane;
			}
			if (t.diagonalaEcrane != nullptr && t.nrEcrane > 0)
			{
				nrEcrane = t.nrEcrane;
				diagonalaEcrane = new int[nrEcrane];
				for (int i = 0; i < nrEcrane; i++)
				{
					diagonalaEcrane[i] = t.diagonalaEcrane[i];
				}
			}
			else
			{
				diagonalaEcrane = nullptr;
				nrEcrane = 0;
			}
		}
		return *this;
	}

	~TelefonMobilPliabil()
	{
		if (diagonalaEcrane != nullptr)
		{
			delete[] diagonalaEcrane;
		}
	}

	friend ostream& operator<<(ostream& out, TelefonMobilPliabil t);
	friend istream& operator>>(istream& in, TelefonMobilPliabil& t);
};

ostream& operator<<(ostream& out, TelefonMobilPliabil t)
{
	out << (TelefonMobil)t;
	out << "Nr ecrane: " << t.nrEcrane << endl;
	out << "Diagonale: ";
	if (t.diagonalaEcrane != nullptr && t.nrEcrane > 0)
	{
		for (int i = 0; i < t.nrEcrane; i++)
		{
			out << t.diagonalaEcrane[i] << " ";
		}
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, TelefonMobilPliabil& t)
{
	in >> (TelefonMobil&)t;
	//...
	return in;
}

int main()
{
	TelefonMobil telefonPersonal;
	TelefonMobil telefonDeServiciu(50, 10);

	telefonPersonal.producator = "Samsung";
	telefonPersonal.nivelBaterie = 20;
	telefonPersonal.incarca(50);
	cout << telefonPersonal.nivelBaterie << endl;

	TelefonMobil* pTelefonMobil = new TelefonMobil(70, 10);
	cout << (*pTelefonMobil).nivelBaterie << endl;
	pTelefonMobil->incarca(10);
	cout << pTelefonMobil->nivelBaterie << endl;
	delete pTelefonMobil;
	pTelefonMobil = nullptr;

	//TelefonMobil altTelefon = 15;
	//TelefonMobil t1 = altTelefon;

	cout << telefonPersonal.getModel() << endl;

	cout << globala << endl;
	functie();
	cout << globala << endl;

	cout << "Nr tel: " << TelefonMobil::nrTelefoane << endl;

	TelefonMobil vector[]{ telefonPersonal, telefonDeServiciu };
	float medie = TelefonMobil::nivelMediuBaterie(vector, 2);
	cout << "medie: " << medie << endl;

	int durate[3]{ 6, 8, 4 };
	TelefonMobil telefon("Nokia", durate, 3);

	TelefonMobil altTelefon = telefon;
	int* durateZilnice = altTelefon.getDurataZilnicaUtilizare();
	//...
	delete[] durateZilnice;

	int durateNoi[2]{ 10, 12 };
	altTelefon.setDurataZilnicaUtilizare(durateNoi, 2);

	telefonDeServiciu.setModel("14 Pro");

	cout << "Durate zilnice utilizare: ";
	for (int i = 0; i < altTelefon.getNrZile(); i++)
	{
		cout << altTelefon.getDurataZilnicaUtilizare(i) << " ";
	}

	telefonDeServiciu = telefonPersonal = telefon;

	cout << endl;
	telefonDeServiciu.incarca(20);
	cout << !telefonDeServiciu;
	//cout << telefonDeServiciu.operator!();
	TelefonMobil t5 = ++telefonDeServiciu;
	TelefonMobil t6 = telefonDeServiciu++;
	TelefonMobil t7 = telefonDeServiciu + 8;
	TelefonMobil t8 = 8 + telefonDeServiciu;
	cout << telefonDeServiciu << telefonPersonal;

	TelefonMobil t9;
	//ifstream g("telefon.txt");
	//g >> t9;
	//g.close();
	ofstream f("telefon.txt");
	f << t9;
	f.close();

	telefonDeServiciu[1] = 17;
	cout << telefonDeServiciu[1] << endl;

	int nivelBaterie = (int)telefonDeServiciu;
	cout << nivelBaterie << endl;

	TelefonMobilPliabil tp;
	t9 = tp;
	TelefonMobilPliabil tp2 = tp;
	TelefonMobilPliabil tp3;
	tp3 = tp2;

	cerr << !tp << endl;

	int diagonale[]{ 9, 7 };
	TelefonMobilPliabil tp4(100, 24, diagonale, 2);
	cout << tp4;

	try
	{
		cout << tp4[1] << endl;
	}
	catch (int errorCode)
	{
		cout << errorCode;
	}
	catch (NullPointerException& e)
	{
		cout << "NULL pointer" << endl;
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	catch (...)
	{
		cout << "eroare necunoscuta";
	}

	int x = 15;
	cout << hex << x << endl;
	cout << oct << x << endl;
	float y = 5.123456;
	cout << setprecision(3) << y << endl;
	cout << setw(3) << left << setfill('$') << dec << x << endl;

	telefonPersonal.setModel("14 Pro");

	ofstream file("telefon.bin", ios::binary | ios::app);
	file << telefonPersonal;
	file.close();

	TelefonMobil t10;
	ifstream g("telefon.bin", ios::binary);
	g >> t10;
	g.close();
}