#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a;
	int b;
	int sum;
	int subtraction; //Phép trừ
	int multiplication; 
	float division;
	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;
	sum = a + b;
	subtraction = a - b;
	multiplication = a * b;
	division = (float)a / b;
	cout << a << " + " << b << " = " << sum << endl;
	cout << a << " - " << b << " = " << subtraction << endl;
	cout << a << " x " << b << " = " << multiplication << endl;
	cout << fixed << setprecision(2) << a << " : " << b << " = " << division;

}