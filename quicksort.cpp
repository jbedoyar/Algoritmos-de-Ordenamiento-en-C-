#include <iostream>
using namespace std;

void intercambio(int *a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int particion (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivote
    int i = (low - 1);  // indice del menor elemento

    for (int j = low; j <= high- 1; j++)
    {
        // si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot)
        {
            i++;    // incrementamos el indice del menor elemento
            intercambio(&arr[i], &arr[j]);
        }
    }
    intercambio(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi es el indice de particionamiento */
        int pi = particion(arr, low, high);

        // Ordenar los elementos
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
int main()
{
    int nums2[] = {26,2,45,1,6,8};
    quicksort(nums2,0,5);
    for (int i = 0; i < 6; i++)
    {
        cout<<nums2[i]<<" ";
    }
    cout<<endl;
    return 0;
}
