#include <iostream>
using namespace std;

int findMin(int inArray[], const int size)
{
    int min = inArray[0];
    for (int i = 1; i < size; i++)
        if (inArray[i] < min)
            min = inArray[i];
    return min;
}

int findMax(int inArray[], const int size)
{
    int max = inArray[0];
    for (int i = 1; i < size; i++)
        if (inArray[i] > max)
            max = inArray[i];
    return max;
}

int computeAverage(int inArray[], const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += inArray[i];
    return sum / size;
}

int computeMedian(int inArray[], const int size)
{
    int* t = new int[size];
    for (int i = 0; i < size; i++)
        t[i] = inArray[i];

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (t[j] > t[j + 1])
            {
                int tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;
            }

    int med;
    if (size % 2 == 1)
        med = t[size / 2];
    else
        med = (t[size / 2 - 1] + t[size / 2]) / 2;

    delete[] t;
    return med;
}

int main()
{
    int size;
    cout << "Enter number of students: ";
    cin >> size;

    int* marks = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter mark of student " << i + 1 << ": ";
        cin >> marks[i];
        while (marks[i] < 0)
        {
            cout << "Marks cannot be negative, try again: ";
            cin >> marks[i];
        }
    }

    cout << "Maximum: " << findMax(marks, size) << endl;
    cout << "Minimum: " << findMin(marks, size) << endl;
    cout << "Average: " << computeAverage(marks, size) << endl;
    cout << "Median : " << computeMedian(marks, size) << endl;

    delete[] marks;
    return 0;
}