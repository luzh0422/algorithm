#include <iostream>

void selectSort(int* array, int length);

template <class T>
int getArrayLength(T& array) {
    return sizeof(array) / sizeof(array[0]);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[] = {3, 4, 1, 5, 7, 2, 0};
    int len = getArrayLength(arr);
    selectSort(arr, len);
    for (int i = 0; i < len; i++) {
        std::cout<<arr[i];
        std::cout<<" ";
    }
    return 0;
}

void selectSort(int *array, int length) {
    for (int i = 0; i < length; i++) {
        int minValue = array[i];
        int index = i;
        for (int j = i; j < length; j++) {
            if (array[j] < minValue) {
                minValue = array[j];
                index = j;
            }
        }
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
}