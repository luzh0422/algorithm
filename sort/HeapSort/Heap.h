//
// Created by Luzh on 2019/12/8.
//

#ifndef HEAPSORT_HEAP_H
#define HEAPSORT_HEAP_H

#include <iostream>

template <class T>
class Heap {
public:
    Heap(int capcity = 20);
    ~Heap();
    void init(T value[], int length);
    void insert(T value);
    void print();
    T* sort();
    T pop();

private:
    int mCapcity;
    int mSize;
    T *heap;
    void filterDown(int index);
    void filterUp(int index);
};

template <class T>
Heap<T>::Heap(int capcity) {
    mCapcity = capcity;
    mSize = 0;
    heap = new T[capcity];
}

template <class T>
Heap<T>::~Heap() {
    delete []heap;
}

template <class T>
void Heap<T>::init(T *value, int length) {
    for (int i = 0; i < length; ++ i) {
        insert(value[i]);
    }
}

template <class T>
void Heap<T>::insert(T value) {
    if (mSize == mCapcity) {
        std::cout << "The heap is full." << std::endl;
        return;
    }

    heap[mSize] = value;
    filterUp(mSize++);
}

template <class T>
void Heap<T>::filterUp(int index) {
    T value = heap[index];
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[parentIndex] > value) {
            heap[index] = heap[parentIndex];
            index = parentIndex;
        } else {
            break;
        }
    }
    heap[index] = value;
}

template <class T>
T Heap<T>::pop() {
    T value = heap[0];
    heap[0] = heap[--mSize];
    filterDown(0);
    return value;
}

template <class T>
void Heap<T>::filterDown(int index) {
    T value = heap[index];
    while(index < mSize) {
        int lChild = index * 2 + 1;
        int rChild = index * 2 + 2;
        if (rChild < mSize) {
            if (heap[lChild] < heap[rChild] && heap[lChild] < value) {
                heap[index] = heap[lChild];
                index = lChild;
            } else if (heap[lChild] > heap[rChild] && heap[rChild] < value) {
                heap[index] = heap[rChild];
                index = rChild;
            }
        } else if (lChild < mSize) {
            if (heap[lChild] < value) {
                heap[index] = heap[lChild];
                index = lChild;
            }
        }
    }

    heap[index] = value;
}

template <class T>
void Heap<T>::print() {
    for (int i = 0; i < mSize; ++ i) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
T* Heap<T>::sort() {
    T *a = new T[mSize];
    int i = 0;
    while(mSize > 0) {
        T value = pop();
        a[i] = value;
        i++;
    }
    return a;
}

#endif //HEAPSORT_HEAP_H
