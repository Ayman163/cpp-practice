#include <iostream>
using namespace std;

char* left(const char* target, const int count)
{
    char* p = new char[count + 1];

    for (int i = 0; i < count; i++)
        p[i] = target[i];
    p[count] = '\0';

    return p;
}

int getLength(const char* str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

void Destructor(char* p)
{
    delete[] p;
}

int main()
{
    char s[30];
    int count;

    cout << "Enter a string: ";
    cin.getline(s, 30);

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Enter count: ";
    cin >> count;

    if (count < 0 || count > getLength(s))
        cout << "Count is out of range!" << endl;
    else
    {
        char* sub = left(s, count);
        cout << "Left substring: " << sub << endl;
        Destructor(sub);
    }
    return 0;
}