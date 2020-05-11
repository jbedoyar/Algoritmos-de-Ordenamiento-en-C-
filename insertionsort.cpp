#include <iostream>
using namespace std;

void insertionsort(int arr[], int n)
{
   int  key, j;
   /* Mueve los elementos del arr[0..i-1], que son
          mayores que la llave, una posicion adelante de su posicion actual */
   for (int i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
int main()
{
    int arr[] = {3,56,7,4,67,45};
    insertionsort(arr,6);
    for(int i = 0; i < 6; ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
