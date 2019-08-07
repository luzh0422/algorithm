#ifndef MAX_HEAP
#define MAX_HEAP

#include <iostream>
using namespace std;

template <class T>
class MaxHeap {
private:
    void filterUp(int index);
    T *heap;
    int mOpacity;
    int mSize;

public:
    MaxHeap(int capcity = 20);
    ~MaxHeap();
    void init(T value[], int length);
    void insert(T value);
    void print();
};

template <class T>
MaxHeap<T>::MaxHeap(int capcity) {
    mOpacity = capcity;
    mSize = 0;
    heap = new T[mOpacity];
}

template <class T>
MaxHeap<T>::~MaxHeap() {
    delete []heap;
}

template <class T>
void MaxHeap<T>::filterUp(int index) {
    T value = heap[index];
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[parentIndex] < value) {
            heap[index] = heap[parentIndex];
            index = parentIndex;
        } else {
            break;
        }
    }
    heap[index] = value;
}

template <class T>
void MaxHeap<T>::insert(T value) {
    if (mSize == mOpacity) {
        cout << "The MaxHeap is full";
        return;
    }
    heap[mSize] = value;
    filterUp(mSize);
    mSize++;
    return;
}

template <class T>
void MaxHeap<T>::init(T *value, int length) {
    for (int i = 0; i < length; i++) {
        insert(value[i]);
    }
}

template <class T>
void MaxHeap<T>::print() {
    for (int i = 0; i < mSize; i++) {
        cout << heap[i] << " ";
    }

    cout << endl;
}


#endif
