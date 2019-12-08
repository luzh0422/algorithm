#ifndef MAX_HEAP
#define MAX_HEAP

#include <iostream>
using namespace std;

template <class T>
class MaxHeap {
private:
    void filterUp(int index);
    void filterDown(int index);
    T *heap;
    int mOpacity;
    int mSize;

public:
    MaxHeap(int capcity = 20);
    ~MaxHeap();
    void init(T value[], int length);
    void insert(T value);
    void print();
    int pop();
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
    /**
     * 递归着往树的上层去寻找元素；
     */
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
void MaxHeap<T>::filterDown(int index) {
    T value = heap[index];
    while (index <= mSize) {
        int lChildIndex = index * 2 + 1;
        int rChildIndex = index * 2 + 2;
        if ((lChildIndex < mSize && rChildIndex < mSize && heap[lChildIndex] > heap[rChildIndex] || lChildIndex < mSize && rChildIndex == mSize) && heap[lChildIndex] > value) {
            heap[index] = heap[lChildIndex];
            index = lChildIndex;
        } else if (lChildIndex < mSize && rChildIndex < mSize && heap[lChildIndex] < heap[rChildIndex] && heap[rChildIndex] > value) {
            heap[index] = heap[rChildIndex];
            index = rChildIndex;
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

template <class T>
int MaxHeap<T>::pop() {
    int value = heap[0];
    heap[0] = heap[-- mSize];
    filterDown(0);
    return value;
}

#endif
