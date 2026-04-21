#include <iostream>
using namespace std;

int main()
{
	float Farenheit;
	float Celsius;
	float Kelvin;
	cout << "Input a Farenheit (F): ";
	cin >> Farenheit;
	Celsius = (Farenheit - 32) / 1.8;
	Kelvin = Celsius + 273.15;
	cout << "Celsius = " << Celsius << endl << "Kelvin = " << Kelvin;
}
