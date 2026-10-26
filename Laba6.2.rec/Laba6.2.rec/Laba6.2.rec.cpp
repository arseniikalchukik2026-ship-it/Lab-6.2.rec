#include <iostream>   
#include <iomanip>   
#include <time.h>     
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else  cout << endl;
}
int Ifirst(int* a, const int size, int& min, int i)
{
    if (a[i] % 2 == 0)
    {
        min = a[i];
        return i;
    }  
    if (i < size - 1) {
        return Ifirst(a, size, min, i + 1);
    }
    else
        return -1;
    
}
int Min(int* a, const int size, int min, int i) {
    if (a[i] < min && a[i] % 2 == 0)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, min, i + 1);
    else
        return min;
}
int Find(int* a, const int size, const int x, int i)
{
    if (a[i] == x)
        return i;

    if (i < size - 1)
        return Find(a, size, x, i + 1);
    else
        return -1;
}

void obmin(int* a, const int imin) {
    if (imin == -1)
        return;
    int r = a[0];
    a[0] = a[imin];
    a[imin] = r;
}




int main()
{
    srand((unsigned)time(NULL));

    const int n = 22;
    int a[n];

    int Low = -40;
    int High = 50;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    int min;
    int imin = Ifirst(a, n, min, 0);

    if (imin == -1)
        cerr << "NEMA" << endl;
    else
    {
        imin = Find(a, n, Min(a, n, min, imin), 0);
        obmin(a, imin);
        Print(a, n, 0);
    }

    return 0;
}