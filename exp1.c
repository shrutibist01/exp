// linear search recursive

#include <stdio.h>
int recursivelinearsearch(int arr[], int n, int m) {
  if (n == 0) {
    return -1;
  }
  if (arr[n - 1] == m) {
    return n - 1;
  }
  return recursivelinearsearch(arr, n - 1, m);
}
int main() {

  int i, m, n;
  printf("Enter the number of elements:");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements:");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the element you want to find:");
  scanf("%d", &m);
  int a = recursivelinearsearch(arr, n, m);
  if (a == -1) {
    printf("element not found");
  } else {
    printf("element found a %d index", a);
  }
}