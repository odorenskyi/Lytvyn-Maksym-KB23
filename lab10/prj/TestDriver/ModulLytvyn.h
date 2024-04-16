#ifndef MODULLYTVYN_H_INCLUDED
#define MODULLYTVYN_H_INCLUDED
#include <string>

void SoftwareDeveloper(void);

using std::string;

float s_calculation(int x, int y, int z);

typedef struct Deposit {
	float totalInterest;
	float monthlyInterestPaid;
} Deposit;

typedef struct Size {
	int french;
	string international;
} Size;

Deposit getPayment(float value, int months);

Size getSize(int slovakSize);

int t9_3(int number);

bool validateCharacter(wchar_t character);

int t10_1(string inputFile, string outputFile);

int t10_2(string file);

int t10_3(string file, int x, int y, int z, int b);

#endif // MODULLYTVYN_H_INCLUDED
