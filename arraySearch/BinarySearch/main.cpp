#include <iostream>

/**
 * 注意二分查找必须是有序数组；
 */
template <class T>
int binarySearch(T value, T arr[], int start, int end) {
    if (start > end) {
        std::cout << "There is no number to find";
        return 0;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == value) {
        return mid;
    } else if (value < arr[mid]) {
        return binarySearch(value, arr, start, mid - 1);
    } else {
        return binarySearch(value, arr, mid + 1, end);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a = binarySearch(3, arr, 0, 8);
    std::cout << a;
    return 0;
}