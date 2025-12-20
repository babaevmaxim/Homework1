#pragma once

struct Node {
    int index;
    int value;
    Node* next;
};

class SparseVector {
private:
    Node* head; 

    void setNonzeroElem(int index, int value);
    void removeElem(int index);
    void addSubVector(const SparseVector& sv, bool add);

public:
    SparseVector(); 
    SparseVector(const SparseVector& other);
    ~SparseVector();
    SparseVector& operator=(const SparseVector& other);
    int getElem(int index) const;
    void setElem(int index, int value);
    bool operator==(const SparseVector& other) const;
    bool operator!=(const SparseVector& other) const;
    SparseVector& operator+=(const SparseVector& other);
    SparseVector& operator-=(const SparseVector& other);
};

const SparseVector operator+(const SparseVector& left, const SparseVector& right);
const SparseVector operator-(const SparseVector& left, const SparseVector& right);
