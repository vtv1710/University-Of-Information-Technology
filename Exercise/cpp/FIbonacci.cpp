#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n > 2) return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int x;
    cin >> x;
    if (x < 1 || x > 30)
    {
        cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
    }
    else
    {
        cout << fibonacci(x) << endl;
    }
    return 0;
}
