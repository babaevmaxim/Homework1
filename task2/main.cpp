#include <iostream>
#include "SparseVector.h"

int main() {
    SparseVector v1;
    v1.setElem(1, 10);
    v1.setElem(5, 50);

    SparseVector v2;
    v2.setElem(1, 5);
    v2.setElem(3, 30);
    SparseVector v3 = v1 + v2;

    std::cout << "v1[1] = " << v1.getElem(1) << " (ozhidalos 10)" << std::endl;
    std::cout << "v2[1] = " << v2.getElem(1) << " (ozhidalos 5)" << std::endl;
    std::cout << "v3[1] = " << v3.getElem(1) << " (ozhidalos 15)" << std::endl;
    std::cout << "v3[3] = " << v3.getElem(3) << " (ozhidalos 30)" << std::endl;
    std::cout << "v3[5] = " << v3.getElem(5) << " (ozhidalos 50)" << std::endl;
    v1.setElem(1, 0);
    std::cout << "v1[1] posle udaleniya = " << v1.getElem(1) << " (ozhidalos 0)" << std::endl;

    return 0;
}
