#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float x = pow(b,2) - (4 * a * c);
    if (x < 0)
    {
        cout << "PTVN" << endl;
    }
    if (x == 0)
    {
        cout << "PT co nghiem kep: x1 = x2 = " << -b / (2 * a) << endl;
    }
    if (x > 0)
    {
        cout << "PT co hai nghiem phan biet: " << endl;
        cout << "x1 = " << (-b + sqrt(x)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(x)) / (2 * a) << endl;
    }
    return 0;
}