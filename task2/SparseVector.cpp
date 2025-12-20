#include "SparseVector.h"
#include <iostream>

SparseVector::SparseVector() {
    head = nullptr;
}


SparseVector::~SparseVector() {
    Node* cur = head;
    while (cur != nullptr) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}

SparseVector::SparseVector(const SparseVector& other) {
    if (other.head == nullptr) {
        head = nullptr;
    } else {
        head = new Node;
        head->index = other.head->index;
        head->value = other.head->value;
        head->next = nullptr;
        Node* myCur = head;
        Node* otherCur = other.head->next;
        while (otherCur != nullptr) {
            Node* newNode = new Node;
            newNode->index = otherCur->index;
            newNode->value = otherCur->value;
            newNode->next = nullptr;
            myCur->next = newNode;
            myCur = newNode;
            otherCur = otherCur->next;
        }
    }
}

SparseVector& SparseVector::operator=(const SparseVector& other) {
    if (this == &other) return *this;
    Node* cur = head;
    while (cur != nullptr) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = nullptr;
    if (other.head != nullptr) {
        head = new Node;
        head->index = other.head->index;
        head->value = other.head->value;
        head->next = nullptr;
        Node* myCur = head;
        Node* otherCur = other.head->next;

        while (otherCur != nullptr) {
            Node* newNode = new Node;
            newNode->index = otherCur->index;
            newNode->value = otherCur->value;
            newNode->next = nullptr;

            myCur->next = newNode;
            myCur = newNode;
            otherCur = otherCur->next;
        }
    }
    return *this; 
}

int SparseVector::getElem(int index) const {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->index == index) return cur->value;
        if (cur->index > index) return 0;
        cur = cur->next;
    }
    return 0;
}

void SparseVector::setElem(int index, int value) {
    if (value != 0) {
        setNonzeroElem(index, value);
    } else {
        removeElem(index);
    }
}
void SparseVector::removeElem(int index) {
    if (head == nullptr) return;

    if (head->index == index) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    Node* prev = head;
    Node* cur = head->next;
    while (cur != nullptr) {
        if (cur->index == index) {
            prev->next = cur->next;
            delete cur;
            return;
        }
        if (cur->index > index) return;
        prev = cur;
        cur = cur->next;
    }
}
void SparseVector::setNonzeroElem(int index, int value) {
    if (head == nullptr || index < head->index) {
        Node* newNode = new Node;
        newNode->index = index;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
        return;
    }
    if (head->index == index) {
        head->value = value;
        return;
    }
    Node* prev = head;
    Node* cur = head->next;
    while (cur != nullptr) {
        if (cur->index == index) {
            cur->value = value; 
            return;
        }
        if (cur->index > index) {
            Node* newNode = new Node;
            newNode->index = index;
            newNode->value = value;
            newNode->next = cur;
            prev->next = newNode;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    Node* newNode = new Node;
    newNode->index = index;
    newNode->value = value;
    newNode->next = nullptr;
    prev->next = newNode;
}

bool SparseVector::operator==(const SparseVector& other) const {
    Node* myCur = head;
    Node* otherCur = other.head;

    while (myCur != nullptr && otherCur != nullptr) {
        if (myCur->index != otherCur->index) return false;
        if (myCur->value != otherCur->value) return false;
        myCur = myCur->next;
        otherCur = otherCur->next;
    }
    if (myCur != nullptr || otherCur != nullptr) return false;

    return true;
}

bool SparseVector::operator!=(const SparseVector& other) const {
    return !(*this == other);
}
void SparseVector::addSubVector(const SparseVector& sv, bool add) {
    Node* cur = sv.head;
    while (cur != nullptr) {
        int myVal = getElem(cur->index);
        int otherVal = cur->value;
        int res;
        if (add) {
            res = myVal + otherVal;
        } else {
            res = myVal - otherVal;
        }
        setElem(cur->index, res);
        cur = cur->next;
    }
}
SparseVector& SparseVector::operator+=(const SparseVector& other) {
    addSubVector(other, true);
    return *this;
}

SparseVector& SparseVector::operator-=(const SparseVector& other) {
    addSubVector(other, false);
    return *this;
}

const SparseVector operator+(const SparseVector& left, const SparseVector& right) {
    SparseVector res(left);
    res += right; 
    return res;
}

const SparseVector operator-(const SparseVector& left, const SparseVector& right) {
    SparseVector res(left);
    res -= right;
    return res;
}
