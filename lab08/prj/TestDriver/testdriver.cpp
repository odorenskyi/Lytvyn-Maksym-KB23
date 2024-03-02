#include <iostream>
#include <cmath>

float s_calculation(float x, float y, float z) {
    return sqrt(abs(x - y)) + pow(z, 2);
}

void SoftwareDeveloper(){
    setlocale(LC_ALL, "ukr");
    std::cout << "\n -------------------------------------\n"
              << "| Lytvyn Maksym, CUNTU, opd@kntu.kr.ua |\n"
              << "| Литвин Максим, ЦНТУ, opd@kntu.kr.ua  |\n"
              << "\n ------ (c) All Rights Reserved ------\n\n";
}

#define ARRAY_SIZE 6

int main() {
    const float x[ARRAY_SIZE] = {2, 5, 4, 4, 4, 4};
    const float y[ARRAY_SIZE] = {3, 8, -2, 11, -4, 4};
    const float z[ARRAY_SIZE] = {1, 2, 5, 6, 9, 9};
    const float expectedResult[ARRAY_SIZE] = {1,1022,97,4354,1294,1293};

    SoftwareDeveloper();

    for (short int i = 0; i < ARRAY_SIZE; i++) {
        const float currentResult = round(s_calculation(x[i], y[i], z[i])*10000) / 10000;
        if (currentResult == expectedResult[i])
            std::cout << "Test #" << i+1 << " - PASSED\n";
        else
            std::cout << "Test #" << i+1 << " - FAILED\n";
    }
    return 0;
}
