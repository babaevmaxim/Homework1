#include <gtest/gtest.h>
#include <string>
#include "Heap.h"

using namespace std;

TEST(HeapTest, IntegersMinHeap) {
    Heap<int, 10> h;
    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    EXPECT_EQ(h.extractMin(), 2);
    EXPECT_EQ(h.extractMin(), 5);
    EXPECT_EQ(h.extractMin(), 10);
    EXPECT_EQ(h.extractMin(), 20);
}

TEST(HeapTest, StringsMinHeap) {
    Heap<string, 5> h;
    h.insert("banana");
    h.insert("apple");
    h.insert("cherry");

    EXPECT_EQ(h.extractMin(), "apple");
    EXPECT_EQ(h.extractMin(), "banana");
    EXPECT_EQ(h.extractMin(), "cherry");
}

TEST(HeapTest, OverflowException) {
    Heap<int, 2> h;
    h.insert(1);
    h.insert(2);
    EXPECT_THROW(h.insert(3), std::overflow_error);
}

TEST(HeapTest, UnderflowException) {
    Heap<int, 5> h;
    EXPECT_THROW(h.extractMin(), std::underflow_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

