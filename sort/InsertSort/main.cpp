#include <iostream>

template <class T>
int getArrayLength(T& array) {
    return sizeof(array) / sizeof(array[0]);
}

template <class T>
void insertSort(T* arr, int len) {
    for (int i = 1; i < len; i++) {
        // 其实这部分是冒泡排序的部分；
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[] = {1, 4, 3, 5, 2, 9, 6, 7};
    int len = getArrayLength(arr);
    insertSort(arr, len);
    for (int i = 0; i < len; i++) {
        std::cout << arr[i];
        std::cout << ",";
    }
    return 0;
}