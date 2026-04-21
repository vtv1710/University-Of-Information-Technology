#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float toan, ly, hoa;
    cin >> toan;
    cin >> ly;
    cin >> hoa;
    float dtb = (float)(toan + ly + hoa) / 3;
    cout << "DTB = " << fixed << setprecision(2) << dtb << endl;
    if (dtb >= 9 && dtb <= 10)
    {
        cout << "Loai: XUAT SAC" << endl;
    }
    else if (dtb >= 8)
    {
        cout << "Loai: GIOI" << endl;
    }
    else if (dtb >= 7)
    {
        cout << "Loai: KHA" << endl;
    }
    else if (dtb >= 6)
    {
        cout << "Loai: TB KHA" << endl;
    }
    else if (dtb >= 5)
    {
        cout << "Loai: TB" << endl;
    }
    else if (dtb >= 4)
    {
        cout << "Loai: YEU" << endl;
    }
    else
    {
        cout << "Loai: KEM" << endl;
    }

    return 0;
}
