#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using namespace std;

template <typename T>
bool lessThan(T v1, T v2)
{
    return v1 < v2;
}

template<class T>
class Vector
{
private:
    T* elemente = nullptr;
    unsigned int dimensiune = 0;

public:
    Vector()
    {
    }

    Vector(T* elemente, unsigned int dimensiune)
    {
        if (elemente != nullptr)
        {
            this->elemente = new T[dimensiune];
            this->dimensiune = dimensiune;
            for (int i = 0; i < this->dimensiune; i++)
            {
                this->elemente[i] = elemente[i];
            }
        }
    }

    Vector(const Vector& v)
    {
        if (v.elemente != nullptr)
        {
            this->elemente = new T[v.dimensiune];
            this->dimensiune = v.dimensiune;
            for (int i = 0; i < this->dimensiune; i++)
            {
                this->elemente[i] = v.elemente[i];
            }
        }
    }

    ~Vector()
    {
        if (this->elemente != nullptr)
        {
            delete[] this->elemente;
        }
    }

    Vector& operator=(const Vector& v)
    {
        if (this != &v)
        {
            if (this->elemente != nullptr)
            {
                delete[] this->elemente;
            }

            if (v.elemente != nullptr)
            {
                this->elemente = new T[v.dimensiune];
                this->dimensiune = v.dimensiune;
                for (int i = 0; i < this->dimensiune; i++)
                {
                    this->elemente[i] = v.elemente[i];
                }
            }
            else
            {
                this->elemente = nullptr;
                this->dimensiune = 0;
            }
        }
        return *this;
    }

    unsigned int getDimensiune()
    {
        return dimensiune;
    }

    T& operator[](unsigned int index)
    {
        if (index < dimensiune)
        {
            return elemente[index];
        }
        else
        {
            throw exception("Index invalid");
        }
    }
};

int main()
{
    cout << lessThan<int>(5, 6) << endl;
    cout << lessThan<string>("Ana", "Anca") << endl;

    Vector<int> v1;
    int w[]{ 3,7,9 };
    Vector<int> v2(w, 3);
    v2[0] = 6;
    for (int i = 0; i < v2.getDimensiune(); i++)
    {
        cout << v2[i] << " ";
    }

    vector<double> v;
    v.push_back(2.1);
    v.push_back(1.5);
    v.push_back(2.4);

    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    v.pop_back();

    cout << endl;
    for (vector<double>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    list<int> l;
    l.push_back(6);
    l.push_front(7);
    l.insert(++l.begin(), 2);

    cout << endl;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }

    deque<string> d;
    d.push_back("xyz");
    d.push_front("abc");
    d.insert(d.begin(), "aaa");

    cout << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }

    cout << endl;
    for (auto s : d)
    {
        cout << s << " ";
    }
}