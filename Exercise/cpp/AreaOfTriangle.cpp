// Tính diện tích tam giác khi biết độ dài 3 cạnh
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	float p = (float)(a + b + c) / 2;
	float s = p * (p - a) * (p - b) * (p - c);
	cout << fixed << setprecision(2) << sqrt(s);
	return 0;
}