// quick sort

#include <stdio.h>

void printArr(int arr[], int l, int h) {
  for (int i = l; i <= h; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void quicksort(int arr[], int l, int h) {
  int pivot, i, j, temp;
  if (l < h) {
    pivot = arr[h];
    i = l;
    j = h - 1;

    printf("Pivot value: %d\n", pivot);

    while (i <= j) {
      while (i <= j && arr[i] <= pivot) {
        i++;
      }
      while (j >= l && arr[j] > pivot) {
        j--;
      }
      if (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        printArr(arr, l, h);
      }
    }

    temp = arr[i];
    arr[i] = arr[h];
    arr[h] = temp;

    printArr(arr, l, h);
    printf("\n");

    quicksort(arr, l, i - 1);
    quicksort(arr, i + 1, h);
  }
}

int main() {
  int n, i;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Invalid number of elements.\n");
    return 1;
  }

  int arr[n];

  printf("Enter the elements of the array:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Before sorting:\n");
  printArr(arr, 0, n - 1);

  quicksort(arr, 0, n - 1);

  printf("After sorting:\n");
  printArr(arr, 0, n - 1);

  return 0;
}