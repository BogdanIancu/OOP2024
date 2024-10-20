#include <iostream>
using namespace std;

void transpusa(int*** matrice, int& nrLinii, int& nrColoane)
{
    int** t = new int* [nrColoane];
    for (int i = 0; i < nrColoane; i++)
    {
        t[i] = new int[nrLinii];
    }

    for (int i = 0; i < nrColoane; i++)
    {
        for (int j = 0; j < nrLinii; j++)
        {
            t[i][j] = (*matrice)[j][i];
        }
    }

    for (int i = 0; i < nrLinii; i++)
    {
        delete[](*matrice)[i];
    }
    delete[] * matrice;

    int aux = nrLinii;
    nrLinii = nrColoane;
    nrColoane = aux;
    *matrice = t;
}

void afisare(const int** matrice, int nrLinii, int nrColoane)
{
    for (int i = 0; i < nrLinii; i++)
    {
        for (int j = 0; j < nrColoane; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

enum TipBursa { sociala = 2, academica, performanta };

union Bac {
    float medie;
    unsigned char calificativ;
};

int main()
{
    int x = 5;
    int& r = x;
    x++;
    cout << r << endl;

    int matrice[2][3];
    cout << matrice << endl;
    matrice[1][2] = 99;
    cout << *(*(matrice + 1) + 2) << endl;
    cout << sizeof(matrice) / sizeof(matrice[0]) << endl;
    cout << sizeof(matrice[0]) / sizeof(matrice[0][0]) << endl;

    int nr_linii = 2;
    int nr_coloane = 3;

    int** w = new int* [2];
    for (int i = 0; i < 2; i++)
    {
        w[i] = new int[3];
    }

    afisare((const int**)w, nr_linii, nr_coloane);
    cout << endl;
    transpusa(&w, nr_linii, nr_coloane);
    afisare((const int**)w, nr_linii, nr_coloane);
    cout << nr_linii << endl;

    for (int i = 0; i < 2; i++)
    {
        delete[] w[i];
        w[i] = nullptr;
    }
    delete[] w;
    w = nullptr;

    TipBursa bursa = TipBursa::sociala;
    cout << bursa << endl;

    Bac bac;
    bac.calificativ = 'A';
    cout << bac.calificativ << endl;
    cout << bac.medie << endl;
    bac.medie = 9.19;
    cout << bac.medie << endl;
}