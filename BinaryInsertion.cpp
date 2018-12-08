#include <iostream>
#include <cstdlib>
using namespace std;
int busquedaBinaria(int[], int, int, int);
void insercionOrdenar(int[], int);
void imprimeVector(int[], int);
int main(int argc, char const *argv[])
{
    /* code */
    const int MAX = 20;
    int vector[MAX];
    for (int y = 0; y < MAX; y++)
    {
        vector[y] = (rand() % 100 + 1);
    }

    cout << "Arreglo Desordenado:" << endl;
    imprimeVector(vector, MAX);
    insercionOrdenar(vector, MAX);
    cout << "\nArreglo Ordenado por insercion binaria:" << endl;
    imprimeVector(vector, MAX);
    return 0;
}
void imprimeVector(int lista[], int tam)
{
    for (int fx = 0; fx < tam; fx++)
    {
        cout << "[" << lista[fx] << "],";
    }
}
void insercionOrdenar(int x[], int n)
{
    int i, loc, j, k, selecto;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selecto = x[i];
        loc = busquedaBinaria(x, selecto, 0, j);
        while (j >= loc)
        {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = selecto;
    }
}
int busquedaBinaria(int x[], int item, int bajo, int alto)
{

    if (alto <= bajo)
        return (item > x[bajo] ? (bajo + 1) : bajo); //operador ternario
    int mid = (bajo + alto) / 2;

    if (item == x[mid])
        return mid + 1;
    if (item > x[mid])
        return busquedaBinaria(x, item, mid + 1, alto);
    return busquedaBinaria(x, item, bajo, mid - 1);
}