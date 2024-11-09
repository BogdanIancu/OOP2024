#include <iostream>
using namespace std;

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
    Masina() :serie(-1)
    {
        anFabricatie = 1900;
        this->pret = 100;
    }

    Masina(int serie, float pret, float* preturiDotari, int numarDotari) :serie(serie)
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

    Masina(string producator, string model, int anFabricatie, int serieSasiu) :serie(serieSasiu)
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

    float getPreturiDotariExtra(int index) {
        if (index >= 0 && index < numarDotariExtra) {
            return preturiDotariExtra[index];
        }
        return 0;
    }

    void setPreturiDotariExtra(float* preturi, int nrPreturi) {
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
}