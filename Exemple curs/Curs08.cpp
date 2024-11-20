#include <iostream>
using namespace std;

int globala = 5;

void functie()
{
	int globala = 3;
	globala++;
	cout << globala << endl;
}

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
		throw exception("Index invalid");
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
		in >> t.producator;
		char buffer[31];
		cout << "Model: ";
		in >> buffer;
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
	cin >> t9;
	cout << t9;

	telefonDeServiciu[1] = 17;
	cout << telefonDeServiciu[1] << endl;

	int nivelBaterie = (int)telefonDeServiciu;
	cout << nivelBaterie;
}