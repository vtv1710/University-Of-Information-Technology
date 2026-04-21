#include <iostream>
using namespace std;

int main() {
    double a, b, c; cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    double sd = sqrt(delta);
    if (delta == 0) {
        cout.precision(3);
        cout << "x = " << -b / (2 * a);
    }
    else if (delta > 0) {
        cout.precision(3);
        cout << "x1 = " << (-b + sd) / (2 * a) << ", x2 = " << (-b - sd) / (2 * a);
    }
    else {
        cout.precision(3);
        double vn = sqrt(abs(delta));
        if (-b / (2 * a) == 0) cout << "x1 = " << vn / (2 * a) << "i, x2 = -" << vn / (2 * a) << "i";
        else cout << "x1 = " << -b / (2 * a) << " + " << vn / (2 * a) << "i, x2 = " << -b / (2 * a) << " - " << vn / (2 * a) << "i";
    }
    return 0;
}