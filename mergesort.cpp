#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* crear arrays tmeporales */
    int L[n1], R[n2];

    /* Copia de los datos a los arrays tmeporales L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* mezclar los arrayas temporales y ponerlos dentro arr[l..r]*/
    i = 0; // indice inicial del primer subarray
    j = 0; // indice inicial del segundo subarray
    k = l; // indice inicial del subarray mezcla
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copiar los elementos restantes de L[],si existe alguno */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copiar los elementos de restantes de R[],si existe alguno */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l es para el indice izquierdo y r es para el indice derecho odel subarray que sera ordenado*/
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        // indice medio
        int m = l+(r-l)/2;

        // Ordenar
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int main()
{
    int nums[] = {18,5,4,23,1,8,2};
    mergesort(nums,0,6);
    for (int i = 0; i < 7; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
