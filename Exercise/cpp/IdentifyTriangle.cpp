#include <iostream>
#include <cmath>    
#include <iomanip>  

using namespace std;

int main()
{
    float a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a + b > c && a + c > b && b + c > a)
    {
        if (a == b && b == c)
        {
            float p = (pow(a, 2)) * (sqrt(3) / 4);
            cout << "Tam giac deu, dien tich = " << fixed << setprecision(2) << p << endl;
        }
        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        {
            float q = 0.5 * (a * b);
            cout << "Tam giac vuong, dien tich = " << fixed << setprecision(2) << q << endl;
        }
        else if (a == b || b == c || a == c)
        {
            float o = 0.5 * pow(a, 2);
            cout << "Tam giac can, dien tich= " << fixed << setprecision(2) << o << endl;
        }
        else
        {
            float p = (a + b + c) / 2;
            float s = p * (p - a) * (p - b) * (p - c);
            cout << "Tam giac thuong, dien tich = " << fixed << setprecision(2) << sqrt(s) << endl;
        }
    }
    else
    {
        cout << "Khong phai tam giac" << endl;
    }
    return 0;
}
