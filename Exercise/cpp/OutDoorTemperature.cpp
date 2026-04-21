#include <iostream>
using namespace std;

int main()
{
	int temperature;
	cout << "What is the outdoor temperature?" << endl;
	cin >> temperature;
	cout << "What is your plan today? ";
	cout << endl;
	if (temperature <= 40)
	{
		if (temperature >= 33)
		{
			cout << "Good day for swimming" << endl;
		}
		else if (temperature >= 24)
		{
			cout << "Good day for golfing" << endl;
		}
		else if (temperature >= 10)
		{
			cout << "Good day to play tennis" << endl;
		}
		else
		{
			cout << "Go to bed" << endl;
		}
	}
	return 0;
		
}

