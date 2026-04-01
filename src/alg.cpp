// Copyright 2021 NNTU-CS
#include <cstdint>

int lowerBound(const int* arr, int left, int right, int target) {
  while (left < right) {
    const int mid = left + (right - left) / 2;
    if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

int upperBound(const int* arr, int left, int right, int target) {
  while (left < right) {
    const int mid = left + (right - left) / 2;
    if (arr[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

int countPairs1(int* arr, int len, int value) {
  std::int64_t count = 0;

  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }

  return static_cast<int>(count);
}

int countPairs2(int* arr, int len, int value) {
  if (len < 2) {
    return 0;
  }

  std::int64_t count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    const int sum = arr[left] + arr[right];

    if (sum < value) {
      ++left;
    } else if (sum > value) {
      --right;
    } else {
      if (arr[left] == arr[right]) {
        const std::int64_t count_same = right - left + 1;
        count += count_same * (count_same - 1) / 2;
        break;
      }

      const int left_value = arr[left];
      const int right_value = arr[right];

      int left_count = 0;
      while (left <= right && arr[left] == left_value) {
        ++left;
        ++left_count;
      }

      int right_count = 0;
      while (right >= left && arr[right] == right_value) {
        --right;
        ++right_count;
      }

      count += static_cast<std::int64_t>(left_count) * right_count;
    }
  }

  return static_cast<int>(count);
}

int countPairs3(int* arr, int len, int value) {
  std::int64_t count = 0;

  for (int i = 0; i + 1 < len; ++i) {
    if (arr[i] > value) {
      break;
    }

    const int target = value - arr[i];
    const int first = lowerBound(arr, i + 1, len, target);

    if (first == len || arr[first] != target) {
      continue;
    }

    const int last = upperBound(arr, first, len, target);
    count += last - first;
  }

  return static_cast<int>(count);
}
