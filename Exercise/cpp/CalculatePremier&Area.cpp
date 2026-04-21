#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int squareedge;
	float premier;
	float area;
	cout << "Input a square edge: ";
	cin >> squareedge;
	premier = squareedge * 4;
	area = squareedge * squareedge;
	cout << fixed << setprecision(2) << "Premier = " << premier << endl << "Area = " << area;
}
