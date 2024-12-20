#include <iostream>
using namespace std;

class ActivImpozabil
{
public:
    virtual float calculeazaImpozit() = 0;
};

class Locuinta : public ActivImpozabil
{
private:
    int suprafataUtila;
    string numarCadastral;

protected:
    float pret;

public:
    Locuinta()
    {
        pret = 0;
        suprafataUtila = 0;
    }

    Locuinta(float pret, int suprafataUtila)
    {
        if (pret > 0)
            this->pret = pret;
        else this->pret = 0;

        if (suprafataUtila > 0)
            this->suprafataUtila = suprafataUtila;
        else this->suprafataUtila = 0;
    }

    float getPret()
    {
        return pret;
    }

    virtual float getPretCuTVA()
    {
        if (pret <= 100000)
        {
            return pret * 1.05;
        }
        else
        {
            return pret * 1.19;
        }
    }

    float calculeazaImpozit() override
    {
        return 2 * suprafataUtila;
    }
};

class Masina : public ActivImpozabil
{
private:
    string producator;
    int capacitateCilindrica;

protected:
    float pret;

public:
    Masina()
    {
        pret = 0;
        capacitateCilindrica = 0;
    }

    Masina(string producator, float pret, int capacitateCilindrica)
    {
        this->producator = producator;
        this->pret = pret;
        this->capacitateCilindrica = capacitateCilindrica;
    }

    float getPret()
    {
        return pret;
    }

    float calculeazaImpozit() override
    {
        return 0.8 * capacitateCilindrica;
    }
};

class Autorulota : public Masina, public Locuinta
{
private:
    int numarLocuri;

public:
    Autorulota()
    {
        numarLocuri = 0;
    }

    Autorulota(string producator, float pretMasina, int suprafata, int capacitate) : Locuinta(0, suprafata), Masina(producator, pretMasina, capacitate)
    {
        numarLocuri = 0;
    }

    float getPret()
    {
        return Masina::pret + Locuinta::pret;
    }

    float getPretCuTVA()
    {
        return getPret() * 1.19;
    }

    float calculeazaImpozit() override
    {
        return Masina::calculeazaImpozit();
    }
};



int main()
{
    Locuinta l1(20000, 65);
    Masina m1("Fiat", 10000, 2000);
    Autorulota a1("Citroen", 12000, 3, 1800);

    cout << a1.getPret() << endl;
    cout << a1.Locuinta::getPret() << endl;
    cout << l1.getPretCuTVA() << endl;
    cout << a1.getPretCuTVA() << endl;

    int x = 0;
    //cin >> x;

    Locuinta* p = x ? &a1 : &l1;

    cout << p->getPretCuTVA() << endl;

    cout << sizeof(l1) << endl;

    Masina& r = a1;
    ActivImpozabil& i1 = r;
    cout << i1.calculeazaImpozit() << endl;
}