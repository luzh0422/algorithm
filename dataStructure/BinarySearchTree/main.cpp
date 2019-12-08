#include <iostream>
#include "BSTree.h"

int arr[] = {1, 5, 4, 3, 2, 6};
#define TBL_SIZE(a) (sizeof(a) / sizeof(a[0]))

int main() {
    std::cout << "Hello, World!" << std::endl;
    BSTree<int>* tree = new BSTree<int>();

    int ilen = TBL_SIZE(arr);
    for(int i = 0; i < ilen; ++i) {
        tree->insert(arr[i]);
    }

    tree->preOrder();
    std::cout << std::endl;
    tree->inOrder();
    return 0;
}