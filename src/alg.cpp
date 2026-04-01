// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i)
    for (int j = i + 1; j < len; ++j)
      if (arr[i] + arr[j] == value) ++count;
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0, left = 0, right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];

    if (sum < value) { ++left; continue; }
    if (sum > value) { --right; continue; }

    if (arr[left] == arr[right]) {
      int n = right - left + 1;
      return count + n * (n - 1) / 2;
    }

    int a = arr[left], b = arr[right], lc = 0, rc = 0;
    while (left <= right && arr[left] == a) { ++left; ++lc; }
    while (right >= left && arr[right] == b) { --right; ++rc; }
    count += lc * rc;
  }

  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len - 1; ++i) {
    int target = value - arr[i], left = i + 1, right = len - 1;
    int first = -1, last = -1, mid;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (arr[mid] < target) left = mid + 1;
      else {
        if (arr[mid] == target) first = mid;
        right = mid - 1;
      }
    }

    if (first == -1) continue;

    left = first;
    right = len - 1;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (arr[mid] > target) right = mid - 1;
      else {
        if (arr[mid] == target) last = mid;
        left = mid + 1;
      }
    }

    count += last - first + 1;
  }

  return count;
}
