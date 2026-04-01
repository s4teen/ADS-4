// Copyright 2021 NNTU-CS
#include <iostream>
#include <vector>

int countPairs1(int* arr, int len, int value);
int countPairs2(int* arr, int len, int value);
int countPairs3(int* arr, int len, int value);

int main() {
  int len = 0;
  int value = 0;
  std::cin >> len >> value;

  std::vector<int> arr(len);
  for (int i = 0; i < len; ++i) {
    std::cin >> arr[i];
  }

  std::cout << countPairs1(arr.data(), len, value) << '\n';
  std::cout << countPairs2(arr.data(), len, value) << '\n';
  std::cout << countPairs3(arr.data(), len, value) << '\n';

  return 0;
}
