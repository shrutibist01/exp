// optimal merge pattern

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
//min heap sort then add and compute 
int minComputation(int size, vector<int> &files) {
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < size; i++) {
    pq.push(files[i]);
  }

  int count = 0;

  while (pq.size() > 1) {
    int first_smallest = pq.top();
    pq.pop();
    int second_smallest = pq.top();
    pq.pop();

    int temp = first_smallest + second_smallest;
    count += temp;

    pq.push(temp);
    cout << "Merge: " << first_smallest << " and " << second_smallest
         << " → New file size: " << temp << endl;
  }
  return count;
}

int main() {
  int n;
  cout << "Enter the number of files: ";
  cin >> n;

  vector<int> files(n);
  cout << "Enter the sizes of the files:\n";
  for (int i = 0; i < n; i++) {
    cin >> files[i];
  }

  cout << "Minimum Computations = " << minComputation(n, files) << endl;
  return 0;
}