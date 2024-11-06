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
	string model;
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
		this->model = "Necunoscut";
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
		model = telefon.model;
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

			producator = telefon.producator;
			model = telefon.model;
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

	void setModel(string model)
	{
		if (model.length() >= 2)
		{
			this->model = model;
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


	void incarca(float nivelIncarcare);
};
int TelefonMobil::nrTelefoane = 0;

void TelefonMobil::incarca(float nivelIncarcare)
{
	nivelBaterie += nivelIncarcare;
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

	cout << "Durate zilnice utilizare: ";
	for (int i = 0; i < altTelefon.getNrZile(); i++)
	{
		cout << altTelefon.getDurataZilnicaUtilizare(i) << " ";
	}

	telefonDeServiciu = telefonPersonal = telefon;
}