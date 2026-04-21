#include <iostream>
using namespace std;

int main() {
    double n; cin >> n;
    double ans = 0;
    if (n <= 5) ans = (0.05 * n);
    else if (n <= 10 && n > 5) ans = (0.1 * n) - 0.25;
    else if (n <= 18 && n > 10) ans = (0.15 * n) - 0.75;
    else if (n <= 32 && n > 18) ans = (0.2 * n) - 1.65;
    else if (n <= 52 && n > 32) ans = (0.25 * n) - 3.25;
    else if (n <= 80 && n > 52) ans = (0.3 * n) - 5.85;
    else ans = (0.35 * n) - 9.85;
    cout << ans;
    return 0;
}