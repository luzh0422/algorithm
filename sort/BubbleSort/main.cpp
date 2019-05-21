#include <iostream>

void bubbleSort(int array[], int length);

template <class T>
int getArrayLen(T& array) {
    return sizeof(array) / sizeof(array[0]);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[] = {5, 3, 1, 7, 9, 10, 11};
    int len = getArrayLen(arr);
    bubbleSort(arr, len);
    for (int i = 0; i < len; i++) {
        std::cout << arr[i];
        std::cout << " ";
    }
    return 0;
}

void bubbleSort(int array[], int length) {
    int temp;
    for (int i = 0; i < length; i++) {
        for (int j = length - 1; j > i; j--) {
            if (array[j] < array[j-1]) {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}