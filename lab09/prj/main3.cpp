#include <iostream>

void SoftwareDeveloper(){
    setlocale(LC_ALL, "ukr");
    std::cout << "\n -------------------------------------\n"
    << "| Lytvyn Maksym, CUNTU, opd@kntu.kr.ua |\n" << "| Литвин Максим, ЦНТУ, opd@kntu.kr.ua |\n" << "\n ------ (c) All Rights Reserved ------\n\n";
}

int countBits(int n) {
    int countZeroes = 0;
    int countOnes = 0;

    while (n) {
        if (n & 1) {
            countOnes++;
        } else {
            countZeroes++;
        }
        n >>= 1;
    }

    return n ? countZeroes : countOnes;
}

int main() {
    SoftwareDeveloper();

    int N;
    std::cout << "Введіть натуральне число N від 0 до 190550: ";
    std::cin >> N;

    if (N < 0 || N > 190550) {
        std::cout << "Некоректне значення N.\n";
        return 1;
    }

    int result = countBits(N);
    std::cout << "Результат: " << result << "\n";

    return 0;
}
