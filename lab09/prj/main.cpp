#include <iostream>
#include <iomanip>

void SoftwareDeveloper(){
    setlocale(LC_ALL, "ukr");
    std::cout << "\n -------------------------------------\n"
    << "| Lytvyn Maksym, CUNTU, opd@kntu.kr.ua |\n" << "| Литвин Максим, ЦНТУ, opd@kntu.kr.ua |\n" << "\n ------ (c) All Rights Reserved ------\n\n";
}

void calculateDiscount(double purchaseAmount) {
    double discountRate = 0.0;
    double discountAmount = 0.0;

    if (purchaseAmount <= 100) {
        discountRate = 0.05;
    } else if (purchaseAmount <= 200) {
        discountRate = 0.07;
    } else if (purchaseAmount <= 300) {
        discountRate = 0.09;
    } else if (purchaseAmount <= 400) {
        discountRate = 0.12;
    } else if (purchaseAmount <= 500) {
        discountRate = 0.15;
    } else if (purchaseAmount <= 1000) {
        discountRate = 0.20;
    } else {
        discountRate = 0.75;
    }

    discountAmount = purchaseAmount * discountRate;
    double totalAmount = purchaseAmount - discountAmount;

    std::cout << "Знижка: " << std::fixed << std::setprecision(2) << (discountRate * 100) << "% (" << discountAmount << " грн.)" << std::endl;
    std::cout << "Сума до сплати з урахуванням знижки: " << totalAmount << " грн." << std::endl;
}

int main() {
    SoftwareDeveloper();

    double purchaseAmount;
    std::cout << "Введіть суму покупки: ";
    std::cin >> purchaseAmount;

    calculateDiscount(purchaseAmount);

    return 0;
}
