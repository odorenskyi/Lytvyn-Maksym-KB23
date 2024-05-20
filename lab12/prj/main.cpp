#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ModulesLytvyn.h"

using namespace std;

int main() {
    string line;
    if (!checkFileInFolder()) {
        return 0;
    }

    ClassLab12_Lytvyn book;
    ifstream Tests_File("../../TestSuite/Tests.txt");
    ofstream TestResult_File("../../TestSuite/TestResult.txt");

    if (Tests_File.is_open() && TestResult_File.is_open()) {
        int counter = 1;
        float number;
        while (getline(Tests_File, line)) {
            istringstream iss(line);
            vector<float> arrNumbers;
            while (iss >> number) {
                arrNumbers.push_back(number);
            }
            book.setLength(arrNumbers[0]);
            book.setWidth(arrNumbers[1]);
            TestResult_File << writeResultToFile(book, counter);
            counter++;
        }
    }

    Tests_File.close();
    TestResult_File.close();
    return 0;
}
