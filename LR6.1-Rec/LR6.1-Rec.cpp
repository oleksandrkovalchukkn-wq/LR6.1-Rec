#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* r, int size, int Low, int High, int i);
void Print(int* r, int size, int i);
int Count(int* r, int size, int i);
int Sum(int* r, int size, int i);
void ZeroElements(int* r, int size, int i);

int main()
{
    srand((unsigned)time(NULL));

    const int k = 26;
    int r[k];

    int Low = 3;
    int High = 92;

    Create(r, k, Low, High, 0);

    cout << "Original:" << endl;
    Print(r, k, 0);

    int count = Count(r, k, 0);
    int sum = Sum(r, k, 0);

    ZeroElements(r, k, 0);

    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    cout << "Modified:" << endl;
    Print(r, k, 0);

    return 0;
}

void Create(int* r, int size, int Low, int High, int i)
{
    if (i < size)
    {
        r[i] = Low + rand() % (High - Low + 1);
        Create(r, size, Low, High, i + 1);
    }
}

void Print(int* r, int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << r[i];
        Print(r, size, i + 1);
    }
    else
    {
        cout << endl;
    }
}

int Count(int* r, int size, int i)
{
    if (i >= size)
        return 0;

    int isSatisfied = 0;
    if ((r[i] / 2) * 2 == r[i] && (i / 7) * 7 != i)
        isSatisfied = 1;

    return isSatisfied + Count(r, size, i + 1);
}

int Sum(int* r, int size, int i)
{
    if (i >= size)
        return 0;

    int valueToAdd = 0;
    if ((r[i] / 2) * 2 == r[i] && (i / 7) * 7 != i)
        valueToAdd = r[i];

    return valueToAdd + Sum(r, size, i + 1);
}

void ZeroElements(int* r, int size, int i)
{
    if (i < size)
    {
        if ((r[i] / 2) * 2 == r[i] && (i / 7) * 7 != i)
            r[i] = 0;

        ZeroElements(r, size, i + 1);
    }
}