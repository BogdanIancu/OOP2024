#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Cerere
{
public:
    char* titlu = nullptr;
    string continut;
    string semnatar;

    Cerere()
    {
    }

    Cerere(const char* titlu, string continut, string semnatar)
    {
        if (titlu != nullptr)
        {
            this->titlu = new char[strlen(titlu) + 1];
            strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
        }
        this->continut = continut;
        this->semnatar = semnatar;
    }

    Cerere(const Cerere& c)
    {
        if (c.titlu != nullptr)
        {
            this->titlu = new char[strlen(c.titlu) + 1];
            strcpy_s(this->titlu, strlen(c.titlu) + 1, c.titlu);
        }
        this->continut = c.continut;
        this->semnatar = c.semnatar;
    }

    ~Cerere()
    {
        if (titlu != nullptr)
            delete[] titlu;
    }

    Cerere& operator=(const Cerere& c)
    {
        if (this != &c)
        {
            if (titlu != nullptr)
                delete[] titlu;

            if (c.titlu != nullptr)
            {
                this->titlu = new char[strlen(c.titlu) + 1];
                strcpy_s(this->titlu, strlen(c.titlu) + 1, c.titlu);
            }
            else
                this->titlu = nullptr;
            this->continut = c.continut;
            this->semnatar = c.semnatar;
        }
        return *this;
    }
};

template <class T>
class Repo
{
public:
    virtual void create(T c) = 0;
    virtual T read(string nume) = 0;

    virtual ~Repo()
    {
    }
};

class CsvFileRepo :public Repo<Cerere>
{
private:
    static string filename;
public:
    void create(Cerere c) override
    {
        ofstream f(filename, ios::app | ios::ate);
        if (f.tellp() == 0)
        {
            f << "Titlu, Continut, Semnatar" << endl;
        }
        f << c.titlu << ", " << c.continut << ", " << c.semnatar << endl;
        f.close();
    }

    Cerere read(string nume) override
    {
        Cerere c;
        ifstream f(filename);
        string line;
        while (!f.eof())
        {
            getline(f, line);
            if (line.find(nume) != string::npos)
            {
                int pos = line.find(", ");
                string titlu = line.substr(0, pos);
                line = line.substr(pos + 2, line.length());
                pos = line.find(", ");
                string continut = line.substr(0, pos);
                string semnatar = line.substr(pos + 2, line.length());
                if (semnatar != nume)
                {
                    continue;
                }
                Cerere x(titlu.c_str(), continut, semnatar);
                return x;
            }
        }
        return c;
    }
};
string CsvFileRepo::filename = "Cereri.csv";


int main()
{
    Repo<Cerere>* repo = new CsvFileRepo();

    Cerere c1("Eliberare Legitimatie", "Va rog eliberati legitimatie transport", "Ion Popescu");
    repo->create(c1);
    Cerere c2("Adeverinta Student", "Va rog eliberati adeverinta", "Vasile Ionescu");
    repo->create(c2);

    string nume;
    cout << "Semnatar: ";
    cin >> ws;

    getline(cin, nume);

    Cerere c = repo->read(nume);
    cout << (c.titlu ? c.titlu : "") << endl << c.continut << endl << c.semnatar << endl;

    delete repo;
    repo = nullptr;
}