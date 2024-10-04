#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";

    char c = 100;
    cout << c << endl;

    unsigned char d = 'A';
    printf("%d\n", d);

    c = 127;
    c++;
    printf("%d\n", c);

    short x = 25000;
    cout << sizeof(x) << endl;

    int y = 782178;
    cout << sizeof(y) << endl;

    long long z = 132323;
    cout << sizeof(z) << endl;

    if (c == 127)
    {
        cout << "Sunt egale" << endl;
    }
    else
    {
        cout << "Nu sunt egale" << endl;
    }

    bool ok = true;
    cout << sizeof(ok) << endl;

    float a = 8.4;
    cout << sizeof(a) << endl;
    double b = 8.4;
    cout << sizeof(b) << endl;

    if (fabs(a - b) < 0.01)
    {
        cout << "OK";
    }
    else
    {
        cout << "NOT OK";
    }
}
