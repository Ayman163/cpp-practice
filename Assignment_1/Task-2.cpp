#include <iostream>
using namespace std;

bool isDiagonal(int** m, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && m[i][j] != 0)
                return false;
    return true;
}

int main()
{
    int n;
    cout << "Enter size of the square matrix: ";
    cin >> n;

    int** m = new int*[n];
    for (int i = 0; i < n; i++)
        m[i] = new int[n];

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    cout << "Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }

    if (isDiagonal(m, n))
        cout << "It is a diagonal matrix." << endl;
    else
        cout << "It is NOT a diagonal matrix." << endl;

    for (int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}