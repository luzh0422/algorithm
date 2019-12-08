#include <iostream>
#include "./heap.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    MaxHeap<int> h(20);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    h.init(arr, 10);
    h.print();
    int value = h.pop();
    h.print();
    return 0;
}