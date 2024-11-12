// merge sort

#include <stdio.h>

void merge(int arr[], int l, int mid, int h) {
  int i, j, k;
  i = l;
  j = mid + 1;
  k = l;
  int b[h + 1];

  while (i <= mid && j <= h) {
    if (arr[i] <= arr[j]) {
      b[k] = arr[i];
      i++;
    } else {
      b[k] = arr[j];
      j++;
    }
    k++;
  }

  if (i > mid) {
    while (j <= h) {
      b[k] = arr[j];
      j++;
      k++;
    }
  } else {
    while (i <= mid) {
      b[k] = arr[i];
      i++;
      k++;
    }
  }

  for (k = l; k <= h; k++) {
    arr[k] = b[k];
  }
}

void merge_sort(int arr[], int l, int h) {
  if (l < h) {
    int mid = (l + h) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, h);
    merge(arr, l, mid, h);
  }
}

int main() {
  int arr[100], n, i;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the array elements:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  merge_sort(arr, 0, n - 1);

  printf("The sorted array is: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}