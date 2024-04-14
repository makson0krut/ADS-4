// Copyright 2021 NNTU-CS


int countPairs1(int *arr, int size, int value) {
    int count = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if ((arr[i] + arr[j]) == value)
                count += 1;
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int right = 0;
    int count = 0;
    int left = len - 1;
    while (arr[right] > value) {
        right -= 1;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                count++;
            }
        }
    }
    return count;
}

int binsearch(int* arr, int size, int value) {
    int right = size - 1;
    int flag = 0;
    int left = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            flag++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == value) {
                flag++;
                left--;
            }
            while (right < size && arr[right] == value) {
                flag++;
                right++;
            }
            return flag;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return flag;
}

int countPairs3(int* arr, int len, int value) {
    int flag = 0;
    for (int i = 0; i < len; i++) {
        int second = value - arr[i];
        flag += binsearch(&arr[i + 1], len - i - 1, second);
    }
    return flag;
}
