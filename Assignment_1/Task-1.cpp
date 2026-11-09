#include <iostream>
using namespace std;

int* resizeArray(int inArray[], const int size)
{
    int* n = new int[size * 2];

    for (int i = 0; i < size; i++)
    {
        n[i] = inArray[i];
        n[i + size] = inArray[i] * 2;
    }
    return n;
}

int main()
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    int* a = new int[size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    int* r = resizeArray(a, size);

    cout << "Resized array: ";
    for (int i = 0; i < size * 2; i++)
        cout << r[i] << " ";
    cout << endl;

    delete[] a;
    delete[] r;
    return 0;
}