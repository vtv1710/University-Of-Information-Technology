#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double roundToNearest(double a, int n) 
{
    return round(a * n) / n;
}

int main() {
    double a;
    int n;

    cin >> a >> n;

    double result = roundToNearest(a, n);

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}
