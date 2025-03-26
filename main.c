#include <stdio.h>

int pivote(int *arr, int inicio, int fin)
{
  int pivote = arr[fin];
  int j = inicio - 1;
  for (int i = inicio; i < fin; i++)
  {
    if (arr[i] <= pivote)
    {
      j++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[j + 1];
  arr[j + 1] = arr[fin];
  arr[fin] = temp;

  return j + 1;
}

void quickSort(int *arr, int inicio, int fin)
{
  if (inicio < fin)
  {
    int pivot = pivote(arr, inicio, fin);
    quickSort(arr, inicio, pivot - 1);
    quickSort(arr, pivot + 1, fin);
  }
}

int main(void)
{
  int SIZE;
  printf("Ingrese la cantidad de elementos para el array\n");
  scanf("%d", &SIZE);
  int array[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    int valor;
    printf("Ingrese el dato numero: %d del array\n", i + 1);
    scanf("%d", &valor);
    array[i] = valor;
  }
  quickSort(array, 0, SIZE - 1);
  printf("---------\n");
  for (int i = 0; i < SIZE; i++)
  {
    printf("%d\n", array[i]);
  }
}