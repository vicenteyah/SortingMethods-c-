#include <iostream>
#include <cstdlib>
using namespace std;

void intercambio(int *x, int *y);
int particion(int[], int, int);
void quickSort(int[], int, int);
void imprimeVector(int[], int);

int main(int argc, char const *argv[])
{
    /* code */
    const int MAX = 20;
    int vector[MAX];
    for (int i = 0; i < MAX; i++)
    {
        vector[i] = (rand() % 100 + 1);
    }

    cout << "Arreglo Desordenado:" << endl;
    imprimeVector(vector, MAX);
    cout << endl;

    quickSort(vector, 0, MAX - 1);

    cout << "\nArreglo ordenado por QuickSort:" << endl;
    imprimeVector(vector, MAX);
    cout << endl;

    return 0;
}
void intercambio(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
int particion(int lista[], int bajo, int alto)
{
    int pivote = lista[alto];
    int i = (bajo - 1);
    for (int j = bajo; j <= alto - 1; j++)
    {
        if (lista[j] <= pivote)
        {
            i++;
            intercambio(&lista[i], &lista[j]);
        }
    }
    intercambio(&lista[i + 1], &lista[alto]);
    return (i + 1);
}

void quickSort(int lista[], int bajo, int alto)
{
    if (bajo < alto)
    {
        int part = particion(lista, bajo, alto);
        quickSort(lista, bajo, part - 1);
        quickSort(lista, part + 1, alto);
    }
}
void imprimeVector(int lista[], int tamanio)
{
    for (int x = 0; x < tamanio; x++)
    {
        cout << "[" << lista[x] << "],";
    }
}