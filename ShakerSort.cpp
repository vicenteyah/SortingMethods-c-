#include <iostream>
#include <cstdlib>

using namespace std;

void shakersort(int a[]);
int main()
{

    int ordenar[] = {3, 5, 9, 1, 10, 23, 15, 2, 50, 25, 31, 12, 30, 90, 11, 29, 89, 20, 19, 4};
    cout << "\nORIGINAL: " << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << " " << ordenar[i] << " ";
    }
    cout << "\n\nORDENADO " << endl;
    shakersort(ordenar);
    for (int i = 0; i < 20; i++)
    {
        cout << " " << ordenar[i] << " ";
    }

    return 0;
}

void shakersort(int a[])
{
    int izq, der, k, aux;
    izq = 0;
    der = 20;
    k = 20;

    while (der >= izq)
    {
        for (int i = 20; i >= 0; i--)
        {
            if (a[i - 1] > a[i])
            {
                aux = a[i - 1];
                a[i - 1] = a[i];
                a[i] = aux;
                k = i;
            }
        }
        izq = k + 1;
        for (int i = izq; i <= der; i++)
        {
            if (a[i - 1] > a[i])
            {
                aux = a[i - 1];
                a[i - 1] = a[i];
                a[i] = aux;
                k = i;
            }
        }
        der = k - 1;
    }
}
