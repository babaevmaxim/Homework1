#include <iostream>
#include <string>
#include "Heap.h"

using namespace std;
int main() {
    cout << "=== Test 1: Integers (int) ===" << endl;
    try {
        Heap<int, 10> intHeap;
        intHeap.insert(10);
        intHeap.insert(5);
        intHeap.insert(20);
        intHeap.insert(2);
        cout << "Min: " << intHeap.extractMin() << " (Expected: 2)" << endl;
        cout << "Min: " << intHeap.extractMin() << " (Expected: 5)" << endl;
        cout << "Min: " << intHeap.extractMin() << " (Expected: 10)" << endl;
        cout << "Min: " << intHeap.extractMin() << " (Expected: 20)" << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n=== Test 2: Strings (std::string) ===" << endl;
    try {
        Heap<string, 5> stringHeap;
        stringHeap.insert("banana");
        stringHeap.insert("apple");
        stringHeap.insert("cherry");
        cout << "Min: " << stringHeap.extractMin() << " (Expected: apple)" << endl;
        cout << "Min: " << stringHeap.extractMin() << " (Expected: banana)" << endl;
        cout << "Min: " << stringHeap.extractMin() << " (Expected: cherry)" << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n=== Test 3: Exceptions ===" << endl;
    try {
        Heap<int, 2> smallHeap;
        smallHeap.insert(1);
        smallHeap.insert(2);
        cout << "Trying to insert 3rd element into Heap of size 2..." << endl;
        smallHeap.insert(3);
    } catch (const overflow_error& e) {
        cout << "Caught expected overflow: " << e.what() << endl;
    }

    try {
        Heap<int, 5> emptyHeap;
        cout << "Trying to extract from empty heap..." << endl;
        emptyHeap.extractMin();
    } catch (const underflow_error& e) {
        cout << "Caught expected underflow: " << e.what() << endl;
    }

    return 0;
}
