#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1], max = 0, max2 = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        if (a[i] >= max) max = a[i];
    }
    for (int i = 0; i < n; i++) 
    {
        if (a[i] < max && a[i] > max2) max2 = a[i];
    }
    if (max2 == 0) cout << 0;
    else cout << max2;
    return 0;
}