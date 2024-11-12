// knapsack

// fractional using greedy
#include <stdio.h>

void fractionalKnapsack(int num, int capacity, double profit[], double weight[],
                        double ratio[]) {
  int cap = capacity;
  double totalProfit = 0.0;
  double fraction[num];

  // Initialize the fraction array to 0
  for (int i = 0; i < num; i++) {
    fraction[i] = 0.0;
  }

  // Fill the knapsack with whole items as much as possible
  int i;
  for (i = 0; i < num; i++) {
    if (weight[i] > cap)
      break;
    else {
      totalProfit += profit[i];
      cap -= weight[i];
      fraction[i] = 1.0;
    }
  }

  // If there's remaining capacity, add a fraction of the next item
  if (i < num) {
    fraction[i] = (double)cap / weight[i];
    totalProfit += fraction[i] * profit[i];
  }

  // Print the table header
  printf("\n| Index | Profit | Weight | P/W Ratio | Fraction x |\n");
  printf("---------------------------------------------------\n");

  // Print the table contents
  for (int j = 0; j < num; j++) {
    printf("| %5d | %6.2f | %6.2f | %9.2f | %10.2f |\n", j + 1, profit[j],
           weight[j], ratio[j], fraction[j]);
  }

  // Print the total profit
  printf("\nTotal Profit: %.2f\n", totalProfit);
}

int main() {
  int capacity, num;

  printf("Enter the number of elements: ");
  scanf("%d", &num);

  double weight[num], profit[num], ratio[num];

  printf("Enter the profits: ");
  for (int i = 0; i < num; i++) {
    scanf("%lf", &profit[i]);
  }

  printf("Enter the weights: ");
  for (int i = 0; i < num; i++) {
    scanf("%lf", &weight[i]);
  }

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  // Calculate profit-to-weight ratio for each item
  for (int i = 0; i < num; i++) {
    ratio[i] = profit[i] / weight[i];
  }

  // Sort items by profit-to-weight ratio in descending order
  for (int i = 0; i < num; i++) {
    for (int j = i + 1; j < num; j++) {
      if (ratio[i] < ratio[j]) {
        // Swap ratios
        double temp = ratio[i];
        ratio[i] = ratio[j];
        ratio[j] = temp;

        // Swap profits
        temp = profit[i];
        profit[i] = profit[j];
        profit[j] = temp;

        // Swap weights
        temp = weight[i];
        weight[i] = weight[j];
        weight[j] = temp;
      }
    }
  }

  fractionalKnapsack(num, capacity, profit, weight, ratio);
  return 0;
}

