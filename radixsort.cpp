#include<iostream>
using namespace std;

// Funcion para obtener el maximo valor in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Una funcion para counting sort de acuerdo con
// el digito representado por exp.
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    // Almacena el numero de ocurrencias en count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Cambia count[i] asi que count[i] contiene ahora la actual
    //  posicion de este  digito en salida[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construir la matriz de salida
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copie la matriz de salida en arr [], de modo que arr [] ahora
    // contiene números ordenados según el dígito actual
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixsort(int arr[], int n)
{
    // Encuentra el número máximo para saber el número de dígitos
    int m = getMax(arr, n);

    // Haga un conteo por cada dígito. Tenga en cuenta que en su lugar
    // de pasar el número de dígito, se pasa exp. exp es 10 ^ i
    // donde i es el número de dígito actual
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    radixsort(arr, 8);
    for(int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
