#include <iostream>
using namespace std;

enum TipBursa { sociala = 2, academica, performanta };

union Bac
{
    float nota;
    unsigned char calificativ;
};

struct Carte {
    string titlu;
    string autor;
    int nrPagini;
};

class Student
{
public:
    string nume;
    int grupa = 1000;

    /*Student() {
        nume = "anonim";
        medie = 4;
    }*/

    Student(string _nume = "anonim") :medie(4)
    {
        nume = _nume;
    }

    ~Student() {
        cout << "Apel destructor" << endl;
    }

    void afisare()
    {
        cout << "Nume: " << nume << endl;
        cout << "Grupa: " << grupa << endl;
        cout << "Medie: " << medie << endl;
    }
private:
    float medie = 1;
};

int main()
{
    TipBursa bursa;
    bursa = TipBursa::sociala;
    cout << bursa << endl;
    bursa = (TipBursa)3;

    Bac bac;
    bac.calificativ = 'A';
    bac.nota = 9.83;
    cout << bac.calificativ << endl;

    Carte carte;
    carte.titlu = "Ion";
    carte.autor = "Liviu Rebreanu";
    carte.nrPagini = 400;

    Student s1;
    s1.nume = "Ionel";
    s1.afisare();

    Student s2("Gigel");
    s2.afisare();
    Student* ps = new Student("Vasile");
    cout << (*ps).nume << endl;
    cout << ps->grupa << endl;
    delete ps;
    ps = nullptr;
}