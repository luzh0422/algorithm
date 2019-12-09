#include <iostream>
#include "MergeSort.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    MergeSort<int> a;
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    a.init(arr, 9);
    a.sort();
    a.print();
    return 0;
}