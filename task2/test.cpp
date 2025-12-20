#include <gtest/gtest.h>
#include "SparseVector.h"

TEST(SparseVectorTest, SetAndGet) {
    SparseVector v;
    v.setElem(5, 100);
    v.setElem(1, 10);
    EXPECT_EQ(v.getElem(5), 100);
    EXPECT_EQ(v.getElem(1), 10);
    EXPECT_EQ(v.getElem(2), 0);
}

TEST(SparseVectorTest, RemoveBySettingZero) {
    SparseVector v;
    v.setElem(3, 50);
    EXPECT_EQ(v.getElem(3), 50);
    v.setElem(3, 0);
    EXPECT_EQ(v.getElem(3), 0);
}

TEST(SparseVectorTest, Addition) {
    SparseVector v1, v2;
    v1.setElem(1, 10);
    v2.setElem(1, 20);
    v2.setElem(5, 5);
    SparseVector v3 = v1 + v2;
    EXPECT_EQ(v3.getElem(1), 30);
    EXPECT_EQ(v3.getElem(5), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
