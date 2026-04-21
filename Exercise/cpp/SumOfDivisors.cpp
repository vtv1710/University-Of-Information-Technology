#include <iostream>
using namespace std;

long long sumOfDivisors(int n) 
{
    long long sum = 0;
    for (int i = 1; i <= n / 2; ++i) 
    {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() 
{
    int n;
    cin >> n;
    if (n > 1 || n < 1000000000)
    {
        cout << sumOfDivisors(n) << endl;
    }
    return 0;
}
