#include <iostream>
using namespace std;

class TelefonMobil
{
public:
	string producator;
	float nivelBaterie = 0;

	TelefonMobil()
	{
		producator = "Necunoscut";
		model = "Necunoscut";
		nivelBaterie = 10;
	}

	TelefonMobil(int baterie)
	{
		nivelBaterie = baterie;
	}

	TelefonMobil(const TelefonMobil& telefon)
	{
		producator = telefon.producator;
		model = telefon.model;
		nivelBaterie = telefon.nivelBaterie;
	}

	~TelefonMobil()
	{
		cout << "apel destructor" << endl;
	}

	void incarca(float nivelIncarcare)
	{
		nivelBaterie += nivelIncarcare;
	}

private:
	string model;
};

int main()
{
	TelefonMobil telefonPersonal;
	TelefonMobil telefonDeServiciu(50);

	telefonPersonal.producator = "Samsung";
	telefonPersonal.nivelBaterie = 20;
	telefonPersonal.incarca(50);
	cout << telefonPersonal.nivelBaterie << endl;

	TelefonMobil* pTelefonMobil = new TelefonMobil(70);
	cout << (*pTelefonMobil).nivelBaterie << endl;
	pTelefonMobil->incarca(10);
	cout << pTelefonMobil->nivelBaterie << endl;
	delete pTelefonMobil;
	pTelefonMobil = nullptr;

	TelefonMobil altTelefon = 15;
	TelefonMobil t1 = altTelefon;
}