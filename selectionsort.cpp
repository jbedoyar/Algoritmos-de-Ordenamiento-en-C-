#include <iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    for(int i = 0; i < n -1; i++)
    {
        int minvalue = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j]< arr[minvalue])
            {
                minvalue = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minvalue];
        arr[minvalue] = temp;
    }
}
int main()
{
  int arr2[] = {8,7,5,4};
  selectionsort(arr2, 4);
  for(int i = 0; i < 4; i++)
  {
      cout<<arr2[i]<<" ";
  }
  cout<<endl;
}
