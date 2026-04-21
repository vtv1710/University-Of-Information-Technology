#include <iostream>
using namespace std;

int main()
{
	int number;
	float result;
	cout << "Input a number (PSI): ";
	cin >> number;
	result = number * 0.453592 / (2.54 * 2.54);
	cout << number << " PSI" << " = " << result << " Kgcm2 ";
} 