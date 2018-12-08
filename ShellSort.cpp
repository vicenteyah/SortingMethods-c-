#include <iostream>
#include <cstdlib>
using namespace std;
void shellSort(int[], int);
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

    cout << "Lista Desordenada" << endl;
    imprimeVector(vector, MAX);
    shellSort(vector, MAX);
    cout << "\nLista ordenada por el método shell" << endl;
    imprimeVector(vector, MAX);

    return 0;
}
void imprimeVector(int lista[], int tamanio)
{
    for (int x = 0; x < tamanio; x++)
    {
        cout << "[" << lista[x] << "],";
    }
    cout << endl;
}
void shellSort(int lista[], int tamanio)
{
    int p = 0, temp = 0, j = 0, i;
    for (i = tamanio / 2; i != 0; i /= 2)
    {
        for (p = 1; p != 0;)
        {
            p = 0;
            for (j = i; j < tamanio; j++)
                if (lista[j - i] > lista[j])
                {
                    temp = lista[j];
                    lista[j] = lista[j - i];
                    lista[j - i] = temp;
                    p++;
                }
        }
    }
}