#include <iostream>
using namespace std;

class Masina
{
private:
    string producator;
    string model;
    int anFabricatie;
    float pret;
    const int serie;
    static string normaPoluare;

public:
    Masina() :serie(-1)
    {
        anFabricatie = 1900;
        this->pret = 100;
    }

    Masina(string producator, string model, int anFabricatie, int serieSasiu) :serie(serieSasiu)
    {
        this->producator = producator;
        this->model = model;
        this->anFabricatie = anFabricatie;
        this->pret = 200;
    }

    Masina(const Masina& m) :serie(m.serie)
    {
        this->producator = m.producator;
        this->model = m.model;
        this->anFabricatie = m.anFabricatie;
        this->pret = m.pret;
    }

    ~Masina()
    {
        cout << "Apel destructor!" << endl;
    }

    float getPret()
    {
        return pret;
    }

    void setPret(float pretNou)
    {
        if (pretNou >= 0)
        {
            pret = pretNou;
        }
    }

    static string getNormaPoluare() {
        return normaPoluare;
    }

    static void setNormaPoluare(string normaPoluare) {
        Masina::normaPoluare = normaPoluare;
    }

    static double valoareFlota(Masina* masini, int nrMasini) {
        double valoare = 0;
        if (masini != nullptr) {
            for (int i = 0; i < nrMasini; i++) {
                valoare += masini[i].pret;
            }
        }
        return valoare;
    }

    string getModel();
};
string Masina::normaPoluare = "euro 6";

string Masina::getModel() {
    return model;
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
}