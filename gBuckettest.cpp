// C++ program to sort an array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>

// Function to sort arr[] of size n using bucket sort
void bucket_sort(std::vector<double>& arr, const int n) {
  // 1) Create n empty buckets
  std::vector<std::vector<double>> b(10, std::vector<double>(10));
  // b.reserve(100);

  // 2) Put array elements in different buckets
  for (auto i = 0; i < n; i++) {
    // Index in bucket
    b[static_cast<unsigned int>(n * arr[i])].push_back(arr[i]);
  }

  // 3) Sort individual buckets
  for (auto i = 0; i < n; i++) sort(b[i].begin(), b[i].end());

  // 4) Concatenate all buckets into vector<double>arr

  auto it = arr.begin();
  for (const auto& x : b)
    for (auto y : x)
      if (y != 0.0) {
        *it++ = y;
      }
}

/* Driver program to test above function */
int main() {
  std::vector<double> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
  // fucking ugly code,yet I need to test something.

  bucket_sort(arr, arr.size());

  std::cout << "Sorted array is \n";
  for (auto x : arr) std::cout << x << " ";
  return EXIT_SUCCESS;
}