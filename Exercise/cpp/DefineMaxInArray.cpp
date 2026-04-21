#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a[n + 1], max = 0, cnt = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        if (a[i] >= max) max = a[i];
    }
    for (int i = 0; i < n; i++) 
    {
        if (a[i] == max) cnt++;
    }
    cout << max << endl << cnt;
    return 0;
}