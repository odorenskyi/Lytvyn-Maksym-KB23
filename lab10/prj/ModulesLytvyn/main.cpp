#include <iostream>
#include <clocale>
#include <ctime>
#include <cmath>
#include <limits>
#include <string>
#include <fstream>
#include <bitset>
#include <codecvt>
#include "ModulLytvyn.h"

using namespace std;

void SoftwareDeveloper()

void s_calculation(char choice);
{
    system("chcp 1251");
    system("cls");

    setlocale(LC_ALL, "ukr");
    cout << "\n ------------------------------------------------\n"
         << "  | Maksym Lytvyn, CUNTU, opd@kntu.kr.ua |"
         << "  | Максим Литвин, ЦНТУ, opd@kntu.kr.ua |  "
         << "\n   ----------- © All Rights Reserved ---------------\n\n\n\n";
}

using namespace std;

wstring characters = L".,!?:;)\" (₴ʼ'№%*_-+=\\/0123456789абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";

float s_calculation(int x, int y, int z) {
	return (1.0/2.0)*pow(fabs(2*z-pow(x,2))/sin(x),3)/sqrt(1+fabs(cos(x))+2*3.14*y);;
}

Deposit getPayment(float value, int months) {
	Deposit deposit;
	if (months == 6 || months == 12) {
		float interest;
		deposit.totalInterest = months == 12 ? 13 : 11/(float)2;
		interest = deposit.totalInterest / 100 / months;
		deposit.monthlyInterestPaid = round(value*interest*100)/100;
	} else {
		deposit.totalInterest = -1;
		deposit.monthlyInterestPaid = -1;
	}
	return deposit;
}

Size getSize(int slovakSize) {
	Size size;
	if (slovakSize >= 6 && slovakSize <= 10) {
		size.french = slovakSize - 4;
		switch (slovakSize)
		{
			case 6:
				size.international = "S";
				break;
			case 7:
				size.international = "M";
				break;
			case 8:
				size.international = "L";
				break;
			case 9:
				size.international = "XL";
				break;
			case 10:
				size.international = "XXL";
				break;
			default:
				size.international = "Error";
		}
	} else {
		size.french = -1;
		size.international = "Error";
	}
	return size;
}

int t9_3(int number) {
	unsigned int count = 0;
	if (number > 0 || number <= 7483650) {
		bool set = number & 1;
		while (number) {
			count += (number & 1) == set;
			number >>= 1;
		}
	} else {
		return -1;
	}
	return count;
}

bool validateCharacter(wchar_t character) {
	for (int i = 0; i < characters.length(); i++)
		if (character == characters.at(i))
			return true;
	return false;
}

int t10_1(string inputFile, string outputFile) {
	wstring line;
	wstring words[4] = {L"програма", L"модуль", L"студент", L"програміст"};
	bool found = false;
	int number = 0;
	wifstream indata;
	indata.open(inputFile);
	ofstream outdata;
	outdata.open(outputFile);

	if (!indata || !outdata)
		return 1;

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		number += line.length();

		for (int i = 0; i < line.length(); i++) {
			line[i] = towlower(line[i]);
			if (!validateCharacter(line[i]))
				return 2;
		}

		if (!found) {
			for (int i = 0; i < 4; i++) {
				int index = line.find(words[i]);
				if (index != wstring::npos && line.length()-words[i].length()-index == 0) { // слово у кінці
					found = true;
					goto out_found;
				}

				for (int j = 0; j < 9; j++) { // крапка, кома, знак оклику, знак питання, двокрапка, крапка з комою, закриваюча дужка, лапки, пробіл
					wstring wordToFind = words[i] + characters.at(j);
					if (line.find(wordToFind) != wstring::npos) {
						found = true;
						goto out_found;
					}
				}
			}
		}
		out_found: continue;
	}

	outdata << "Розробник: Гончарук Олександр" << endl << "Установа/організація: Центральноукраїнський національний технічний університет" << endl << "Місто: Кропивницький" << endl << "Країна: Україна" << endl << "Рік розробки: 2023" << endl << endl;

	outdata << "Кількість символів у файлі: " << number << endl;

	outdata << "У вхідному файлі " << ((found) ? "наявні" : "відсутні") << " слова \"Україна\", \"університет\", \"блокнот\""." << endl;

	return 0;
}

int t10_2(string file) {
	wchar_t character;
	time_t rawtime;
	time(&rawtime);
	int number = 0;

	wifstream indata;
	indata.open(file);
	ofstream outdata;
	outdata.open(file, ios_base::app);

	if (!indata || !outdata)
		return 1;

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (indata >> character) {
		if (!validateCharacter(towlower(character)))
			return 2;
		for (int i = 0; i < 10; i++)
			if (character == characters[i + 22]) // 0-9
				number += 1;
	}

	outdata << endl << "Кількість цифр у файлі: " << number << endl;
	outdata << "Дата й час дозапису: " << ctime(&rawtime);
	return 0;
}

int t10_3(string file, int x, int y, int z, int b) {
	wchar_t character;
	time_t rawtime;
	time(&rawtime);
	int number = 0;

	ofstream data;
	data.open(file, ios_base::app);

	if (!data)
		return 1;

	data << endl << "s = " << s_calculation(x, y, z) << endl;
	if (b > 0) {
		string binary = bitset<numeric_limits<int>::digits>(b).to_string();
		binary.erase(0, binary.find_first_not_of('0'));
		data << "b у двійковому коді: " << binary << endl;
	}
	else
		data << "b — не натуральне число" << endl;

	return 0;
}
