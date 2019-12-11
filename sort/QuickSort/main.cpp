#include <iostream>

template <class T>
void exchange(T *a, T *b) {
    T temp = *b;
    *b = *a;
    *a = temp;
}

template <class T>
void quickSort(T a[], int start, int end) {
    if (start >= end) {
        return;
    }
    T key = a[end];
    int i = start;
    for (int j = start; j < end; j++) {
        if (a[j] < key) {
            exchange(&a[i ++], &a[j]);
        }
    }
    exchange(&a[i], &a[end]);
    quickSort(a, start, i - 1);
    quickSort(a, i + 1, end);
}

template <class T>
void print(T a[], int size) {
    for (int i = 0; i < size; ++ i) {
        std::cout << a[i];
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[] = {6, 5, 4, 3, 2, 1};
    quickSort(arr, 0, 5);
    print(arr, 6);
    return 0;
}