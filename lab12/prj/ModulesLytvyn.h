#ifndef MODULESLYTVYN_H_INCLUDED
#define MODULESLYTVYN_H_INCLUDED

#include <fstream>
#include <string>
#include <iostream>

void HelloWorld() {
    std::cout << "Hello world";
}

class ClassLab12_Lytvyn {
public:
    ClassLab12_Lytvyn(const float length = 1, const float width = 1)
        : Length(length), Width(width) {}

    float getArea() const;
    float getLength() const;
    float getWidth() const;
    void setLength(float length);
    void setWidth(float width);

private:
    float Length;
    float Width;
};

float ClassLab12_Lytvyn::getArea() const {
    return Length * Width;
}

float ClassLab12_Lytvyn::getLength() const {
    return Length;
}

float ClassLab12_Lytvyn::getWidth() const {
    return Width;
}

void ClassLab12_Lytvyn::setLength(float length) {
    Length = length;
}

void ClassLab12_Lytvyn::setWidth(float width) {
    Width = width;
}

bool checkFileInFolder() {
    std::string file = __FILE__;
    size_t checking = file.find("\\prj");
    if (checking == std::string::npos) {
        std::ofstream fileResult("../../TestSuite/TestResult.txt");
        fileResult << "Встановлені вимоги порядку виконання лабораторної роботи порушено!\n";
        for (int i = 0; i < 100; i++) {
            std::cout << "\a";
        }
        fileResult.close();
        return false;
    }
    return true;
}

std::string writeResultToFile(const ClassLab12_Lytvyn& book, int counter) {
    return "Test Suite No" + std::to_string(counter)
        + "\nLength = " + std::to_string(book.getLength())
        + "\tWidth = " + std::to_string(book.getWidth())
        + "\nArea = " + std::to_string(book.getArea()) + "\n";
}

#endif
