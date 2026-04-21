#include<iostream>
using namespace std;

int main() 
{
    int a[100], n, cnt = 0, x, k;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x >> k;
    for (int i = 0; i < k; i++) 
    {
        cout << a[i] << " ";
    }
    cout << x << " ";
    for (int i = k; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}