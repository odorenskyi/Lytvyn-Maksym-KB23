#include <iostream>
#include <map>
#include <string>

void SoftwareDeveloper() {
    setlocale(LC_ALL, "ukr");
    std::cout << "\n -------------------------------------\n"
    << "| Lytvyn Maksym, CUNTU, opd@kntu.kr.ua |\n" << "| Литвин Максим, ЦНТУ, opd@kntu.kr.ua |\n" << "\n ------ (c) All Rights Reserved ------\n\n";
}

class SizeConverter {
public:
    virtual std::string getSize(int ukraineSize) const = 0;
};

class InternationalSizeConverter : public SizeConverter {
public:
    std::string getSize(int ukraineSize) const override {
        if (ukraineSize == 0) return "S";
        if (ukraineSize == 1) return "M";
        if (ukraineSize == 2) return "L";
        if (ukraineSize == 3) return "XL";
        if (ukraineSize == 4) return "XXL";
        if (ukraineSize == 5) return "XXXL";
        return "Розмір не визначено";
    }
};

class CzechSizeConverter : public SizeConverter {
public:
    std::string getSize(int ukraineSize) const override {
        if (ukraineSize == 0) return "6";
        if (ukraineSize == 1) return "7";
        if (ukraineSize == 2) return "8";
        if (ukraineSize == 3) return "9";
        if (ukraineSize == 4) return "10";
        return "Розмір не визначено";
    }
};

class UKSizeConverter : public SizeConverter {
public:
    std::string getSize(int ukraineSize) const override {
        if (ukraineSize == 0) return "34";
        if (ukraineSize == 1) return "36";
        if (ukraineSize == 2) return "38";
        if (ukraineSize == 3) return "40";
        if (ukraineSize == 4) return "42";
        if (ukraineSize == 5) return "44";
        return "Розмір не визначено";
    }
};

class GermanySizeConverter : public SizeConverter {
public:
    std::string getSize(int ukraineSize) const override {
        if (ukraineSize == 0) return "4";
        if (ukraineSize == 1) return "5";
        if (ukraineSize == 2) return "7";
        if (ukraineSize == 3) return "8";
        return "Розмір не визначено";
    }
};

class FranceSizeConverter : public SizeConverter {
public:
    std::string getSize(int ukraineSize) const override {
        if (ukraineSize == 0) return "2";
        if (ukraineSize == 1) return "3";
        if (ukraineSize == 2) return "4";
        if (ukraineSize == 3) return "5";
        if (ukraineSize == 4) return "6";
        return "Розмір не визначено";
    }
};

int main() {
    SoftwareDeveloper();

    std::cout << "Введіть розмір чоловічої спідні за українською системою: ";
    int ukraineSize;
    std::cin >> ukraineSize;

    InternationalSizeConverter internationalConverter;
    CzechSizeConverter czechConverter;
    UKSizeConverter ukConverter;
    GermanySizeConverter germanyConverter;
    FranceSizeConverter franceConverter;

    std::cout << "Міжнародний: " << internationalConverter.getSize(ukraineSize) << std::endl;
    std::cout << "Чехія, Словаччина: " << czechConverter.getSize(ukraineSize) << std::endl;
    std::cout << "Великобританія: " << ukConverter.getSize(ukraineSize) << std::endl;
    std::cout << "Німеччина: " << germanyConverter.getSize(ukraineSize) << std::endl;
    std::cout << "Франція: " << franceConverter.getSize(ukraineSize) << std::endl;

    return 0;
}
