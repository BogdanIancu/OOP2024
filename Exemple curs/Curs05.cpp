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

	TelefonMobil(const TelefonMobil& telefon) : durataMaximaBaterie(telefon.durataMaximaBaterie)
	{
		producator = telefon.producator;
		model = telefon.model;
		nivelBaterie = telefon.nivelBaterie;
		nrTelefoane++;
	}

	~TelefonMobil()
	{
		cout << "apel destructor" << endl;
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
}