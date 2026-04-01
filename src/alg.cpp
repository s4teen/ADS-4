// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len; ++i)
    for (int j = i + 1; j < len; ++j)
      if (arr[i] + arr[j] == value)
        ++count;

  return count;
}

int countPairs2(int *arr, int len, int value) {
  if (len < 2)
    return 0;

  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    while (left < right && arr[left] + arr[right] > value)
      --right;

    if (left >= right)
      break;

    if (arr[left] + arr[right] < value) {
      ++left;
      continue;
    }

    if (arr[left] == arr[right]) {
      int n = right - left + 1;
      count += n * (n - 1) / 2;
      break;
    }

    int temp = right;
    while (temp > left && arr[left] + arr[temp] == value) {
      ++count;
      --temp;
    }

    ++left;
  }

  return count;
}

int countPairs3(int *arr, int len, int value) {
  if (len < 2)
    return 0;

  int *values = new int[len];
  int *counts = new int[len];
  int size = 0;

  for (int i = 0; i < len; ++i) {
    if (size == 0 || values[size - 1] != arr[i]) {
      values[size] = arr[i];
      counts[size] = 1;
      ++size;
    } else {
      ++counts[size - 1];
    }
  }

  int count = 0;

  for (int i = 0; i < size; ++i) {
    if (values[i] > value - values[i])
      break;

    int target = value - values[i];
    int left = i;
    int right = size - 1;
    int pos = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (values[mid] == target) {
        pos = mid;
        break;
      }

      if (values[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }

    if (pos == -1)
      continue;

    if (pos == i)
      count += counts[i] * (counts[i] - 1) / 2;
    else
      count += counts[i] * counts[pos];
  }

  delete[] values;
  delete[] counts;

  return count;
}
