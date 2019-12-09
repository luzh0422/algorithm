#include <iostream>
#include "Heap.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Heap<int> heap(20);
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    heap.init(a, 9);
    heap.print();
    int *res = heap.sort();
    for (int i = 0; i < 9; ++ i) {
        std::cout << res[i];
    }
    std::cout << std::endl;
    return 0;
}