#pragma once
#include <stdexcept>
#include <iostream>

template <typename T, int MaxSize>
class Heap {
private:
    T arr[MaxSize];
    int currentSize;
    int parent(int idx) { return (idx - 1) / 2; }
    int leftChild(int idx) { return 2 * idx + 1; }
    int rightChild(int idx) { return 2 * idx + 2; }
    void siftUp(int idx) {
        while (idx > 0 && arr[idx] < arr[parent(idx)]) {
            T temp = arr[idx];
            arr[idx] = arr[parent(idx)];
            arr[parent(idx)] = temp;
            idx = parent(idx);
        }
    }

    void siftDown(int idx) {
        int minIndex = idx;
        int l = leftChild(idx);
        int r = rightChild(idx);
        if (l < currentSize && arr[l] < arr[minIndex]) {
            minIndex = l;
        }

        if (r < currentSize && arr[r] < arr[minIndex]) {
            minIndex = r;
        }

        if (idx != minIndex) {
            T temp = arr[idx];
            arr[idx] = arr[minIndex];
            arr[minIndex] = temp;

            siftDown(minIndex);
        }
    }

public:
    Heap() {
        currentSize = 0;
    }

    void insert(const T& value) {
        if (currentSize >= MaxSize) {
            throw std::overflow_error("Heap is full!"); 
        }

        arr[currentSize] = value;
        siftUp(currentSize);

        currentSize++;
    }

    T extractMin() {
        if (currentSize <= 0) {
            throw std::underflow_error("Heap is empty!");
        }

        T minVal = arr[0];
        arr[0] = arr[currentSize - 1];
        currentSize--;
        siftDown(0);

        return minVal;
    }

    int count() const {
        return currentSize;
    }
};
