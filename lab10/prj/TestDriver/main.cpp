#include <iostream>
#include <locale>
#include <fstream>
#include <codecvt>
#include <string>
#include "ModulLytvyn.h"

using namespace std;

string input = "input.txt";
string output = "output.txt";

bool createInput(wstring content) {
	wofstream data;
	data.open(input);

	data.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	if (!data) {
		cout << "������� ������ ������� �����." << endl;
		return false;
	}

	data << content << endl;

	return true;
}

bool test1_1() {
	wstring line;
	const wstring lines[3] = {L"���������: �������� ���������", L"��������/�����������: �������������������� ������������ ��������� �����������", L"г� ��������: 2023"};
	bool linesFound[3] = {false, false, false};
	int currentLine = 0;
	if(!createInput(L"����"))
		return false;

	t10_1(input, output);

	wifstream indata;
	indata.open(output);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		if (line.find(lines[currentLine]) != wstring::npos) {
			linesFound[currentLine] = true;
			currentLine++;
		}
		if (linesFound[0] && linesFound[1] && linesFound[2])
			return true;
	}
	return false;
}

bool test1(wstring data, bool wordPresent) {
	wstring line;

	if(!createInput(data))
		return false;

	t10_1(input, output);

	wifstream indata;
	indata.open(output);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		if ((wordPresent && line.find(L"������") != wstring::npos) || (!wordPresent && line.find(L"�������") != wstring::npos))
			return true;
	}

	return false;
}

bool test2_1() {
	wstring line;
	if(!createInput(L"����"))
		return false;

	t10_2(input);

	wifstream indata;
	indata.open(input);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		if (line.find(L"���� � ��� ��������: ") != wstring::npos)
			return true;
	}

	return false;
}

bool test2(wstring data, int digits) {
	wstring line;
	if(!createInput(data))
		return false;

	t10_2(input);

	wifstream indata;
	indata.open(input);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		if (line.find(L"ʳ������ ���� � ����: " + digits) != wstring::npos)
			return true;
	}

	return false;
}

bool test3(int x, int y, int z, int b, wstring s, wstring bin) {
	wstring line;
	bool firstValid = false;
	t10_3(output, x, y, z, b);

	wifstream indata;
	indata.open(output);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		if (!firstValid && (line.find(L"s = " + s) != wstring::npos))
			firstValid = true;
		else if (firstValid && (line.find(L"b � ��������� ���: " + bin) != wstring::npos))
			return true;
	}

	return false;
}

int main() {
	const wstring data1_1[] = {L"�����������", L"������������", L"������", L"������"};
	const bool wordPresent[] = {true, false, true, false};

	const wstring data2_1[] = {L"�������", L"0123456789", L"12", L"00000"};
	const int digits[] = {0, 10, 2, 5};

	const int x[] = {7, 2, 9, 0, 7};
	const int y[] = {2, 45, 0, 0, 5};
	const int z[] = {1, 6, 1, 0, 4};
	const int b[] = {1, 3, 8, 100, 127};
	const wstring s[] = {L"7.84054", L"268.187", L"3.84147", L"1", L"35775.4"};
	const wstring bin[] = {L"1", L"11", L"1000", L"1100100", L"1111111"};


	setlocale(LC_ALL, "");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			bool value = false;
			wstring description;
			if (i < 2 && j == 0) {
                description = L"��������� �����������";
				if (i == 0)
					value = test1_1();
				else if (i == 1)
					value = test2_1();
			}
			else if (i == 0) {
				value = test1(data1_1[j-1], wordPresent[j-1]);
                description = L"������ ����: " + data1_1[j-1] + L", ���������� ���������: ����� " + (wordPresent[j-1] ? L"������" : L"�������");
			}
			else if (i == 1) {
				value = test2(data2_1[j-1], digits[j-1]);
				string tmpstr = to_string(digits[j-1]);
				wstring wstr(tmpstr.begin(), tmpstr.end());
				description = L"������ ����: " + data2_1[j-1] + L", ���������� ���������: ������� �����: " + wstr;
			}
			else if (i == 2) {
				value = test3(x[j], y[j], z[j], b[j], s[j], bin[j]);
                string xtmpstr = to_string(digits[j-1]);
				wstring xwstr(xtmpstr.begin(), xtmpstr.end());
                string ytmpstr = to_string(digits[j-1]);
				wstring ywstr(ytmpstr.begin(), ytmpstr.end());
                string ztmpstr = to_string(digits[j-1]);
				wstring zwstr(ztmpstr.begin(), ztmpstr.end());
                string btmpstr = to_string(digits[j-1]);
				wstring bwstr(btmpstr.begin(), btmpstr.end());
				description = L"������ ����: x = " + xwstr + L", y = " + ywstr + L", z = " + zwstr + L", b = " + bwstr + L", ���������� ���������: s = " + s[j] + L", b � ��������� ���: " + bin[j];
			}
			wcout << "Test " << i + 1 << "." << j + 1 << " (" << description << ") " << (value ? "passed" : "failed") << endl;
		}

	}

	return 0;
}