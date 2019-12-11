//
// Created by Luzh on 2019/12/9.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

#include <iostream>

template <class T>
class MergeSort {
public:
    MergeSort();
    ~MergeSort();
    void init(T *arr, int len);
    void sort();
    void print();

private:
    T *array;
    int mLen;
    void sort(int start, int end, T *temp);
    void merge(int start, int middle, int end, T *temp);
};

template <class T>
MergeSort<T>::MergeSort() {

}

template <class T>
MergeSort<T>::~MergeSort() {
    delete []array;
}

template <class T>
void MergeSort<T>::init(T *arr, int len) {
    array = new T[len];
    mLen = len;
    for (int i = 0; i < len; ++ i) {
        array[i] = arr[i];
    }
}

template <class T>
void MergeSort<T>::sort() {
    T *temp = new T[mLen];
    sort(0, mLen, temp);
}

template <class T>
void MergeSort<T>::sort(int start, int end, T *temp) {
    if (start < end) {
        int mid = (start + end) / 2;
        sort(start, mid, temp);
        sort(mid + 1, end, temp);
        merge(start, mid, end, temp);
    }
}

template <class T>
void MergeSort<T>::merge(int start, int middle, int end, T *temp) {
    int i = start;
    int j = middle + 1;
    int k = 0;
    while (i <= middle && j < end) {
        if (array[i] < array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    while (i <= middle) {
        temp[k++] = array[i++];
    }
    while (j <= end) {
        temp[k++] = array[j++];
    }
    for (int i = 0; i < k; i++) {
        array[start + i] = temp[i];
    }
}

template <class T>
void MergeSort<T>::print() {
    for (int i = 0; i < mLen; ++ i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

#endif //MERGESORT_MERGESORT_H
