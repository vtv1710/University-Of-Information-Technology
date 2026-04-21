#include <iostream>
using namespace std;

void NhapMang(float a[][150], int& n, int& m) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
        }
    }
}

void solve(float a[][150], float b[][150], int n, int m) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int n, m; cin >> n >> m;
    float a[150][150], b[150][150];
    NhapMang(a, n, m);
    int l, k; cin >> l >> k;
    NhapMang(b, l, k);
    solve(a, b, n, m);
    return 0;
}