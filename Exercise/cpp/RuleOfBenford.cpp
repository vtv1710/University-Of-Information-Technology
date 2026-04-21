#include <iostream>
using namespace std;
#define MAX 100

void Nhapmang(int a[], int n) 
{
	for (int i = 1; i <= n; i++) cin >> a[i];
}

int count1 = 0; int count4 = 0;
bool isBenford(int a[], int n) 
{
	for (int i = 1; i <= n; i++) 
	{
		while (a[i] >= 10) 
		{
			a[i] /= 10;
		}
		if (a[i] == 1) count1++;
		if (a[i] == 4) count4++;
	}
	if (count1 == 3 && count4 == 1) return true;
	else return false;
	return true;
}

int main()
{
	int a[MAX], n = 10;
	Nhapmang(a, n);
	if (isBenford(a, n) == true)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	return 0;
}
