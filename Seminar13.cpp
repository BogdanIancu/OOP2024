#include<iostream>
#include<set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

class Autoturism {
public:
    string producator;
    int anFabricatie;

    bool operator<(const Autoturism& a) const {
        return this->producator < a.producator;
    }
};
int main() {
    set<int> s;
    s.insert(45);
    s.insert(2);
    s.insert(7);
    s.insert(2);

    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    Autoturism a1;
    a1.producator = "Nissan";
    a1.anFabricatie = 2020;

    Autoturism a2;
    a2.producator = "Dacia";
    a2.anFabricatie = 2024;

    set<Autoturism > flota;
    flota.insert(a1);
    flota.insert(a2);
    for (Autoturism a : flota) {
        cout << a.producator << " ";
    }
    cout << endl;

    map<int, int> m;
    m.insert(make_pair(1, 2));
    m.insert(pair<int, int>(2, 4));
    m.insert(make_pair(3, 6));

    cout << m[2] << endl;

    map<int, int>::iterator i = m.find(3);
    if (i != m.end()) {
        cout << i->second;
    }

    stack<int> stiva;
    stiva.push(2);
    stiva.push(4);
    stiva.push(3);

    cout << endl;

    while (!stiva.empty()) {
        cout << stiva.top() << " ";
        stiva.pop();
    }

    queue<int> coada;
    coada.push(2);
    coada.push(4);
    coada.push(3);

    cout << endl;

    while (!coada.empty()) {
        cout << coada.front() << " ";
        coada.pop();
    }

    priority_queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);

    cout << endl;

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}