#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

class Student
{
public:
	string name;
	int grade;

	bool operator<(const Student& s) const
	{
		return this->grade < s.grade;
	}
};

template <typename T = int, int size = 1>
class Vector
{
public:
	T values[size];

	int getSize()
	{
		return size;
	}
};

int main()
{
	// Template
	const int size = 5;
	Vector<int, size> v1;
	v1.values[0] = 1;
	v1.values[1] = 2;
	cout << v1.getSize() << endl;

	Vector<> v2;
	cout << v2.getSize() << endl;

	// STL
	vector<int> v;
	v.push_back(1); v.push_back(2); v.push_back(3);

	for (unsigned i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl << v.capacity() << endl;

	v.pop_back();
	cout << v.size() << endl << v.capacity() << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
	for (int x : v)
	{
		cout << x << " ";
	}
	
	cout << endl;
	list<double> l;
	l.push_back(1.5);
	l.push_front(2.5);
	l.insert(++l.begin(), 3.7);
	list<double>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	it = --l.end();
	cout << *it;

	cout << endl;
	set<int> s;
	s.insert(1); s.insert(5); s.insert(2); s.insert(7);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	set<int>::iterator i = s.find(5);
	cout << endl << *i;

	cout << endl;
	set<Student> grupa;
	Student s1, s2;
	s1.name = "Ionel";
	s1.grade = 9;
	s2.name = "Gigel";
	s2.grade = 10;
	grupa.insert(s1);
	grupa.insert(s2);

	for (Student x : grupa)
	{
		cout << x.name << " ";
	}

	map<string, int> m;
	m.insert(pair<string, int>("Ionel", 12345));
	m.insert(make_pair("Gigel", 4567));
	m.insert(make_pair("Vasile", 7800));
	cout << endl;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	map<string, int>::iterator e = m.find("Ionel");
	cout << (e != m.end() ? e->second : -1) << endl;
	cout << m["Vasile"] << endl;
}